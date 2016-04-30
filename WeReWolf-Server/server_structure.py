from socket import *
import struct
import thread
import json
import random

from game import *

class GameServer:
	def __init__ (self):
		random.seed()
		self.players = [""] * 25 # maximum players online 
		self.game = Game()
		self.playerNum = 0
		self.kpu_voted = 0
		self.kpu_data = {}
		self.day_chance = 1

	def resetDayChance(self):
		self.day_chance = 1

	def decreaseDayChance(self):
		self.day_chance -= 1

	def getDayChance(self):
		return self.day_chance

	def setKPUCount (self, i, value):
		self.kpu_data[i] = value

	def getKPUCount (self, i):
		return self.kpu_data[i]

	def resetKPUCount(self):
		self.kpu_data = {}		
		i = 0
		for player in self.players:
			self.kpu_data[i] = 0
			i += 1

	def getConsensusKPU (self):
		maxVote = 0
		selKPU = -1
		for kpu_id, votes in self.kpu_data.items():
			if (votes > maxVote):
				selKPU = kpu_id

		return selKPU

	def getKPUVoted (self):
		return self.kpu_voted

	def increaseKPUVoted (self):
		self.kpu_voted += 1

	def resetKPUVoted(self):
		self.kpu_voted = 0

	def getGame(self):
		return self.game

	def decreasePlayer(self):
		self.playerNum -= 1

	def getTotalPlayer(self):
		return self.playerNum

	def getPlayerList (self):
		return self.players

	def getPlayerByPID (self, pid):
		return self.players[pid]

	def getPlayerByUsername (self, username):
		for player in self.players:
			if ( player != "" ):
				if ( player.getName() == username ):
					return player.getID
		return -1

	def getTotalAliveWerewolf (self):
		i = 0
		for player in self.players:
			if ( player != "" ):
				if ( player.getRole() == 'werewolf' ):
					if ( player.isAlive() ):
						i += 1
		return i

	def getTotalAlivePlayer (self):
		i = 0
		for player in self.players:
			if ( player != "" ):
				if ( player.isAlive() ):
					i += 1
		return i

	def broadcast (self, message):
		msg = json.dumps(message,separators=(',',':'))
		for player in self.players:
			if ( player != "" ):
				player.getIPort().send(msg + "\r\n")

	def isAllReady (self):
		b = True
		for player in self.players:
			if ( player != "" ):
				if ( player.getReadiness() == False ):
					b = False

		return b

	def startGame (self):
		i = 0
		for player in self.players:
			self.kpu_data[i] = 0
			i += 1

		werewolf = self.playerNum / 3
		villager = self.playerNum - werewolf

		wfplayer = []
		i = 0

		for player in self.players:
			if ( player != "" ):
				rnd = random.randint(0, 1)		

				if ( rnd == 1 ):
					if ( villager <= 0 ):
						player.setRole("werewolf")						
						werewolf -= 1
						wfplayer.append(i)
					else:
						player.setRole("villager")
						villager -= 1
				else:
					if ( villager <= 0 ):
						player.setRole("werewolf")
						werewolf -= 1
						wfplayer.append(i)
					else:
						player.setRole("villager")
						villager -= 1
				i += 1

		for player in self.players:
			if ( player != "" ):
				player.getIPort().send(self.startGameToJSON(player.getRole(), wfplayer))			

		return None

	def startGameToJSON (self, role, wfplayer):
		class message(object):
			def __init__(self):
				self.method = "start"
				self.time = "night"
				self.role = ""
				self.friend = []
				self.description = "game is started"

		msgobj = message()

		msgobj.role = role

		if ( role == "werewolf" ):
			for wf in wfplayer:
				msgobj.friend.append((self.players[wf]).getName())

		msg = json.dumps(msgobj.__dict__)
		return msg

	def isEndGame (self):
		villager = self.getTotalAlivePlayer() - self.getTotalAliveWerewolf()
		werewolf = self.getTotalAliveWerewolf()
		winner = -1

		print "Check Game End State"
		print "Werewolf: ", werewolf
		print "Villager: ", villager

		if ( werewolf == villager ):
			winner = 0
		elif ( werewolf == 0 ):
			winner = 1
		else:
			winner = -1

		if ( winner != -1 ):
			winning = "undefined"

			if ( winner == 0 ):
				winning = "werewolf"
			else:
				winning = "villager"

			self.game.setWinner(winner)
			self.game.stopGame()

			for player in self.players:
				if ( player != "" ):
					player.getIPort().send(json.dumps({"method":"game_over", "winner":winning, "description":"Game Ended"}) + "\r\n")

	def newPlayer (self, name, iport, udip, udport):
		i = 0
		for x in self.players:
			if ( x == "" ):
				self.players[i] = Player(i, iport, name, udip, udport)
				self.playerNum += 1
				return i
			i += 1
		return i

	def delPlayer (self, pid):
		self.players[pid] = ""
		self.playerNum -= 1
		a = 0
		for i in range(pid, (self.playerNum + 1)): 
			if (self.players[i] != ""):
				(self.players[i]).setID(a)
				a += 1

	def delPlayerByID (self, pid):
		rid = -1
		i = 0
		for player in self.players:
			if ( player != "" ):
				if ( player.getID() == pid ):
					rid = i
			i += 1
		self.delPlayer(rid)


class MessageServer:
	client = 0

	def __init__ (self, clientsocket, clientaddr, GameServer):
		self.clientid = -1
		print "Accepted connection from ", tuple(clientaddr)

		self.GameServer = GameServer
		onLoop = True

		while onLoop:			
			try:
				msg = clientsocket.recv(4096)
				msg = msg.split("\r\n", 1)
				data = msg[0]
				if not data:
					break
				else:
					print "Received: " + data
					self.interpreter(data, clientsocket, GameServer)
			except error:
				GameServer.delPlayer(self.clientid)
				onLoop = False

		clientsocket.close()


	def interpreter (self, message, clientsocket, GameServer):
		msg = json.loads(message)

		if msg['method'] == 'join':
			if msg['username'] != "":
				if GameServer.getPlayerByUsername(msg['username']) == -1:
					if not ((GameServer.getGame()).isGameStarted()):
						# Register player ke Server
						self.clientid = GameServer.newPlayer(msg['username'], clientsocket, msg['udp_address'], msg['udp_port'])
						# Katakan bahwa login berhasil
						self.sendResponse(clientsocket, json.dumps({"status":"ok", "player_id":self.clientid}))						
					else:
						self.sendResponse(clientsocket, json.dumps({"status":"fail", "description":"please wait, game is currently running"}))
				else:
					self.sendResponse(clientsocket, json.dumps({"status":"fail", "description":"user exist"}))
			else:
				self.sendResponse(clientsocket, json.dumps({"status":"error", "description":"wrong request"}))

		elif msg['method'] == 'leave':
			GameServer.delPlayer(self.clientid)
			self.sendResponse(clientsocket, json.dumps({"status":"ok"}))

		elif msg['method'] == 'ready':
			(GameServer.getPlayerByPID(self.clientid)).setReadiness(True)
			self.sendResponse(clientsocket, json.dumps({"status":"ok", "description":"waiting for other player to start"}))
			if ( (GameServer.isAllReady()) and (GameServer.getTotalPlayer() >= 3) ):
				GameServer.startGame()

		elif msg['method'] == 'client_address':
			self.sendResponse(clientsocket, self.clientsToJSON(GameServer))

		elif msg['method'] == 'vote_result_werewolf':
			if (msg['vote_status'] == 1):
				#GameServer.delPlayerByID(msg['player_killed'])
				(GameServer.getPlayerByPID(msg['player_killed'])).setAlive(0)
				(GameServer.getGame()).changeTime()
				GameServer.broadcast({"method":"change_phase", 
									  "time":"day", 
									  "days": (GameServer.getGame()).getDay(), 
									  "description":"Werewolf voted, civilian killed"})
				GameServer.isEndGame()
			else:	
				GameServer.broadcast({"method":"vote_now", "phase":"night"})				

		elif msg['method'] == 'vote_result_civilian':
			if (msg['vote_status'] == 1):
				#GameServer.delPlayerByID(msg['player_killed'])
				(GameServer.getPlayerByPID(msg['player_killed'])).setAlive(0)
				(GameServer.getGame()).changeTime()
				GameServer.broadcast({"method":"change_phase", 
									  "time":"night", 
									  "days": (GameServer.getGame()).getDay(), 
									  "description":"Civilian voted, someone killed"})
				GameServer.isEndGame()
			else:				
				if (GameServer.getDayChance() != 0):			
					GameServer.broadcast({"method":"vote_now", "phase":"day"})
					GameServer.decreaseDayChance()
				else:
					GameServer.resetDayChance()
					GameServer.broadcast({"method":"change_phase", 
										  "time":"night", 
										  "days": (GameServer.getGame()).getDay(), 
										  "description":"Civilian cannot decide. No one killed."})					

		elif msg['method'] == 'accepted_proposal':
			GameServer.setKPUCount(msg['kpu_id'], GameServer.getKPUCount(msg['kpu_id']) + 1)
			GameServer.increaseKPUVoted()
			self.sendResponse(clientsocket, json.dumps({"status":"ok", "description":"KPU is selected"}))

			if (GameServer.getKPUVoted() > ((GameServer.getTotalPlayer()//2) + 1)):
				kpu_id = GameServer.getConsensusKPU()
				GameServer.resetKPUVoted()
				GameServer.resetKPUCount()

				for player in self.players:
					if ( player != "" ):
						player.getIPort().send(json.dumps({"method":"kpu_selected", "kpu_id":kpu_id}) + "\r\n")


				for player in self.players:
					if ( player != "" ):
						player.getIPort().send(json.dumps({"method":"vote_now", "phase":(GameServer.getGame()).getDay()}) + "\r\n")

			#(GameServer.getGame()).setKPU(msg['kpu_id'])


	def clientsToJSON (self, GameServer):
		class message(object):
			def __init__(self):
				self.status = "ok"
				self.description = "list of clients retrieved"
				self.clients = []

		msgobj = message()

		for client in GameServer.getPlayerList():
			if ( client != "" ):
				if (client.isAlive()):
					msgobj.clients.append({"player_id": client.getID(), 
										"is_alive": client.isAlive(), 
										"address": client.getUdIP(), 
										"port": client.getUdPort(), 
										"username": client.getName()})
				else:					
					msgobj.clients.append({"player_id": client.getID(), 
										"is_alive": client.isAlive(), 
										"address": client.getUdIP(), 
										"port": client.getUdPort(), 
										"username": client.getName(), 
										"role": client.getRole()})

		msg = json.dumps(msgobj.__dict__)
		return msg

	def sendResponse (self, clientsocket, msg):
		print msg
		clientsocket.send(msg +"\r\n")

	def __del__ (self):
		self.GameServer.delPlayer(self.clientid)
		print "Message Server destroyed"

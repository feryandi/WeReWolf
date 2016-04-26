from socket import *
import struct
import thread
import json

from game import *

class GameServer:
	def __init__ (self):
		self.players = [""] * 25 # maximum players online 
		self.game = Game()
		self.playerNum = 0

	def getGame(self):
		return self.game

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

	def broadcast (self, rid, message):
		msg = json.dumps(message,separators=(',',':'))
		for player in self.players:
			if ( player != "" ):
				player.getIPort().send(msg + "\r\n")

	def isAllReady (self, rid):
		b = True
		for player in self.players:
			if ( player != "" ):
				if ( player.getReadiness() == False ):
					b = False

		return b

	def startGame (self, rid):
		for player in self.players:
			if ( player != "" ):
				# player.getIPort().send(msg + "\r\n")
				return None

		return None

	def newPlayer (self, name, iport, udip, udport):
		i = 0
		for x in self.players:
			if ( x == "" ):
				self.players[i] = Player(i, iport, name, udip, udport)
				playerNum += 1
				return i
			i += 1
		return None

	def delPlayer (self, pid):
		self.players[pid] = ""
		a = 0
		for i in range(pid, playerNum + 1): 
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
		delPlayer(rid)


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
						# Berikan list Room yang ada
						# self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))
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

		elif msg['method'] == 'client_address':
			self.sendResponse(clientsocket, self.clientsToJSON(GameServer))

		elif msg['method'] == 'vote_result_werewolf':
			if (msg['vote_status'] == 1):
				GameServer.delPlayerByID(msg['player_killed'])
				(GameServer.getGame()).changeTime()
				GameServer.broadcast({"method":"change_phase", 
									  "time":"day", 
									  "days": (GameServer.getGame()).getDay(), 
									  "description":"Werewolf voted, civilian killed"})

		elif msg['method'] == 'vote_result_civilian':
			if (msg['vote_status'] == 1):
				GameServer.delPlayerByID(msg['player_killed'])
				(GameServer.getGame()).changeTime()
				GameServer.broadcast({"method":"change_phase", 
									  "time":"night", 
									  "days": (GameServer.getGame()).getDay(), 
									  "description":"Civilian voted, someone killed"})


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
					msgobj.data.append({"player_id": client.getID(), 
										"is_alive": client.isAlive(), 
										"address": client.getUdIP(), 
										"port": client.getUdPort(), 
										"username": client.getName()})
				else:					
					msgobj.data.append({"player_id": client.getID(), 
										"is_alive": client.isAlive(), 
										"address": client.getUdIP(), 
										"port": client.getUdPort(), 
										"username": client.getName(), 
										"role": client.getRole()})

		msg = json.dumps(msgobj.__dict__)
		return msg

	def startGameToJSON (self, GameServer):
		class message(object):
			def __init__(self):
				self.method = "start"
				self.time = "night"
				self.role = ""
				self.friend = []
				self.description = "game is started"

		msgobj = message()

		msg = json.dumps(msgobj.__dict__)
		return msg

	def sendResponse (self, clientsocket, msg):
		print msg
		clientsocket.send(msg +"\r\n")

	def __del__ (self):
		self.GameServer.delPlayer(self.clientid)
		print "Message Server destroyed"

from socket import *
import struct
import thread
import json

from game import *

class GameServer:
	def __init__ (self):
		self.players = [""] * 25 # maximum players online 
		self.game = Game()

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

	def newPlayer (self, name, iport):
		i = 0
		for x in self.players:
			if ( x == "" ):
				self.players[i] = Player(i, iport, name)
				return i
			i += 1
		return None

	def delPlayer (self, pid):
		self.players[pid] = ""


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
						self.clientid = GameServer.newPlayer(msg['username'], clientsocket)
						# Katakan bahwa login berhasil
						self.sendResponse(clientsocket, json.dumps({"status":"ok", "player_id":self.clientid}))
						# Berikan list Room yang ada
						# self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))
					else:
						self.sendResponse(clientsocket, json.dumps({"status":"fail", "description":"please wait, game is currently running"}))
				else:
					self.sendResponse(clientsocket, json.dumps({"status":"fail", "description":"user exist"}))
			else:
				self.sendResponse(clientsocket, json.dumps({"status":"fail", "description":"wrong request"}))


	def objectToJSON (self, request, GameServer):
		class message(object):
			def __init__(self):
				self.type = "response"
				self.object = "undefined"
				self.data = []

		msgobj = message()

		#if (request == "rooms"):
		#	msgobj.object = "rooms"
		#	for room in GameServer.getRoomList():
		#		if ( room != "" ):
		#			msgobj.data.append({"id": room[0].getID(), "name":room[0].getName()})

		msg = json.dumps(msgobj.__dict__)
		return msg

	def sendResponse (self, clientsocket, msg):
		print msg
		clientsocket.send(msg +"\r\n")

	def __del__ (self):
		self.GameServer.delPlayer(self.clientid)
		print "Message Server destroyed"

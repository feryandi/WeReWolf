from socket import *
import struct
import thread
import json

from game import *

class GameServer:
	character = ['X', 'O', '☺', 'L', 'M'] # maximum 5 players per room (?)

	def __init__ (self):
		self.players = [""] * 25 # maximum players online 
		self.rooms = [""] * 10 # maximum rooms active

	def getPlayerList (self):
		return self.players

	def getPlayerByPID (self, pid):
		return self.players[pid]

	def getRoomList (self):
		return self.rooms

	def broadcastByRoom (self, rid, message):
		msg = json.dumps(message,separators=(',',':'))
		for player in self.players:
			if ( ( player != "" ) and ( player.getRoomID() == rid ) ):
				player.getIPort().send(msg + "\r\n")

	def broadcastByPID (self, pid, message):
		msg = json.dumps(message,separators=(',',':'))
		player = self.players[pid]
		if player != "":
			player.getIPort().send(msg + "\r\n")


	def newPlayer (self, name, iport):
		i = 0
		for x in self.players:
			if ( x == "" ):
				self.players[i] = Player(i, iport, name)
				return i
			i += 1
		return None

	def newRoom (self, name, pid):
		i = 0
		for x in self.rooms:
			if ( x == "" ):
				self.rooms[i] = (Room(i, name, pid), Game(i, pid))
				return i
			i += 1
		return None

	def delPlayer (self, pid):
		self.players[pid] = ""

	def delRoom (self, rid):
		self.rooms[rid] = ""

	def playerJoin (self, pid, rid):
		if ( ( self.rooms[rid][1].getPlayerCount() < 5 ) and ( not self.rooms[rid][1].isGameStarted() ) ):
			self.players[pid].setRoomID(rid)
			self.rooms[rid][1].addPlayer(pid)
			self.players[pid].setChar(GameServer.character[self.rooms[rid][1].getPlayerCount() - 1])
			print "Player join room (" + str(rid) + ") and get character '" + self.players[pid].getChar() + "'"
			return 1
		else:
			print "User trying to join full room"
			return 0

	def playerQuit (self, pid):
		rid = self.players[pid].getRoomID()
		self.rooms[rid][1].delPlayer(pid)
		self.players[pid].setChar("?")
		print "Player (" + str(pid) + ") quit from game"

		if self.rooms[rid][1].getPlayerCount() == 0:
			self.delRoom(rid)
			print "Room (" + str(rid) + ") deleted because lack of players"


class MessageServer:
	client = 0

	def __init__ (self, clientsocket, clientaddr, GameServer):
		self.clientid = -1
		print "Accepted connection from ", tuple(clientaddr)

		self.GameServer = GameServer
		onLoop = True

		while onLoop:			
			try:
				# size = struct.unpack("i", clientsocket.recv(struct.calcsize("i")))
				# data = ""
				# while len(data) < size[0]:
				# 	msg = clientsocket.recv(size[0] - len(data))
					# if not msg:
					# 	return None
					# data += msg

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

		if msg['type'] == 'login':
			if msg['name'] != "":
				# Register player ke Server
				self.clientid = GameServer.newPlayer(msg['name'], clientsocket)
				# Katakan bahwa login berhasil
				self.sendResponse(clientsocket, json.dumps({"type":"login", "id":self.clientid}))
				# Berikan list Room yang ada
				self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))

		elif msg['type'] == 'startgame':
			rid = GameServer.getPlayerByPID(self.clientid).getRoomID()
			if GameServer.getRoomList()[rid][1].getPlayerCount() >= 3 :
				GameServer.getRoomList()[rid][1].startGame()
				GameServer.broadcastByRoom(rid, {"type":"startgame"})

		elif msg['type'] == 'newroom':
			if msg['name'] != "":
				# Buat room baru,
				rid = GameServer.newRoom(msg['name'], self.clientid)

				# Kirim ulang data rooms ke Client
				GameServer.broadcastByRoom(-1, json.loads(self.objectToJSON("rooms", GameServer)))

				# Kasi tau bahwa room berhasil dibuat
				self.sendResponse(clientsocket, json.dumps({"type":"newroom", "rid":rid}))

				# Kasi tau bahwa dia adalah owner room (yang bisa start game kalo udah ada 3 orang)
				# GameServer.broadcastByPID(self.clientid, {"type":"owner"})

		elif msg['type'] == 'spectate':
			GameServer.getPlayerByPID(self.clientid).setRoomID(int(msg['rid']))
			GameServer.getPlayerByPID(self.clientid).setSpectate(True)
			self.sendResponse(clientsocket, json.dumps({"type":"spectate", "rid":msg['rid']}))
			self.sendResponse(clientsocket, self.objectToJSON("board", GameServer))	

		elif msg['type'] == 'join':
			rid = msg['rid']
			if rid >= 0:
				# Join Player ke Game
				if GameServer.playerJoin(self.clientid, rid) == 1:
					# Beritahu ke player bahwa berhasil join
					self.sendResponse(clientsocket, json.dumps({"type":"join", "rid":rid}))
					GameServer.broadcastByRoom(rid, json.loads(self.objectToJSON("players", GameServer)))
					GameServer.getPlayerByPID(self.clientid).setSpectate(False)
				else:
					# Beritahu ke player bahwa GAGAL join (dengan cara diam seribu bahasa)
					pass

		elif msg['type'] == 'closegame':
			rid = GameServer.getPlayerByPID(self.clientid).getRoomID()

			if ( ( GameServer.getPlayerByPID(self.clientid) != "" ) and ( not GameServer.getPlayerByPID(self.clientid).isSpectate() ) ):
				rid = GameServer.getPlayerByPID(self.clientid).getRoomID()
				GameServer.playerQuit(self.clientid)

				if GameServer.getRoomList()[rid] != "":
					GameServer.broadcastByRoom(rid, json.loads(self.objectToJSON("players", GameServer)))

			GameServer.getPlayerByPID(self.clientid).setRoomID(-1)
			# Kirim ulang data rooms ke Client
			GameServer.broadcastByRoom(-1, json.loads(self.objectToJSON("rooms", GameServer)))

			self.sendResponse(clientsocket, json.dumps({"type":"closegame"}))

		elif msg['type'] == 'play':
			rid = GameServer.getPlayerByPID(self.clientid).getRoomID()
			game = GameServer.getRoomList()[rid][1]
			x = int(msg['x'])
			y = int(msg['y'])

			if game.isGameStarted():
				if ( ( game.getTurn() == self.clientid ) and ( not game.isBoardSet(int(msg['x']), int(msg['y']) ) ) ):
					game.setBoard(int(msg['x']), int(msg['y']), GameServer.getPlayerByPID(self.clientid).getChar())
					if game.isWin(int(msg['x']), int(msg['y']), GameServer.getPlayerByPID(self.clientid).getChar()) :
						GameServer.broadcastByRoom(rid, {"type":"win", "id":self.clientid, "name":GameServer.getPlayerByPID(self.clientid).getName()})
						game.stopGame()

						GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x, "y":y})
						for i in range(game.highlight[0]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x, "y":y + i + 1})
						for i in range(game.highlight[1]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x, "y":y - i - 1})
						for i in range(game.highlight[2]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x + i + 1, "y":y})
						for i in range(game.highlight[3]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x - i - 1, "y":y})
						for i in range(game.highlight[4]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x + i + 1, "y":y + i + 1})
						for i in range(game.highlight[5]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x - i - 1, "y":y - i - 1})
						for i in range(game.highlight[6]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x - i - 1, "y":y + i + 1})
						for i in range(game.highlight[7]/10) :
							GameServer.broadcastByRoom(rid, {"type":"highlight", "x":x + i + 1, "y":y - i - 1})

					game.nextTurn()
					GameServer.broadcastByRoom(rid, {"type":"play", "x":msg['x'], "y":msg['y'], "char":GameServer.getPlayerByPID(self.clientid).getChar(), "turn_id":game.getTurn()})
				else:
					print "[Room #" + str(rid) + "] Play denied. It's (" + str(game.getTurn()) + ") turn OR it's have owned by other user."
			else:
				print "[Room #" + str(rid) + "] Play denied. Game not started."

		elif msg['type'] == 'chat':
			GameServer.broadcastByRoom(GameServer.getPlayerByPID(self.clientid).getRoomID(), {"type":"chat", "message":msg['message'], "pid":self.clientid})

		elif msg['type'] == 'request':
			if msg['object'] == 'rooms':
				self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))
			elif msg['object'] == 'players':
				GameServer.broadcastByRoom(GameServer.getPlayerByPID(self.clientid).getRoomID(), json.loads(self.objectToJSON("players", GameServer)))
			elif msg['object'] == 'board':
				GameServer.broadcastByRoom(GameServer.getPlayerByPID(self.clientid).getRoomID(), json.loads(self.objectToJSON("board", GameServer)))

		elif msg['type'] == 'test':
			self.sendResponse(clientsocket, json.dumps({"type":"play"}))


	def objectToJSON (self, request, GameServer):
		class message(object):
			def __init__(self):
				self.type = "response"
				self.object = "undefined"
				self.data = []

		msgobj = message()

		if (request == "rooms"):
			msgobj.object = "rooms"
			for room in GameServer.getRoomList():
				if ( room != "" ):
					msgobj.data.append({"id": room[0].getID(), "name":room[0].getName()})

		elif (request == "players"):
			msgobj.object = "players"
			for player in GameServer.getRoomList()[GameServer.getPlayerList()[self.clientid].getRoomID()][1].getPlayerList():
				if GameServer.getPlayerByPID(player) != "":
					msgobj.data.append({"id":player, "name": GameServer.getPlayerByPID(player).getName(), "char":GameServer.getPlayerByPID(player).getChar()})

		elif (request == "board"):
			msgobj.object = "board"
			for b in GameServer.getRoomList()[GameServer.getPlayerList()[self.clientid].getRoomID()][1].getBoard():
				msgobj.data.append(b)

		msg = json.dumps(msgobj.__dict__)
		return msg

	def sendResponse (self, clientsocket, msg):
		print msg
		clientsocket.send(msg +"\r\n")

	def __del__ (self):
		self.GameServer.delPlayer(self.clientid)
		print "Message Server destroyed"

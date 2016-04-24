from player import *
from room import *

class Game:
	def __init__ (self, rid, pid):
		self.room = rid
		self.size = 20
		self.board = [ [ 0 for x in range(self.size) ] for x in range(self.size) ]
		self.turn = 0
		self.winner = -1
		self.players = []
		self.isStart = False
		self.highlight = [ 0 for x in range(8) ] # verticalA, verticalB, horizontalA, horizontalB, diagonalAA, diagonalAB, diagonalBA, diagonalBB

	def setBoard(self, x, y, char):
		self.board[x][y] = char

	def isBoardSet(self, x, y):
		return (self.board[x][y] != 0)

	def countSame(self, x, y, char, x_incr, y_incr):
		count = 0
		temp = char
		x_iter = x + x_incr
		y_iter = y + y_incr
		while temp == char and x_iter < self.size and y_iter < self.size :
			temp = self.board[x_iter][y_iter]
			if temp == char :
				count = count + 1
			x_iter = x_iter + x_incr
			y_iter = y_iter + y_incr
		return count

	def checkWin(self, x, y, char, x_incr, y_incr, highlight_idx):
		countA = self.countSame(x,y,char,x_incr,y_incr)
		self.highlight[highlight_idx] = countA
		countB = self.countSame(x,y,char,-x_incr,-y_incr)
		self.highlight[highlight_idx+1] = countB

		return countA + countB + 1 > 4

	def checkVertical(self, x, y, char):
		return self.checkWin(x,y,char,0,1,0)
		
	def checkHorizontal(self, x, y, char):
		return self.checkWin(x,y,char,1,0,2)

	def checkDiagonalA(self, x, y, char):
		return self.checkWin(x,y,char,1,1,4)

	def checkDiagonalB(self, x, y, char):
		return self.checkWin(x,y,char,-1,1,6)

	def changeHighlight(self, highlight_idx):
		self.highlight[highlight_idx] = self.highlight[highlight_idx] * 10
		self.highlight[highlight_idx+1] = self.highlight[highlight_idx+1] * 10

	def isWin(self, x, y, char):
		win = 0
		if self.checkVertical(x,y,char) :
			win = win + 1
			self.changeHighlight(0)
		if self.checkHorizontal(x,y,char) :
			win = win + 1
			self.changeHighlight(2)
		if self.checkDiagonalA(x,y,char) :
			win = win + 1
			self.changeHighlight(4)
		if self.checkDiagonalB(x,y,char) :
			win = win + 1
			self.changeHighlight(6)
		return win > 0

	def getOwner (self):
		if self.getPlayerCount() == 0:
			return ""
		else:
			return self.players[0]

	def isOwner (self, player):
		return player.getID() == self.getOwner().getID()

	def isGameStarted (self):
		return self.isStart

	def getBoard(self):
		return self.board

	def getPlayerCount (self):
		return len(self.players)

	def getTurn (self):
		return self.players[self.turn]

	def nextTurn (self):
		self.turn += 1
		if self.turn > len(self.players) - 1:
			self.turn = 0

	def getPlayerList (self):
		return self.players

	def addPlayer (self, pid):
		self.players.append(pid)

	def delPlayer (self, pid):
		self.players.remove(pid)

	def startGame (self):
		self.isStart = True

	def stopGame (self):
		self.isStart = False

	def __del__ (self):
		print "Game from Room ( " + str(self.room) + " ) stopped"
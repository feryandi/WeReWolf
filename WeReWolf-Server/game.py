from player import *

class Game:
	def __init__ (self):
		self.time = 0
		self.size = 20
		self.turn = 0
		self.winner = -1
		self.isStart = False

	def isGameStarted (self):
		return self.isStart

	def startGame (self):
		self.isStart = True

	def stopGame (self):
		self.isStart = False

	def changeTime (self):
		self.time += 1
		self.time %= 2
		self.turn += 1

	def __del__ (self):
		print "Game from Room ( " + str(self.room) + " ) stopped"
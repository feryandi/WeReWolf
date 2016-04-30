from player import *

class Game:
	def __init__ (self):
		self.time = 0
		self.size = 20
		self.turn = 0
		self.winner = -1
		self.isStart = False
		self.kpu = -1

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

	def getDay (self):
		return (self.turn / 2)

	def setKPU (self, kpu_id):
		self.kpu = kpu_id

	def getKPU (self):
		return self.kpu

	def setWinner (self, i):
		self.winner = i

	def __del__ (self):
		print "Game stopped"
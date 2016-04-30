class Player:
	def __init__ (self, pid, iport, name, udip, udport):
		self.id = pid
		self.iport = iport
		self.name = name
		self.role = 'undefined'

		self.alive = 1
		self.ready = False

		self.udport = udport
		self.udip = udip

		self.sKPU = -1

	def isAlive (self):
		return self.alive

	def setAlive (self, i):
		self.alive = i

	def getID (self):
		return self.id

	def setID (self, pid):
		self.id = pid

	def setRole(self, role):
		self.role = role

	def getRole(self):
		return self.role

	def getIPort (self):
		return self.iport

	def getUdPort (self):
		return self.udport

	def getUdIP (self):
		return self.udip

	def getName (self):
		return self.name

	def getReadiness (self):
		return self.ready

	def setReadiness (self, bool):
		self.ready = bool

	def __del__ (self):
		print "Player [ " +  self.name + " ("  + str(self.id) + ") ] exited"
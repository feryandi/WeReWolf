class Player:
	def __init__ (self, pid, iport, name):
		self.id = pid
		self.iport = iport
		self.name = name
		self.role = 'undefined'
		self.alive = True;
		self.ready = False;

	def isAlive (self):
		return self.alive

	def setAlive (self, bool):
		self.alive = bool

	def getID (self):
		return self.id

	def setID (self, pid):
		self.id = pid

	def getIPort (self):
		return self.iport

	def getName (self):
		return self.name

	def getReadiness (self):
		return self.ready

	def setReadiness (self, bool):
		self.ready = bool

	def __del__ (self):
		print "Player [ " +  self.name + " ("  + str(self.id) + ") ] exited"

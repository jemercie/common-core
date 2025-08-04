import json
from channels.generic.websocket import WebsocketConsumer
from . import hook
from . import socketlib

LOCAL_VARS = {}
LOCAL_VARS["_increment"] = 0
LOCAL_VARS["users"] = {}
LOCAL_VARS["sockets"] = {}

class Consumer( WebsocketConsumer ):
	def connect( self ):
		self.accept()
		self.uniqueid = LOCAL_VARS["_increment"]
		self.callback = {}
		LOCAL_VARS["_increment"] += 1

		if self.IsAuthenticated():
			LOCAL_VARS["users"][ self.GetName() ] = self
		LOCAL_VARS["sockets"][ self.GetUniqueID() ] = self
		self.SendFunction( 'connection_established', { "username":self.GetName(), "message": "Bonjour" } )

		users = {}
		for user in socketlib.getAllUsers().values():
			users[ user.GetName() ] = True
		self.SendFunction( 'get_users', { "users" : users } )

		if self.IsAuthenticated():
			socketlib.broadcastFunction( 'add_user', { "user" : self.GetName() } )
			hook.Call("OnConnected", { "socket":self, "user":self.User() })

	def disconnect(self, _):
		if self.IsAuthenticated():
			hook.Call("OnDisconnected", { "socket":self, "user":self.User() })
			socketlib.broadcastFunction( 'remove_user', { "user" : self.GetName() } )

			if self.GetName() in LOCAL_VARS["users"].keys():
				del LOCAL_VARS["users"][ self.GetName() ]
		if self.GetUniqueID() in LOCAL_VARS["sockets"].keys():
			del LOCAL_VARS["sockets"][ self.GetUniqueID() ]

	def receive(self, text_data):
		jsonData = json.loads( text_data )

		if "callback_server" in jsonData:
			if jsonData['callback_server'] in self.callback:
				self.callback[ jsonData['callback_server'] ]( self, jsonData['args'] )
				del self.callback[ jsonData['callback_server'] ]
				return

		function = jsonData['function']
		args = jsonData['args']
		if function in socketlib.FUNCTION:
			ret = socketlib.FUNCTION[ function ]( self, args )
			if "callback_client" in jsonData:
				retData = {}
				retData["callback_client"] = jsonData['callback_client']
				retData["args"] = ret
				self.Send( retData )
		else:
			print( self.GetIDName(), "attempt to call unknown function:", function)

	def User( self ):
		return self.scope["user"]
	
	def IsAuthenticated( self ):
		return self.User().is_authenticated
	
	def GetName( self ):
		if self.IsAuthenticated():
			return self.User().username
		return "Anonymous User"
	
	def GetIDName( self ):
		return self.GetName() + '(' + str(self.GetUniqueID()) + ')'
	
	def GetUniqueID( self ):
		return self.uniqueid
	
	def Send( self, jsonData ):
		self.send( text_data = json.dumps( jsonData ) )

	def SendFunction( self, name, args, *callback ):
		jsonData = {}
		jsonData["function"] = name
		jsonData["args"] = args
		for func in callback:
			index = insertInArray( self.callback, func )
			jsonData["callback_server"] = index

		self.Send( jsonData )

def insertInArray( dict, value ):
	index = 1
	while (index in dict):
		index = index + 1
	dict[ index ] = value

	return index
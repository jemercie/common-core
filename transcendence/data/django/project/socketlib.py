from . import consumers
import json

FUNCTION = {}
def registerFunction( name, function ):
	FUNCTION[ name ] = function

def getByID( id ):
	if id in consumers.LOCAL_VARS["sockets"]:
		return consumers.LOCAL_VARS["sockets"][ id ]
	return None

def getByName( name ):
	if name in consumers.LOCAL_VARS["users"]:
		return consumers.LOCAL_VARS["users"][ name ]
	return None

def getAllUsers():
	return consumers.LOCAL_VARS["users"]

def getAll():
	return consumers.LOCAL_VARS["sockets"]

def broadcastFunction( name, args ):
	for socket in getAll().values():
		socket.SendFunction( name, args )

from . import socket_function
from app_chat import socket_function
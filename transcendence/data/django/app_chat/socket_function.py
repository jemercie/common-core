from project import socketlib

def function( client, args ):
	if not client.IsAuthenticated():
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Vous n'etes pas authentifié"})
		return
	
	if "message" not in args:
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Il n'y a pas de message"})
		return
	elif (len(args["message"]) == 0):
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Il n'y a pas de message"})
		return
	elif (len(args["message"]) > 256):
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Le message est trop long (Max:256)"})
		return

	target = socketlib.getByName( args["target"] )
	if target == client:
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Vous ne pouvez pas vous envoyer un message a vous meme"})
		return
	
	if ( target is not None ):
		if isIgnore( target.User(), client.User() ):
			client.SendFunction("notify", {"type":"error", "delay":5, "message": "Vous ne pouvez pas envoyer un message a la cible car elle vous ignore"})
			return
		target.SendFunction( "CHAT.PrivateMessage", { "target":client.GetName(), "message":args["message"], "isSender":False } )
		client.SendFunction( "CHAT.PrivateMessage", { "target":target.GetName(), "message":args["message"], "isSender":True } )
	else:
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "La cible n'est pas en ligne"})

socketlib.registerFunction( 'CHAT.SendPrivateMessage', function )

def function( client, args ):
	if not client.IsAuthenticated():
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Vous n'etes pas authentifié"})
		return
	
	if "message" not in args:
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Il n'y a pas de message"})
		return
	elif (len(args["message"]) == 0):
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Il n'y a pas de message"})
		return
	elif (len(args["message"]) > 256):
		client.SendFunction("notify", {"type":"error", "delay":5, "message": "Le message est trop long (Max:256)"})
		return

	socketlib.broadcastFunction( "CHAT.GlobalMessage", { "author":client.GetName(), "message":args["message"] })

socketlib.registerFunction( 'CHAT.SendGlobalMessage', function )






# FRIENDS FUNCTION
from django.contrib.auth.models import User
from app_chat.models import FriendList, IgnoreList
from project import hook

def isFriend( fromUser, toUser ):
	query = FriendList.objects.all()
	query = query.filter( fromUser=fromUser, toUser=toUser )
	if (query.exists()):
		return True
	return False

def getFriends(user):
    friends_list = []
    query = FriendList.objects.filter(fromUser=user)
    if query.exists():
        for item in query:
            friend_id = item.toUser.username
            friend = item.toUser
            friends_list.append((friend_id, friend))
    return friends_list

def function( client, args ):
	query = User.objects.all()
	query = query.filter( username = args["target"] )
	if (query.exists()):
		if (isFriend( client.User(), query[0])):
			client.SendFunction("error", {"message": "La cible est deja dans votre liste d'amis"})
			return
		FriendList.objects.create( fromUser = client.User(), toUser = query[0])
		client.SendFunction("AddFriend", {"target":args["target"]})
	else:
		client.SendFunction("error", {"message": "L'utilisateur n'est pas trouver dans la base de donnee"})
socketlib.registerFunction( 'AddFriend', function )

def function( client, args ):
	if not client.IsAuthenticated():
		client.SendFunction("error", {"message": "Vous n'etes pas authentifié"})
		return
	
	query = User.objects.all()
	query = query.filter( username = args["target"] )
	if (query.exists()):
		if (not isFriend( client.User(), query[0])):
			client.SendFunction("error", {"message": "L'utilisateur n'est pas dans votre liste d'amis"})
			return
		
		try:
			obj = FriendList.objects.get(fromUser=client.User(), toUser=query[0])
			obj.delete()
		except FriendList.DoesNotExist:
			print("Error: Friend link doesnt exists")
	
		client.SendFunction("RemoveFriend", {"target":args["target"]})
	else:
		client.SendFunction("error", {"message": "L'utilisateur n'est pas trouver dans la base de donnee"})
socketlib.registerFunction( 'RemoveFriend', function )


# IGNORE FUNCTION 

def isIgnore( fromUser, toUser ):
	query = IgnoreList.objects.all()
	query = query.filter( fromUser=fromUser, toUser=toUser )
	if (query.exists()):
		return True
	return False

def getIgnores( user ):
	tbl = {}
	query = IgnoreList.objects.all()
	query = query.filter( fromUser=user )
	if (query.exists()):
		for item in query:
			tbl[ item.toUser.username ] = True
	return tbl

def function( client, args ):
	if not client.IsAuthenticated():
		client.SendFunction("error", {"message": "Vous n'etes pas authentifié"})
		return
	
	query = User.objects.all()
	query = query.filter( username = args["target"] )
	if (query.exists()):
		if (isIgnore( client.User(), query[0])):
			client.SendFunction("error", {"message": "La cible est deja dans votre blacklist"})
			return
		IgnoreList.objects.create( fromUser = client.User(), toUser = query[0])
		client.SendFunction("AddIgnore", {"target":args["target"]})
	else:
		client.SendFunction("error", {"message": "L'utilisateur n'est pas trouver dans la base de donnee"})
socketlib.registerFunction( 'AddIgnore', function )

def function( client, args ):
	if not client.IsAuthenticated():
		client.SendFunction("error", {"message": "Vous n'etes pas authentifié"})
		return
	
	query = User.objects.all()
	query = query.filter( username = args["target"] )
	if (query.exists()):
		if (not isIgnore( client.User(), query[0])):
			client.SendFunction("error", {"message": "L'utilisateur n'est pas dans votre blacklist"})
			return
		
		try:
			obj = IgnoreList.objects.get(fromUser=client.User(), toUser=query[0])
			obj.delete()
		except IgnoreList.DoesNotExist:
			print("Error: Ignore link doesnt exists")
	
		client.SendFunction("RemoveIgnore", {"target":args["target"]})
	else:
		client.SendFunction("error", {"message": "L'utilisateur n'est pas trouver dans la base de donnee"})
socketlib.registerFunction( 'RemoveIgnore', function )

from django.core.exceptions import ObjectDoesNotExist
from app_user.models import ProfileModel

def function( args ):
	tbl = getFriends( args["user"] )
	args["socket"].SendFunction( "UpdateFriend", {"tbl":tbl} )

	tbl = getIgnores( args["user"] )
	args["socket"].SendFunction( "UpdateIgnore", {"tbl":tbl} )

	try:
		obj = ProfileModel.objects.get( user = args["user"] )
		socketlib.broadcastFunction("UpdateAvatarUser", {"user":args["socket"].GetName(), "avatar":obj.profile_image.url})
	except ObjectDoesNotExist:
		print("[ERROR]", args["user"], "ne dispose pas de profil dans la BDD")

	tbl = {}
	all_profiles = ProfileModel.objects.all()
	for profile in all_profiles:
		tbl[ profile.user.username ] = profile.profile_image.url
	args["socket"].SendFunction("UpdateAvatarAll", { "tbl":tbl } )

hook.Add("OnConnected", "CHAT.OnConnected", function)
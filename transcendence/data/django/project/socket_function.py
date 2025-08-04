from . import socketlib

""""
PROTOTYPE :

	dict	socketlib.registerFunction( string, function )
	NULL	self.SendFunction( string, dict, function )

	
Exemple pour declarer une fonction appellé depuis le client :

	socketlib.registerFunction( 'print', lambda client, args:(
		print( args["message"] )
	))


Exemple pour appeller une fonction du serveur:

	self.SendFunction( "print", { "message": "Print du client" } )
ou 
	args = {}
	args["message"] = "Print du client"
	SOCKET.SendFunction( "print", args )


Exemple pour envoyer une fonction au client et d'attendre un callback :
Le retour sera traité dans le 3eme argument de la fonction self.SendFunction
Dans la fonction clientside il faudra return les valeurs

	jArgs = {}
	jArgs["message"] = "Salut du serveur"
	self.SendFunction("print_callback", jArgs, lambda client, args:(
		print( client.GetName(), args["message"] )
	))

"""
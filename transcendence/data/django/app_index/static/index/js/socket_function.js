/*

PROTOTYPE:
array	SOCKET.registerFunction( string, function )
NULL 	SOCKET.SendFunction( string, array, function )


Exemple pour declarer une fonction appellé depuis le serveur :

	SOCKET.registerFunction("print", function( args )
	{
		console.log( args.message )
	})



Exemple pour appeller une fonction du serveur:

	SOCKET.SendFunction( "print", { "message": "Print du client" } )
ou 
	args = {}
	args.message = "Print du client"
	SOCKET.SendFunction( "print", args )



Exemple pour envoyer une fonction au serveur et d'attendre un callback :
Le retour sera traité dans le 3eme argument de la fonction SOCKET.SendFunction
Dans la fonction serverside il faudra return les valeurs

	SOCKET.SendFunction( "print_callback", args, function( args )
	{
		console.log( args.message )
	})
*/


SOCKET.registerFunction("connection_established", function( args )
{
	SOCKET.connected = true
	SOCKET.username = args.username
})

SOCKET.registerFunction("error", function( args )
{
	console.log( "[ERROR]", args.message )
})


SOCKET.UserList = {}
SOCKET.registerFunction("get_users", function( args )
{
	SOCKET.UserList = args.users
	hook.Call( "get_users", args )
})

SOCKET.registerFunction("add_user", function( args )
{
	SOCKET.UserList[ args.user ] = true
	hook.Call( "add_user", args )
})

SOCKET.registerFunction("remove_user", function( args )
{
	delete SOCKET.UserList[ args.user ]
	hook.Call( "remove_user", args )
})

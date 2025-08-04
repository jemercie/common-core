CHAT.Users = {}

CHAT.AddUser = function( login )
{
	CHAT.Users[ login ] = true
}

CHAT.RemoveUser = function( login )
{
	delete CHAT.Users[ login ]
}

hook.Add("get_users", "CHAT.get_users", function( args )
{
	const entries = Object.entries( args.users );
	entries.forEach(function([key, value]) {
		if ( SOCKET.username != key ) {
			CHAT.AddUser( key );
		}
	});
})

hook.Add("add_user", "CHAT.add_user", function( args )
{
	if ( SOCKET.username == args.user){
		return;
	}

	CHAT.AddUser( args.user );
})

hook.Add("remove_user", "CHAT.remove_user", function( args )
{
	CHAT.RemoveUser( args.user );
})
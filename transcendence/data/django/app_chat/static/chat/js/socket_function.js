SOCKET.registerFunction("CHAT.PrivateMessage", function( args )
{
	hook.Call( "OnPrivateMessage", args )
})

SOCKET.registerFunction("CHAT.GlobalMessage", function( args )
{
	hook.Call( "OnGlobalMessage", args )
})

SOCKET.registerFunction("UpdateAvatarUser", function( args )
{
	hook.Call( "OnUpdateAvatarUser", args )
})

SOCKET.registerFunction("UpdateAvatarAll", function( args )
{
	const entries = Object.entries( args.tbl );
	entries.forEach(function([key, value]) {
		hook.Call( "OnUpdateAvatarUser", {user:key, avatar:value} )
	});
})
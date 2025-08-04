FRIENDS = {}
FRIENDS.Table = {}

// FUNCTION
FRIENDS.getTable = function()
{
	return FRIENDS.Table
}

FRIENDS.isFriend = function( name )
{
	return FRIENDS.Table[ name ]
}


// SOCKET FUNCTION 
SOCKET.registerFunction("UpdateFriend", function( args )
{
	FRIENDS.Table = args.tbl
	hook.Call( "OnUpdateFriend", args )
})

SOCKET.registerFunction("AddFriend", function( args )
{
	FRIENDS.Table[ args.target ] = true
	hook.Call( "OnAddFriend", args )
})

SOCKET.registerFunction("RemoveFriend", function( args )
{
	delete FRIENDS.Table[ args.target ]
	hook.Call( "OnRemoveFriend", args )
})
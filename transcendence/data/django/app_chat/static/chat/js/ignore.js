IGNORE = {}
IGNORE.Table = {}

// FUNCTION
IGNORE.getTable = function()
{
	return IGNORE.Table
}

IGNORE.isIgnore = function( name )
{
	return IGNORE.Table[ name ]
}

// SOCKET FUNCTION 
SOCKET.registerFunction("UpdateIgnore", function( args )
{
	IGNORE.Table = args.tbl

	let ignore_btn = document.querySelector('.chat_ignore_button');
	if (ignore_btn)
		ignore_btn.UpdateState()

	hook.Call( "OnUpdateIgnore", args )
})

SOCKET.registerFunction("AddIgnore", function( args )
{
	IGNORE.Table[ args.target ] = true

	let ignore_btn = document.querySelector('.chat_ignore_button');
	if (ignore_btn)
		ignore_btn.UpdateState()

	hook.Call( "OnAddIgnore", args )
})

SOCKET.registerFunction("RemoveIgnore", function( args )
{
	delete IGNORE.Table[ args.target ]

	let ignore_btn = document.querySelector('.chat_ignore_button');
	if (ignore_btn)
		ignore_btn.UpdateState()

	hook.Call( "OnRemoveIgnore", args )
})
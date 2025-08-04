let url = `ws://${window.location.host}/ws/socket-server/`

SOCKET = {}
SOCKET.FUNCTION = {}
SOCKET.FUNCTION_CALLBACK = {}
SOCKET.registerFunction = function( name, func )
{
	SOCKET.FUNCTION[ name ] = func
}

SOCKET.socket = new WebSocket( url )
SOCKET.socket.onmessage = function( e ){
	let data = JSON.parse( e.data )

	let funcName = data.function
	let args = data.args
	let callback_server = data.callback_server
	let callback_client = data.callback_client

	if ( callback_client && SOCKET.FUNCTION_CALLBACK[ callback_client ] )
	{
		SOCKET.FUNCTION_CALLBACK[ callback_client ]( args )
		delete SOCKET.FUNCTION_CALLBACK[ callback_client ]
		return
	}

	if (SOCKET.FUNCTION[ funcName ])
	{
		let ret = SOCKET.FUNCTION[ funcName ]( args )
		if (callback_server)
		{
			let jArgs = {}
			jArgs["callback_server"] = callback_server
			jArgs["args"] = ret
			SOCKET.Send( jArgs )
		}
	}
	else
	{
		console.log("Attempt to run unknown function", funcName)
	}
	console.log("Data", data)
}

SOCKET.Send = function( jsonData )
{
	SOCKET.socket.send( JSON.stringify( jsonData ) )
}

SOCKET.SendFunction = function( name, args, callback )
{
	const jsonData = {}
	jsonData["function"] = name
	jsonData["args"] = args
	if ( callback )
	{
		let index = insertInArray( SOCKET.FUNCTION_CALLBACK, callback )
		jsonData["callback_client"] = index
	}

	SOCKET.Send( jsonData )
}

SOCKET.GetName = function()
{
	return SOCKET.username
}

function insertInArray( array, value )
{
	let index = 1
	while ( array[ index ] )
		index += 1
	array[ index ] = value

	return index
}
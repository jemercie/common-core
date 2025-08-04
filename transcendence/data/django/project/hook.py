Table = {}

def Add( name, id, func ):
	if (not name in Table):
		Table[ name ] = {}
	Table[ name ][ id ] = func

def Remove( name, id ):
	if ( not name in Table ):
		return
	del Table[ name ][ id ]

def Call( name, args ):
	if ( not name in Table ):
		return
	for id in Table[ name ]:
		Table[ name ][ id ]( args )
	

hook = {}
hook.table = {}

hook.Add = function( name, id, func )
{
	if ( !hook.table[ name ] ){
		hook.table[ name ] = {}
	}

	hook.table[ name ][ id ] = func
}

hook.Remove = function( name, id )
{
	if ( !hook.table[ name ] ){ return; }
	
	delete hook.table[ name ][ id ];
}

hook.Call = function( name, args )
{
	if ( !hook.table[ name ] ){ return; }

	const entries = Object.entries( hook.table[ name ] );
	entries.forEach( function( [key, value] ) {
		value( args )
	});
}
CHAT.TextBox = document.getElementById('chat_textbox');
if ( CHAT.TextBox && !CHAT.TextBox.initialized )
{
	CHAT.TextBox.initialized = true
	CHAT.TextBox.addEventListener('keydown', function( event ) {
		if (event.key === "Enter") {
			const message = CHAT.TextBox.value
			if ( message.length <= 0 )
				return

			if ( CHAT.Frame.User ){
				SOCKET.SendFunction( "CHAT.SendPrivateMessage", { target:CHAT.Frame.User, message:message } )
			}
			else {
				SOCKET.SendFunction( "CHAT.SendGlobalMessage", { message:message } )
			}
			CHAT.TextBox.value = ''
		}
	});
}
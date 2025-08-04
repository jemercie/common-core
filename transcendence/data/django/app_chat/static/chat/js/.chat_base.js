CHAT.AvatarTable = {}

CHAT.Frame = {}
CHAT.Frame.ChatMessages = {}
CHAT.Frame.GlobalMessages = {}


CHAT.USERS = {}
CHAT.USERS.List = {}
CHAT.USERS.Active = false;

CHAT.F_USERS = {}
CHAT.F_USERS.List = {}
CHAT.F_USERS.Active = false;

// FUNCTION
CHAT.Frame.ShowGlobalChannel = function()
{
	const profileImage = document.getElementById('chat_header_img');
	const profileName = document.getElementById('chat_header_p');

	profileImage.src = "https://thumbs.dreamstime.com/b/vector-globe-icon-world-globe-icon-world-vector-illustration-126263075.jpg"
	profileName.textContent = "#Global Channel"

	const chat_body = document.querySelector('.chat_body');
	while (chat_body.firstChild) {
		chat_body.removeChild(chat_body.firstChild);
	}

	const friend_btn = document.querySelector('.chat_friend_button');
	if (friend_btn)
		friend_btn.remove()

	const ignore_btn = document.querySelector('.chat_ignore_button');
	if (ignore_btn)
		ignore_btn.remove()

	CHAT.Frame.User = null
	for (const [key, value] of Object.entries( CHAT.Frame.GlobalMessages )) {
		CHAT.Frame.PopupMessage( value );
	}
}

CHAT.Frame.OpenPrivateMessage = function( target )
{
	const chat_header = document.querySelector('.chat_header');
	const profileImage = document.getElementById('chat_header_img');
	const profileName = document.getElementById('chat_header_p');

	profileImage.src = "https://www.clarity-enhanced.net/wp-content/uploads/2020/06/robocop.jpg"
	if (CHAT.AvatarTable[ target ])
		profileImage.src = CHAT.AvatarTable[ target ]

	profileName.textContent = target

	const chat_body = document.querySelector('.chat_body');
	while (chat_body.firstChild) {
		chat_body.removeChild(chat_body.firstChild);
	}

	// FRIEND BUTTON
	let friend_btn = document.querySelector('.chat_friend_button');
	if (!friend_btn) {
		friend_btn = document.createElement('button');
		friend_btn.className = "chat_friend_button";
		friend_btn.addEventListener('click', function() {
			if ( !FRIENDS.isFriend( target ) )
				SOCKET.SendFunction("AddFriend", {target:friend_btn.target})
			else
				SOCKET.SendFunction("RemoveFriend", {target:friend_btn.target})
		});
		chat_header.appendChild( friend_btn );
	}
	friend_btn.UpdateState = function()
	{
		friend_btn.textContent = "Add Friend"
		if ( FRIENDS.isFriend( friend_btn.target ) )
			friend_btn.textContent = "Remove Friend"
	}
	friend_btn.target = target
	friend_btn.UpdateState()

	// IGNORE BUTTON
	let ignore_btn = document.querySelector('.chat_ignore_button');
	if (!ignore_btn) {
		ignore_btn = document.createElement('button');
		ignore_btn.className = "chat_ignore_button";
		ignore_btn.addEventListener('click', function() {
			if ( !IGNORE.isIgnore( target ) )
				SOCKET.SendFunction("AddIgnore", {target:ignore_btn.target})
			else
				SOCKET.SendFunction("RemoveIgnore", {target:ignore_btn.target})
		});
		chat_header.appendChild( ignore_btn );
	}
	ignore_btn.UpdateState = function()
	{
		ignore_btn.textContent = "Ignore"
		if ( IGNORE.isIgnore( ignore_btn.target ) )
			ignore_btn.textContent = "Stop ignoring"
	}
	ignore_btn.target = target
	ignore_btn.UpdateState()

	CHAT.Frame.User = target
	if ( CHAT.Frame.ChatMessages[ target ] )
	{
		for (const [key, value] of Object.entries( CHAT.Frame.ChatMessages[ target ] )) {
			CHAT.Frame.PopupMessage( value );
		}
	}
}

CHAT.Frame.PopupMessage = function( tbl )
{
	let classMessage = "chat_message_left"
	if ( tbl.isSender ){
		classMessage = "chat_message_right"
	}

	const chat_body = document.querySelector('.chat_body');
	const message = document.createElement('div');
	message.className = classMessage;


	if (tbl.isGlobal){
		const name = document.createElement('h6');
		name.textContent = tbl.target;
		message.appendChild(name);
	}

	const paragraph = document.createElement('p');
	paragraph.textContent = tbl.message;
	message.appendChild(paragraph);

	chat_body.appendChild( message );
	chat_body.scrollTop = chat_body.scrollHeight;
}



// HOOKS

hook.Add("OnUpdateAvatarUser", "CHAT.OnUpdateAvatarUser", function( args )
{
	CHAT.AvatarTable[ args.user ] = args.avatar
	if (CHAT.Frame.User && CHAT.Frame.User == args.user )
	{
		const profileImage = document.getElementById('chat_header_img');
		profileImage.src = args.avatar
	}

	if (CHAT.USERS.List[ args.user ])
	{
		if ( CHAT.USERS.List[ args.user ].img )
			CHAT.USERS.List[ args.user ].img.src = args.avatar
	}

	if (CHAT.F_USERS.List[ args.user ])
	{
		if ( CHAT.F_USERS.List[ args.user ].img )
			CHAT.F_USERS.List[ args.user ].img.src = args.avatar
	}
})

hook.Add("OnPrivateMessage", "CHAT.OnPrivateMessage", function( args )
{
	if ( !CHAT.Frame.ChatMessages[ args.target ] ){
		CHAT.Frame.ChatMessages[ args.target ] = {}
	}

	let tbl = {}
	tbl.target = args.target
	tbl.isSender = args.isSender
	tbl.message = args.message

	insertInArray( CHAT.Frame.ChatMessages[ args.target ], tbl )
	if ( CHAT.Frame.User == args.target )
		CHAT.Frame.PopupMessage( tbl )
})

hook.Add("OnGlobalMessage", "CHAT.OnGlobalMessage", function( args )
{
	let tbl = {}
	tbl.target = args.author
	tbl.message = args.message

	tbl.isSender = false
	if (args.author == SOCKET.username)
		tbl.isSender = true
	tbl.isGlobal = true

	insertInArray( CHAT.Frame.GlobalMessages, tbl )
	if ( !CHAT.Frame.User )
		CHAT.Frame.PopupMessage( tbl )
})

hook.Add("OnUpdateFriend", "CHAT.OnUpdateFriend", function( args )
{
	let friend_btn = document.querySelector('.chat_friend_button');
	if (friend_btn)
		friend_btn.UpdateState()
	CHAT.F_USERS.UpdateList()
})

hook.Add("OnAddFriend", "CHAT.OnUpdateFriend", function( args )
{
	let friend_btn = document.querySelector('.chat_friend_button');
	if (friend_btn)
		friend_btn.UpdateState()
	CHAT.F_USERS.UpdateList()
})

hook.Add("OnRemoveFriend", "CHAT.OnUpdateFriend", function( args )
{
	let friend_btn = document.querySelector('.chat_friend_button');
	if (friend_btn)
		friend_btn.UpdateState()
	CHAT.F_USERS.UpdateList()
})

CHAT.Frame.ShowGlobalChannel()
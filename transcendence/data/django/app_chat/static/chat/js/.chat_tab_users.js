CHAT.USERS.ShowList = function()
{
	if ( CHAT.USERS.Active ) { return }
	CHAT.F_USERS.HideList()

	CHAT.USERS.Active = true
	const tab_user = document.getElementById("tab_users")
	const tab_friends = document.getElementById("tab_friends")
	tab_user.style.background = "#111111"
	tab_friends.style.background = "#292929"

	const entries = Object.entries( CHAT.USERS.List );
	entries.forEach(function([key, value]) {
		value.style.display = 'flex';
	});
}

CHAT.USERS.HideList = function()
{
	if ( !CHAT.USERS.Active ) { return }
	CHAT.USERS.Active = false
	
	const entries = Object.entries( CHAT.USERS.List );
	entries.forEach(function([key, value]) {
		value.style.display = 'none';
	});
}

CHAT.USERS.AddUser = function( login )
{
	if (CHAT.USERS.List[ login ]){
		return;
	}

	const usersList = document.querySelector('.list');

	const newUser = document.createElement('div');
	newUser.className = 'user_info';
	newUser.id = 'user_info_' + login;

	newUser.addEventListener('click', function() {
		CHAT.Frame.OpenPrivateMessage( login )
	});

	const img = document.createElement('img');
	img.src = 'https://www.clarity-enhanced.net/wp-content/uploads/2020/06/robocop.jpg';
	img.alt = 'Avatar';

	if (CHAT.AvatarTable[ login ])
		img.src = CHAT.AvatarTable[ login ]
	newUser.img = img

	const paragraph = document.createElement('p');
	paragraph.textContent = login;

	newUser.appendChild(img);
	newUser.appendChild(paragraph);
	usersList.appendChild(newUser);

	if ( !CHAT.USERS.Active ) {
		newUser.style.display = 'none';
	}

	CHAT.USERS.List[ login ] = newUser
}

CHAT.USERS.RemoveUser = function( login )
{
	if (!CHAT.USERS.List[ login ]){
		return;
	}

	CHAT.USERS.List[ login ].remove()
	delete CHAT.USERS.List[ login ];
}

// HOOKS
hook.Add("get_users", "CHAT.get_users", function( args )
{
	const entries = Object.entries( args.users );
	entries.forEach(function([key, value]) {
		if ( SOCKET.username != key ) {
			CHAT.USERS.AddUser( key );
		}
	});
})

hook.Add("add_user", "CHAT.add_user", function( args )
{
	if ( SOCKET.username == args.user){
		return;
	}

	CHAT.USERS.AddUser( args.user );
})

hook.Add("remove_user", "CHAT.remove_user", function( args )
{
	CHAT.USERS.RemoveUser( args.user );
})

CHAT.USERS.ShowList()
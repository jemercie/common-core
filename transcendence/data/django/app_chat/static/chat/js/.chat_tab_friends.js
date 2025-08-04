CHAT.F_USERS.ShowList = function()
{
	if ( CHAT.F_USERS.Active ) { return }
	CHAT.USERS.HideList()

	CHAT.F_USERS.Active = true
	const tab_user = document.getElementById("tab_users")
	const tab_friends = document.getElementById("tab_friends")
	tab_user.style.background = "#292929"
	tab_friends.style.background = "#111111"

	const entries = Object.entries( CHAT.F_USERS.List );
	entries.forEach(function([key, value]) {
		value.style.display = 'flex';
	});
}

CHAT.F_USERS.HideList = function()
{
	if ( !CHAT.F_USERS.Active ) { return }
	CHAT.F_USERS.Active = false
	
	const entries = Object.entries( CHAT.F_USERS.List );
	entries.forEach(function([key, value]) {
		value.style.display = 'none';
	});
}

CHAT.F_USERS.UpdateList = function()
{
	const entries = Object.entries( CHAT.F_USERS.List );
	entries.forEach(function([key, value]) {
		window.clearInterval( CHAT.F_USERS.List[ key ].timer )
		CHAT.F_USERS.List[ key ].remove()
		delete CHAT.F_USERS.List[ key ]
	});

	const flist = Object.entries( FRIENDS.getTable() );
	flist.forEach(function([key, value]) {
		const usersList = document.querySelector('.list');
		const newUser = document.createElement('div');
		newUser.className = 'user_info';
		newUser.id = 'user_info_' + key;

		newUser.addEventListener('click', function() {
			CHAT.Frame.OpenPrivateMessage( key )
		});

		const img = document.createElement('img');
		img.src = 'https://www.clarity-enhanced.net/wp-content/uploads/2020/06/robocop.jpg';
		img.alt = 'Avatar';


		if (CHAT.AvatarTable[ key ])
			img.src = CHAT.AvatarTable[ key ]
		newUser.img = img

		const paragraph = document.createElement('p');
		paragraph.textContent = key;

		const isonline = document.createElement('h6');
		newUser.appendChild(img);
		newUser.appendChild(paragraph);
		newUser.appendChild(isonline);
		usersList.appendChild(newUser);

		newUser.checkStatus = function()
		{
			if ( SOCKET.UserList[ key ] )
			{
				newUser.isOnline = true
				isonline.textContent = "Online"
				isonline.style.color = 'rgb(0,210,10)';
			}
			else
			{
				newUser.isOnline = false
				isonline.textContent = "Offline"
				isonline.style.color = 'rgb(255,33,0)';
			}
		}
		
		newUser.timer = window.setInterval( function()
		{
			if (newUser == null || newUser == undefined)
			{
				console.log("destroyTimer", key)
				window.clearInterval( newUser.timer )
				return
			}

			newUser.checkStatus()
		}, 1000 )
		newUser.checkStatus()

		if ( !CHAT.F_USERS.Active ) {
			newUser.style.display = 'none';
		}

		CHAT.F_USERS.List[ key ] = newUser
	});
}
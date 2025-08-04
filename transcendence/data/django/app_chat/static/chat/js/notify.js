NOTIFY = {}
NOTIFY.OffSet = 50
NOTIFY.Table = {}

NOTIFY.Add = function( message, delay )
{
	const entries = Object.entries( NOTIFY.Table );
	entries.forEach(function([key, value]) {
		value.y = value.y + NOTIFY.OffSet
		value.style.transition = 'top 0.5s'
		value.style.top = value.y + 'px'
	});

	const newDiv = document.createElement('div')
	newDiv.className = 'notification'
	newDiv.textContent = message
	newDiv.y = 0

	newDiv.style.position = 'fixed'
	newDiv.style.top = '0px'
	newDiv.style.right = '0'
	newDiv.style.color = '#fff'
	newDiv.style.padding = '10px'
	newDiv.style.zIndex = '9999'
	newDiv.style.fontSize = '12px'
	newDiv.style.borderRadius = '4px'; // border-radius: 10px;
	newDiv.style.backgroundColor = 'rgba(23, 22, 27, 0.568)'; // background-color: rgba(23, 22, 27, 0.568);
	newDiv.style.border = '0.02px solid rgba(23, 22, 27, 0.882)'; // border: 0.02px rgba(23, 22, 27, 0.882) solid;
	newDiv.style.backdropFilter = 'blur(3px)'; // backdrop-filter: blur(3px);

	document.body.appendChild(newDiv);

	let index = insertInArray( NOTIFY.Table, newDiv )
	setTimeout(() => {
		newDiv.style.transition = 'transform 0.5s ease'
		newDiv.style.transform = 'translateX(100%)'
	}, (delay * 1000) - 500);

	setTimeout(() => {
		newDiv.remove()
		delete NOTIFY.Table[ index ]
	}, delay * 1000); 

	NOTIFY.AddProgressBar( newDiv, delay - 0.5 )

	console.log("Notification :", message)
}

NOTIFY.AddProgressBar = function( div, delay )
{
	const progressBar = document.createElement('div')
    progressBar.className = 'progress-bar'
    progressBar.style.width = '0%'
    progressBar.style.height = '5px'
    progressBar.style.backgroundColor = 'green'

	let progressWidth = 0;
    const progressInterval = setInterval(() => {
        progressWidth += 0.1
        progressBar.style.width = progressWidth + '%'

        if (progressWidth >= 100)
            clearInterval(progressInterval)
    }, delay);

    div.appendChild(progressBar);
}

SOCKET.registerFunction("notify", function( args )
{
	const type = args["type"]
	const message = args["message"]
	const delay = args["delay"]

	NOTIFY.Add( message, delay )
	hook.Call("OnNotify", { type:type, message:message, delay:delay } )
})

// UTILS
function insertInArray( array, value )
{
	let index = 1
	while ( array[ index ] )
		index += 1
	array[ index ] = value

	return index
}
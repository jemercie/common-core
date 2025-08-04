
const getLoginBox = async () => {
    try {
        const response = await fetch('/user/login/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getRegisterBox = async () => {
    try {
        const response = await fetch('/user/register/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getChat = async () => {
    console.log("fetching /chat");
    try {
        const response = await fetch('/chat/index/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;

        const scripts = tempElement.querySelectorAll('script');

        scripts.forEach((script) => {
            const newScript = document.createElement('script');
            if (script.src) {
                newScript.src = script.src;
            } else {
                newScript.textContent = script.textContent;
            }
            document.head.appendChild(newScript).parentNode.removeChild(newScript);
        });
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getGame = async () => {
    console.log("stats");
    try {
        const response = await fetch('/game/index/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;

        const scripts = tempElement.querySelectorAll('script');

        scripts.forEach((script) => {
            const newScript = document.createElement('script');
            if (script.src) {
                newScript.src = script.src;
            } else {
                newScript.textContent = script.textContent;
            }
            document.head.appendChild(newScript).parentNode.removeChild(newScript);
        });
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getGameStats = async () => {
    console.log("stats");
    // try {
    //     const response = await fetch('/app_game/stats/');
    //     const html = await response.text();

    //     const tempElement = document.createElement('div');
    //     tempElement.innerHTML = html;

    //     const contentText = tempElement.querySelector('#content').innerHTML;

    //     document.getElementById("main-page").innerHTML = contentText;
    // } catch (error) {
    //     console.error('Error fetching or displaying text:', error);
    // }
}
const getProfile = async () => {
    try {
        url = '/user/' + window.location.pathname.substring(1);
        const response = await fetch(url);
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getProfileUpdate = async () => {
    try {
        const response = await fetch('/user/profile_update/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}
const getHomeee = async () => {
    try {
        const response = await fetch('/home_index/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#content').innerHTML;

        document.querySelector("#main-page").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}

const route = (event, arg) => {
    console.log('riyte');
    console.log(arg);
    if (event)
        event.preventDefault();
    if (event && arg == window.location.pathname){
        console.log("return");
        return;
    }
    const newPath = arg.startsWith('/') ? arg : '/' + arg;
    window.history.pushState({}, "", newPath);
    handleLocation();
}

const routes = {
    "home/" : getHomeee,
    "login/": getLoginBox,
    "register/": getRegisterBox,
    "profile/": getProfile,
    "profile_update/": getProfileUpdate,
    "game/": getGame,
    "chat/": getChat,
    "stats/": getGameStats,
}

const loginWith42 = async (code) => {
    code = code.substring(6);
    token = getCSRFToken()
    fetch('/user/login_with_42/', {
        method: "POST",
        body: code,
        headers: {
            "X-CSRFToken": getCSRFToken()
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            reloadNavbarButtons();
            route(null, "profile/");
            console.log("registred");
        } else {
            alert(data.message);
            console.log("not registred");
        }
    })
    .catch(error => console.error("Error:", error));

}

const registerWith42 = async (code) => {
    code = code.substring(6);
    token = getCSRFToken()
    fetch('/user/register_with_42/', {
        method: "POST",
        body: code,
        headers: {
            "X-CSRFToken": getCSRFToken()
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            reloadNavbarButtons();
            route(null, "profile/");
            console.log("registred");
        } else {
            alert(data.message);
            console.log("not registred");
        }
    })
    .catch(error => console.error("Error:", error));
}

const handleLocation = async () => {
    // requete avec les socket pour le username et si il est null directement renvoyer sur la page ou faut choisir un autre username
    let path = window.location.pathname.substring(1);
    console.log("handlelocation");
    if (path.startsWith('login/')){
        let code = window.location.search;
        if (code != ''){
            loginWith42(code)
            return;
        }
    } if (path.startsWith('register/')){
        let code = window.location.search;
        if (code != ''){
            registerWith42(code)
            return;
        }
    } routes[path]();
}

window.addEventListener('DOMContentLoaded', handleLocation);

window.addEventListener('popstate', handleLocation);

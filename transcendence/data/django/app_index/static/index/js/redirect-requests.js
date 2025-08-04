function getCSRFToken() {
    const metaTag = document.querySelector('meta[name="csrf-token"]');
    return metaTag ? metaTag.content : '';
}

const triggerLogout = async () => {
    console.log("logout");
    const response = await fetch('/user/logout/')
    .then(response => response.json())
        .then(data => {
        if (data.success) {
            reloadNavbarButtons();
            route(null, "home/");
        }
    })
}

function submitLoginForm(event) {
    console.log("submit login");
    event.preventDefault(event);
    var formData = new FormData(document.querySelector('#signInForm'));

    fetch('/user/login/', {
        method: "POST",
        body: formData,
        headers: {
            "X-CSRFToken": getCSRFToken()
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            reloadNavbarButtons();
            route(null, "profile/");
            console.log("logged");
        } else {
            alert(data.message);
            console.log("not logged");
        }
    })
    .catch(error => console.error("Error:", error));
}

function submitRegisterForm(event){
    console.log("submit register");
    event.preventDefault();
    var formData = new FormData(document.querySelector('#signUpForm'));
    
    fetch('/user/register/', {
        method: "POST",
        body: formData,
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

const reloadNavbarButtons = async() => {
    try {
        const response = await fetch('/');
        const html = await response.text();

        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector('#navbar-buttons').innerHTML;
        console.log(contentText);

        document.querySelector("#navbar-buttons").innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}

const redirectFuncts = {
    "logout" : triggerLogout,
    "submitLogin" : submitLoginForm,
    "submitRegister" : submitRegisterForm,
}

const redirect = (event, arg) =>{
    event.preventDefault();
    redirectFuncts[arg](event);
}

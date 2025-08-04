
const getForm = async (element) => {
    try {
        const response = await fetch('/user/profile_update/');
        const html = await response.text();
        console.log(element)
        const tempElement = document.createElement('div');
        tempElement.innerHTML = html;

        const contentText = tempElement.querySelector(element).innerHTML;

        document.querySelector('.edit-button').innerHTML = contentText;
    } catch (error) {
        console.error('Error fetching or displaying text:', error);
    }
}

const submitForm = async (element) => {
    let form_name = element + '_form';
    let formData = new FormData(document.querySelector(form_name));

    fetch('/user/profile_update/', {
        method: "POST",
        body: formData,
        headers: {
            "X-CSRFToken": getCSRFToken()
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            reloadElement(element + '_reload');
            reloadElement('.edit-button');
            console.log("updated");
        } else {
            reloadElement(element);
            alert(data.message);
            console.log("not updated");
        }
    })

}

const reloadElement = async(element) =>{
    const response = await fetch('/user/profile/');
    const html = await response.text();

    const tempElement = document.createElement('div');
    tempElement.innerHTML = html;

    const contentText = tempElement.querySelector(element).innerHTML;

    document.querySelector(element).innerHTML = contentText;
}

const fooorms = {
    "get_username_form" : getForm,
    "get_password_form" : getForm,
    "get_bio_form" : getForm,
    "get_image_form" : getForm,
    "submit_username_form": submitForm,
    "submit_password_form" : submitForm,
    "submit_bio_form" : submitForm,
    "submit_image_form" : submitForm,
    "dismiss": reloadElement,
}

const redirForms = (arg, element) =>{
    fooorms[arg](element);
}

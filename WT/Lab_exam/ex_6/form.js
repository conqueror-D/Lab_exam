function handleSubmit(event) {
    event.preventDefault();
    var name = document.getElementById('name').value;
    var pass = document.getElementById('pass').value;
    console.log(name, pass);
    if (name === 'Juned' && pass === '123') {
        console.log("Hello")
        window.location.href = 'profile.html';
    } else {
        alert("Your wrong");
    }
}

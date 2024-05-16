let output = document.getElementById('output-val');
let btns = document.querySelectorAll('.btn');
let submitBtn = document.getElementById('submitBtn');
let dateContainer = document.getElementById('date');

let operator = null;
let isOperatorSelected = false;

function printDate() {
    let date = new Date();
    let day = date.toLocaleDateString();
    dateContainer.innerHTML = day + "<br>";
    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();
    dateContainer.innerHTML += `${hours}:${minutes}:${seconds}`;
}
setInterval(printDate, 1000);

btns.forEach((btn) => {
    btn.addEventListener('click', () => {
        isOperatorSelected = true;
        operator = btn.textContent;
        console.log(operator);
    });
})
function handleSubmit() {
    let num1 = parseInt(document.getElementById('num1').value);
    let num2 = parseInt(document.getElementById('num2').value);
    let ans = null;
    if (num1 && num2 && isOperatorSelected) {
        if (operator === '-') {
            ans = num1 - num2;
        } else if (operator === '*') {
            ans = num1 * num2;
        } else if (operator === '+') {
            ans = num1 + num2;
        } else {
            ans = num1 / num2;
        }
        output.innerText = ans;
    } else {
        alert("Please enter both the number and select an operator")
    }
}




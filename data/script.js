const form = document.getElementById("form");

async function main() {
    const response = await fetch("/settings");
    const data = await response.json();

    form.led_output.checked = data["led_output"];
    form.sound_output.checked = data["sound_output"];
    form.dash_threshold.value = data["data_threshold"];
}

window.addEventListener("DOMContentLoaded", main);

form.addEventListener('submit', function (event) {
    event.preventDefault()

    const formObject = {
        led_output: form.led_output.checked,
        sound_output: form.sound_output.checked,
        dash_threshold: Number(form.dash_threshold.value)
    };

    const jsonString = JSON.stringify(formObject, null, 2);

    console.log(jsonString)
    })
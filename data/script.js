const form = document.getElementById("form");

let currentSettings;

async function main() {
    const response = await fetch("/settings");
    currentSettings = await response.json();

    form.led_output.checked = currentSettings["led_output"];
    form.sound_output.checked = currentSettings["sound_output"];
    form.dash_threshold.value = currentSettings["dash_threshold"];
}

window.addEventListener("DOMContentLoaded", main);

form.addEventListener('submit', async function (event) {
    event.preventDefault()

    const formObject = {
        led_output: form.led_output.checked,
        sound_output: form.sound_output.checked,
        dash_threshold: Number(form.dash_threshold.value)
    };


    const jsonString = JSON.stringify(formObject, null, 2);

    if (
        formObject.led_output === currentSettings.led_output &&
        formObject.sound_output === currentSettings.sound_output &&
        formObject.dash_threshold === currentSettings.dash_threshold
    ) {
        return;
    }

    currentSettings = formObject;

    fetch("/settings", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },

        body: jsonString
    })
})
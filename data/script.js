const form = document.getElementById("form");
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
## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. **This is still just in develeopment.**

# Components
You will need:
- An ESP8266.
- A **buzzer** (preferably passive).
- An **LED**.
- A **220Ω resistor** (R1).
- A **pushbutton**.
# Setup
**1. Setup the wiring:**

|Terminal 1|Terminal 2|
|----------|----------|
|Pushbutton terminal 1|ESP8266 G|
|Pushbutton terminal 2|ESP8266 D1 **(PADDLE_PIN)**|
|Buzzer terminal 1|ESP8266 D7 **(BUZZER_PIN)**|
|Buzzer terminal 2|ESP8266 G|
|LED Anode|ESP8266 D6 **(LED_PIN)**|
|R1 terminal 1|LED Cathode|
|R1 terminal 2| ESP8266 G|
<hr>

**2. Install the firmware:**

Flash `Telegraph.ino` on your ESP8266.

Before flashing, you may change the constants in `config.h`, which control the following:
- `PADDLE_PIN` - Which pin is your paddle (pushbutton) connected to? Defaults to Pin 2.
- `BUZZER_PIN` - Which pin is your buzzer connected to? Defaults to Pin 11.
- `LED_PIN` - Which pin is your LED connected to? Defaults to Pin 10.
- `IS_BUZZER_ACTIVE` - Is your buzzer active (true) or passive (false)? Defaults to false.
- `LED_OUTPUT` - Should the led mirror your paddle? Defaults to true.
- `SOUND_OUTPUT` - Should the buzzer mirror your paddle? Defaults to true.
- `DASH_THRESHOLD` - How much milliseconds of pressing makes for a dash rather than a dot? Defaults to 150.


# Usage

## Morsing
To morse, press your paddle. Press the paddle (shorter than the `DASH_THRESHOLD`) to make a dot, and hold it (longer than the `DASH_THRESHOLD`) to make a dash. Wait at least 3 times the `DASH_THRESHOLD` in order to seperate between characters. Wait at least 7 times the `DASH_THRESHOLD` to seperate between words.


## Settings Mode
You can go into Settings Mode by morsing the word "SETTINGS".
You can exit it by clicking your paddle once.

> [!NOTE]
> This mode is for future implementation, currently it only makes the led blink.
Hope you enjoy! :3
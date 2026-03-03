## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. **This is still just in develeopment.**

# Components
You will need:
- An ESP8266.
- A **passive buzzer**.
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
1. Flash the `data` folder on your ESP8266 using LittleFS. [I recommend to use this repository for that](https://github.com/earlephilhower/arduino-littlefs-upload).

3. Flash `Telegraph.ino` on your ESP8266.

# Usage

## Morsing
To morse, press your paddle. Press the paddle (shorter than the `DASH_THRESHOLD`*) to make a dot, and hold it (longer than the `DASH_THRESHOLD`) to make a dash. Wait at least 3 times the `DASH_THRESHOLD` in order to seperate between characters. Wait at least 7 times the `DASH_THRESHOLD` to seperate between words.

*Changeable in Settings Mode.

## Settings Mode
You can go into Settings Mode by morsing the word "SETTINGS". Ther
You can exit it by clicking your paddle once.

There, you can change:
- Led Output: Should the LED mirror the paddle?
- Sound Output: Should the buzzer mirror the paddle?
- Dash Threshold - When the paddle is held for shorter than this time, it is considered a dot. When held for longer, it's considered a dash.

Hope you enjoy :3
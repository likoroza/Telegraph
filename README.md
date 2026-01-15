## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. **This is still just a demo.**

# Components
You will need:
- An **Arduino UNO R3** (or a clone).
- A **buzzer** (preferably passive)*.
- An **LED***.
- A **220Ω resistor** (R1).
- A **pushbutton**.

*Optional.

# Setup
**1. Setup the wiring:**

|Terminal 1|Terminal 2|
|----------|----------|
|Pushbutton terminal 1|Arduino GND|
|Pushbutton terminal 2|Arduino D2 **(PADDLE_PIN)**|
|Buzzer terminal 1|Arduino D11 **(BUZZER_PIN)**|
|Buzzer terminal 2|Arduino GND|
|LED Anode|Arduino D10 **(LIGHT_PIN)**|
|R1 terminal 1|LED Cathode|
|R1 terminal 2| Arduino GND|
<hr>

**2. Install the firmware:**

Flash `Telegraph.ino` on your Arduino.

Before flashing, you may change:
- `IS_BUZZER_ACTIVE` - Is your buzzer active (true) or passive (false)? Defaults to false.
- `LIGHT_OUTPUT` - Should the led mirror your paddle? Defaults to true.
- `SOUND_OUTPUT` - Should the buzzer mirror your paddle? Defaults to true.
- `DASH_THRESHOLD` - How much milliseconds of pressing makes for a dash rather than a dot? Defaults to 150.
- `dealWithCharacter()` implementation - What should the code do with the character once it finishes?


# Usage

## Morsing
To morse, click your paddle. Make a short click (under the `DASH_THRESHOLD`) to make a dot, and make a long click (above the `DASH_THRESHOLD`) to make a dash. Wait at least 3 times the `DASH_THRESHOLD` in order to seperate between characters. Wait at least 7 times the `DASH_THRESHOLD` to seperate between words.


## Settings Mode
You can go into Settings Mode by morsing the word (SETTINGS).
You can exit it by clicking your paddle once.

> [!NOTE]
> This mode is for future implementation, currently it only makes the led blink.

Hope you enjoy! :3
## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. This is still a demo.

# Components
You will need:
- An **Arduino UNO R3** (or a clone).
- A ***passive* buzzer.***
- An **LED.***
- A **220Ω resisor** (R1).
- A **pushbutton.**

*Optional.

## Setup
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
- `LIGHT_OUTPUT` - Should the led mirror your paddle?
- `SOUND_OUTPUT` - Should the buzzer mirror your paddle?
- `DASH_THRESHOLD` - How much milliseconds of pressing makes for a dash rather than a dot?
- `dealWithCharacter()` implemntation - What should the code do with the character once it finishes?

Hope you enjoy! :3
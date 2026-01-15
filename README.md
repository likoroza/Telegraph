## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. This is still a demo.

# Components
You will need:
- An **Arduino UNO R3** (or a clone).
- A ***passive* buzzer.**
- A pushbutton.

## Setup
**1. Setup the wiring:**

|Terminal 1|Terminal 2|
|----------|----------|
|Buzzer terminal 1|Arduino D11 **(BUZZER_PIN)**|
|Buzzer terminal 2|Arduino GND|
|Pushbutton terminal 1|Arduino GND|
|Pushbutton terminal 2|Arduino D2 **(PADDLE_PIN)**|
<hr>

**2. Install the firmware:**

Flash `Telegraph.ino` on your Arduino.
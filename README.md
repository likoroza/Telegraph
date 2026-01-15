## Telegraph

# Inroduction
This is a "telegraph" project used to communicate Morse Code between devices. This is still a demo.

# Components
You will need:
- An **Arduino UNO R3** (or a clone).
- An ***Active* buzzer.**
- A TTP223 touch sensor.

## Setup
**1. Setup the wiring:**

|Terminal 1|Terminal 2|
|----------|----------|
|Buzzer anode|Arduino D11 **(BUZZER_PIN)**|
|Buzzer cathode|Arduino GND|
|TTP223 VCC|Arduino 5V|
|TTP223 I/O|Arduino D2 **(PADDLE_PIN)**
|TTP223 GND|Arduino GND|

<hr>

**2. Install the firmware:**

Flash `Telegraph.ino` on your Arduino.
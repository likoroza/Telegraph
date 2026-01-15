int PADDLE_PIN = 2;
int BUZZER_PIN = 11; 

int start_press;

void setup()
{
	pinMode(PADDLE_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    bool padelState = !digitalRead(PADDLE_PIN);
    buzz(padelState);
}

void buzz(bool state) {
    if (state) {
        tone(BUZZER_PIN, 600);
    }

    else {
        noTone(BUZZER_PIN);
    }
}
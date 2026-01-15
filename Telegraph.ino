int PADDLE_PIN = 2;
int BUZZER_PIN = 11; 


void setup()
{
	pinMode(PADDLE_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    digitalWrite(BUZZER_PIN, digitalRead(PADDLE_PIN));
}

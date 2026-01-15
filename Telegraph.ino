int PADDLE_PIN = 2;
int BUZZER_PIN = 11; 
int LIGHT_PIN = 10;

bool LIGHT_OUTPUT = true;
bool SOUND_OUTPUT = true;
int DASH_THRESHOLD = 150;

int time_at_state_start;
bool is_measuring_pressed = false; 

String currentCharacter;

void setup()
{
	pinMode(PADDLE_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LIGHT_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    bool paddleState = !digitalRead(PADDLE_PIN);
    
    if (SOUND_OUTPUT)
    {
        buzz(paddleState);
    }
    

    if (LIGHT_OUTPUT) {
        digitalWrite(LIGHT_PIN, paddleState);
    }

    if (paddleState && !is_measuring_pressed) {
        time_at_state_start = millis();
        is_measuring_pressed = true;
    }

    if (!paddleState) {
        int stateTime = millis() - time_at_state_start;

        if (is_measuring_pressed) {

            currentCharacter += stateTime < DASH_THRESHOLD ? "." : "-";
            delay(1);

            is_measuring_pressed = false;
            time_at_state_start = millis();
            return;
        }

        if (stateTime >= (DASH_THRESHOLD * 3) && currentCharacter != "") {
            dealWithCharacter(currentCharacter);
            currentCharacter = "";
        }
        
    }
}

void buzz(bool state) {
    if (state) {
        tone(BUZZER_PIN, 600);
    }

    else {
        noTone(BUZZER_PIN);
    }
}

void dealWithCharacter(String currentCharacter) {
    //TODO: Implement method
}
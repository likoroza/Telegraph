int PADDLE_PIN = 2;
int BUZZER_PIN = 11; 
int LED_PIN = 10;

bool IS_BUZZER_ACTIVE = false;

bool LED_OUTPUT = true;
bool SOUND_OUTPUT = true;

int DASH_THRESHOLD = 150;

int time_at_state_start;
bool is_measuring_pressed = false; 

String currentCharacter;
int currentCodeProgress = 0;

String SETTINGS_MODE_CODE[] = {"...", ".", "-", "-", "..", "-.", "--.", "..."};

void setup()
{
	pinMode(PADDLE_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    bool paddleState = !digitalRead(PADDLE_PIN);
    
    if (SOUND_OUTPUT)
    {
        buzz(paddleState);
    }
    

    if (LED_OUTPUT) {
        digitalWrite(LED_PIN, paddleState);
    }

    if (paddleState && !is_measuring_pressed) {
        time_at_state_start = millis();
        is_measuring_pressed = true;
    }

    if (!paddleState) {
        int stateTime = millis() - time_at_state_start;

        if (is_measuring_pressed) {

            currentCharacter += stateTime < DASH_THRESHOLD ? "." : "-";
            delay(5);

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
    if (IS_BUZZER_ACTIVE) {
        digitalWrite(BUZZER_PIN, state);
        return;
    }

    if (state) {
        tone(BUZZER_PIN, 600);
    }

    else {
        noTone(BUZZER_PIN);
    }
}

void dealWithCharacter(String currentCharacter) {
    //TODO: Implement method
    Serial.println(currentCharacter);

    if (currentCodeProgress == sizeof(SETTINGS_MODE_CODE)/ sizeof(SETTINGS_MODE_CODE[0]) -1) {
        currentCodeProgress = 0;
        settingsMode();
        return;
    }

    if (SETTINGS_MODE_CODE[currentCodeProgress] == currentCharacter) {
        currentCodeProgress++;
        return;
    }
    currentCodeProgress = 0;
}

void settingsMode() {    
    unsigned long lastBlinkTime;
    bool ledState = true;

    while (digitalRead(PADDLE_PIN)) // Button is not pressed
    {
        if (millis() - lastBlinkTime >= 500) {
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
            lastBlinkTime = millis();
        }
        
    }
    // Button is pressed   
    while (!digitalRead(PADDLE_PIN)) { /// Button is held
        
    }

    // Button is released
}
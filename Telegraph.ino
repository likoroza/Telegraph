#include "config.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>    

int time_at_state_start;
bool is_measuring_pressed = false;

ESP8266WebServer server(80);
String currentCharacter;
int currentCodeProgress = 0;

String SETTINGS_MODE_CODE[] = {"...", ".", "-", "-", "..", "-.", "--.", "..."};

void setup()
{
	pinMode(PADDLE_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    
    intro(1);

    LittleFS.begin();
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

void handleSettingsRoot() {
    File htmlFile = LittleFS.open("/main.html", "r");
    if (!htmlFile) {
        server.send(404, "text/plain", "File not found!");
    }


    File cssFile = LittleFS.open("/styles.css", "r");
    if (!cssFile) {
        Serial.println("CSS file not found!");
    }


    File jsFile = LittleFS.open("/script.js", "r");
    if (!jsFile) {
        Serial.println("JS file not found!");
    }

    String html = htmlFile.readString();

    html.replace("/*INSERT CSS CODE*/", cssFile.readString());
    html.replace("<!--INSERT JS CODE-->", jsFile.readString());

    server.send(200, "text/html", html);

    htmlFile.close();
    cssFile.close();
    jsFile.close();
}

void handleSettingsJsonGet() {
    File settingsFile = LittleFS.open("/settings.json", "r");
    if (!settingsFile) {
        server.send(404, "text/plain", "File not found!");
    }

    server.streamFile(settingsFile, "application/json");
}

void handleSettingsJsonPost() {
    if (!server.hasArg("plain")) {
        server.send(400, "text/plain", "There is no JSON file!");
    }

    File settingsFile = LittleFS.open("/settings.json", "w");
    if (!settingsFile) {
        Serial.println("No file!");
        return;
    }

    const String body = server.arg("plain");
    
    settingsFile.print(body);

    settingsFile.close();
}

void settingsMode() { 
    unsigned long lastBlinkTime;
    bool ledState = true;

    WiFi.softAP("Telegraph");

    server.on("/", handleSettingsRoot);
    server.on("/settings", HTTP_GET, handleSettingsJsonGet);
    server.on("/settings", HTTP_POST, handleSettingsJsonPost);
    
    server.begin();

    

    while (digitalRead(PADDLE_PIN)) // Button is not pressed
    {
        yield();

        if (millis() - lastBlinkTime >= 500) {
            ledState = !ledState;
            digitalWrite(LED_PIN, ledState);
            lastBlinkTime = millis();
        }

        server.handleClient();
    }
    // Button is pressed   
    while (!digitalRead(PADDLE_PIN)) { /// Button is held
        
    }

    // Button is released
    WiFi.softAPdisconnect(true);
    server.stop();
}

void updateConfig() {

}

void intro(int speed) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 160*2, 1000 / speed);
    delay(500 / speed);
    tone(BUZZER_PIN, 180*2, 250 / speed);
    delay(250 / speed);
    tone(BUZZER_PIN, 190*2, 250 / speed);
    delay(250 / speed);
    tone(BUZZER_PIN, 180*2, 500 / speed);
    delay(500 / speed);
    tone(BUZZER_PIN, 240*2, 500 / speed);
    delay(500 / speed);
    digitalWrite(LED_PIN, LOW);
}
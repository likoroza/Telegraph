#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

const uint8_t PADDLE_PIN = D1;
const uint8_t BUZZER_PIN = D7; 
const uint8_t LED_PIN = D6;

const bool IS_BUZZER_ACTIVE = false;

const bool LED_OUTPUT = true;
const bool SOUND_OUTPUT = true;

const unsigned long DASH_THRESHOLD = 150;

#endif // CONFIG_H
#include <Arduino.h>
#include "Led.h"

Led::Led() {
}

Led::~Led() {
}

void Led::init() {    
    pinMode(LED_RED, OUTPUT);
}

void Led::on() {
    digitalWrite(LED_RED, HIGH);
}

void Led::off() {
    digitalWrite(LED_RED, LOW);
}
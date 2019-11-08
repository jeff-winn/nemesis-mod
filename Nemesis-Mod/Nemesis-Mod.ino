#include "src/App.h"
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);

    Serial.println("Connected!");

    MainApp.init();
}

void loop() {
    MainApp.run();
}
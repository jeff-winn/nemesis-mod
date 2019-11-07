#include "src/App.h"
#include <Arduino.h>

App app = App();

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);

    Serial.println("Connected!");

    app.init();
}

void loop() {
    app.run();
}
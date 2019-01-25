#include <Arduino.h>
#include "src/App.h"

App* app;

void setup() {
    app = new App();
    app->init();
}

void loop() {
    app->run();
}
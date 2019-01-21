#include "Nemesis-Mod.h"
#include "App.h"

App* app;

void setup() {
    app = new App();
    app->init();
}

void loop() {
    app->run();
}
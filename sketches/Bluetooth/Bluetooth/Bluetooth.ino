#include "src/App.h"

App app = App();

void setup() {    
    app.init();
}

void loop() {
    app.runOnce();
}
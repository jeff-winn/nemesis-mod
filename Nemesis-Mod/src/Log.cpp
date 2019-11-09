#include <Arduino.h>
#include "Log.h"

Logger Log = Logger();

void Logger::println(const char value[]) {
#ifndef __RELEASE__
    Serial.println(value);
#endif
}

void Logger::waitForUsbConnection() {
#ifndef __RELEASE__
    Serial.begin(115200);
    
    while (!Serial) {
        delay(10);
    }

    _connected = true;
    println("Connected!\n");
#endif
}
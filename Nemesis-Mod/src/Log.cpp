#include <Arduino.h>
#include "Log.h"

Logger Log = Logger();

#define size_of_array(type) (char *)(&type+1)-(char*)(&type)

void Logger::println(const int value) {
#ifndef __RELEASE__
    Serial.println(value);
#endif
}

void Logger::println(const uint8_t value) {
#ifndef __RELEASE__
    Serial.println(value);
#endif
}

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

    println("Connected!\n");
#endif
}
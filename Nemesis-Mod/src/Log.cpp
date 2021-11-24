#include <Arduino.h>
#include "Log.h"

Logger Log = Logger();

#define size_of_array(type) (char *)(&type+1)-(char*)(&type)

void Logger::println(const float value, const int precision) {
#ifdef __ENABLE_LOGGING__
    Serial.println(value, precision);
#endif
}

void Logger::println(const uint32_t value) {
#ifdef __ENABLE_LOGGING__
    Serial.println(value);
#endif
}

void Logger::println(const char value[]) {
#ifdef __ENABLE_LOGGING__
    Serial.println(value);
#endif
}
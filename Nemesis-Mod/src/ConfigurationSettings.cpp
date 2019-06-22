#include "ConfigurationSettings.h"

ConfigurationSettings::ConfigurationSettings(Adafruit_FRAM_I2C* fram) {
    m_fram = fram;
}

void ConfigurationSettings::init() {
    m_fram->begin();
}
#include "ConfigurationSettings.h"

ConfigurationSettings::ConfigurationSettings(Adafruit_FRAM_I2C* fram) {
    m_fram = fram;
}

ConfigurationSettings::~ConfigurationSettings() {
    m_fram = NULL;
}

void ConfigurationSettings::init() {
    m_fram->begin();
}

int ConfigurationSettings::getFeedNormalSpeed() {
    return 100;
}

int ConfigurationSettings::getFeedHighSpeed() {
    return 175;
}

int ConfigurationSettings::getFeedMaxSpeed() {
    return 400;
}

int ConfigurationSettings::getFlywheelNormalSpeed() {
    return 125;
}

int ConfigurationSettings::getFlywheelMediumSpeed() {
    return 250;
}

int ConfigurationSettings::getFlywheelMaxSpeed() {
    return 400;
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return 0.1;
}
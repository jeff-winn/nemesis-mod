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

void ConfigurationSettings::reset() {
    setFeedNormalSpeed(100);
    setFeedHighSpeed(175);
    setFeedMaxSpeed(400);

    setFlywheelNormalSpeed(125);
    setFlywheelMediumSpeed(250);
    setFlywheelMaxSpeed(400);
    setFlywheelTrimVariance(0.1F);
}

int ConfigurationSettings::getFeedNormalSpeed() {
    return 100;
}

void ConfigurationSettings::setFeedNormalSpeed(int value) {    
}

int ConfigurationSettings::getFeedHighSpeed() {
    return 175;
}

void ConfigurationSettings::setFeedHighSpeed(int value) {
}

int ConfigurationSettings::getFeedMaxSpeed() {
    return 400;
}

void ConfigurationSettings::setFeedMaxSpeed(int value) {    
}

int ConfigurationSettings::getFlywheelNormalSpeed() {
    return 125;
}

void ConfigurationSettings::setFlywheelNormalSpeed(int value) {
}

int ConfigurationSettings::getFlywheelMediumSpeed() {
    return 250;
}

void ConfigurationSettings::setFlywheelMediumSpeed(int value) {    
}

int ConfigurationSettings::getFlywheelMaxSpeed() {
    return 400;
}

void ConfigurationSettings::setFlywheelMaxSpeed(int value) {
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return 0.1F;
}

void ConfigurationSettings::setFlywheelTrimVariance(float value) {    
}
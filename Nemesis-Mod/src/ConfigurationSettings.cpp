#include "ConfigurationSettings.h"
#include "BitConverter.h"

const short FEED_NORMAL_SPEED_ADDR = 0x04;
const short FEED_HIGH_SPEED_ADDR = 0x08;
const short FEED_MAX_SPEED_ADDR = 0x12;
const short FLYWHEEL_NORMAL_SPEED_ADDR = 0x16;
const short FLYWHEEL_MEDIUM_SPEED_ADDR = 0x20;
const short FLYWHEEL_MAX_SPEED_ADDR = 0x24;

ConfigurationSettings::ConfigurationSettings(Adafruit_FRAM_I2C* fram) {
    m_fram = fram;
}

ConfigurationSettings::~ConfigurationSettings() {
    m_fram = NULL;
}

void ConfigurationSettings::init() {
    m_fram->begin();

    if (!initialized()) {
        defaultSettings();
        setInitialized(true);
    }
}

bool ConfigurationSettings::initialized() {
    return m_fram->read8(0x0) != 0;
}

void ConfigurationSettings::setInitialized(bool value) {
    m_fram->write8(0x0, (value ? 0xFF : 0x00));
}

void ConfigurationSettings::defaultSettings() {
    setFeedNormalSpeed(100);
    setFeedHighSpeed(175);
    setFeedMaxSpeed(400);

    setFlywheelNormalSpeed(125);
    setFlywheelMediumSpeed(250);
    setFlywheelMaxSpeed(400);
}

int ConfigurationSettings::getFeedNormalSpeed() {
    return readInt32(FEED_NORMAL_SPEED_ADDR);
}

void ConfigurationSettings::setFeedNormalSpeed(int value) {
    writeInt32(FEED_NORMAL_SPEED_ADDR, value);
}

int ConfigurationSettings::getFeedHighSpeed() {
    return readInt32(FEED_HIGH_SPEED_ADDR);
}

void ConfigurationSettings::setFeedHighSpeed(int value) {
    writeInt32(FEED_HIGH_SPEED_ADDR, value);
}

int ConfigurationSettings::getFeedMaxSpeed() {
    return readInt32(FEED_MAX_SPEED_ADDR);
}

void ConfigurationSettings::setFeedMaxSpeed(int value) {    
    writeInt32(FEED_MAX_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelNormalSpeed() {
    return readInt32(FLYWHEEL_NORMAL_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelNormalSpeed(int value) {
    writeInt32(FLYWHEEL_NORMAL_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelMediumSpeed() {
    return readInt32(FLYWHEEL_MEDIUM_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelMediumSpeed(int value) {    
    writeInt32(FLYWHEEL_MEDIUM_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelMaxSpeed() {
    return readInt32(FLYWHEEL_MAX_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelMaxSpeed(int value) {
    return writeInt32(FLYWHEEL_MAX_SPEED_ADDR, value);
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return 0.1F;
}

int ConfigurationSettings::readInt32(short address) {
    byte raw[4];

    for (auto index = 0; index < 4; index++) {
        raw[index] = m_fram->read8(address + index);
    }

    return Convert.toInt32(raw);
}

void ConfigurationSettings::writeInt32(short address, int value) {
    byte* raw = Convert.toByteArray(value);

    for (auto index = 0; index < 4; index++) {
        m_fram->write8(address + index, raw[index]);
    }

    delete[] raw;
}
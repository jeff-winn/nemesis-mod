#include "ConfigurationSettings.h"
#include "BitConverter.h"

const short FEED_NORMAL_SPEED_ADDR = 0x04;
const short FEED_HIGH_SPEED_ADDR = 0x08;
const short FEED_MAX_SPEED_ADDR = 0x12;
const short FLYWHEEL_NORMAL_SPEED_ADDR = 0x16;
const short FLYWHEEL_MEDIUM_SPEED_ADDR = 0x20;
const short FLYWHEEL_MAX_SPEED_ADDR = 0x24;
const short FLYWHEEL_TRIM_VARIANCE_ADDR = 0x28;
const short FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR = 0x32;
const short FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR = 0x36;

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
    setFlywheelTrimVariance(0.1F);
    setFlywheelM1TrimAdjustment(1.0F);
    setFlywheelM2TrimAdjustment(1.0F);
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
    writeInt32(FLYWHEEL_MAX_SPEED_ADDR, value);
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return readFloat(FLYWHEEL_TRIM_VARIANCE_ADDR);
}

void ConfigurationSettings::setFlywheelTrimVariance(float value) {
    writeFloat(FLYWHEEL_TRIM_VARIANCE_ADDR, value);
}

float ConfigurationSettings::getFlywheelM1TrimAdjustment() {
    return readFloat(FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR);
}

void ConfigurationSettings::setFlywheelM1TrimAdjustment(float value) {
    writeFloat(FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR, value);
}

float ConfigurationSettings::getFlywheelM2TrimAdjustment() {
    return readFloat(FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR);
}

void ConfigurationSettings::setFlywheelM2TrimAdjustment(float value) {
    writeFloat(FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR, value);
}

int ConfigurationSettings::readInt32(short address) {
    byte raw[4];

    for (auto index = 0; index < 4; index++) {
        raw[index] = m_fram->read8(address + index);
    }

    return Convert.toInt32(raw);
}

void ConfigurationSettings::writeInt32(short address, int value) {
    byte* raw = Convert.toInt32Array(value);

    for (auto index = 0; index < 4; index++) {
        m_fram->write8(address + index, raw[index]);
    }

    delete[] raw;
}

float ConfigurationSettings::readFloat(short address) {
    byte raw[4];

    for (auto index = 0; index < 4; index++) {
        raw[index] = m_fram->read8(address + index);
    }

    return Convert.toFloat(raw);
}

void ConfigurationSettings::writeFloat(short address, float value) {
    byte* raw = Convert.toFloatArray(value);

    for (auto index = 0; index < 4; index++) {
        m_fram->write8(address + index, raw[index]);
    }

    delete[] raw;
}
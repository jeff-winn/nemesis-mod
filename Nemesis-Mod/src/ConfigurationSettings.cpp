#include <Adafruit_FRAM_I2C.h>
#include "ConfigurationSettings.h"
#include "BitConverter.h"
#include "Log.h"

const short OPERATOR_TOKEN_LENGTH_ADDR = 0x10;
const short OPERATOR_TOKEN_ADDR = 0x11;
const short FEED_NORMAL_SPEED_ADDR = 0x100;
const short FEED_HIGH_SPEED_ADDR = 0x104;
const short FEED_MAX_SPEED_ADDR = 0x108;
const short FLYWHEEL_NORMAL_SPEED_ADDR = 0x112;
const short FLYWHEEL_MEDIUM_SPEED_ADDR = 0x116;
const short FLYWHEEL_MAX_SPEED_ADDR = 0x120;
const short FLYWHEEL_TRIM_VARIANCE_ADDR = 0x124;
const short FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR = 0x128;
const short FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR = 0x132;

ConfigurationSettings Settings = ConfigurationSettings();

// Defines the FRAM module for persistent data storage.
Adafruit_FRAM_I2C framDriver = Adafruit_FRAM_I2C();

void ConfigurationSettings::init() {
    framDriver.begin();

    if (!initialized()) {
        defaultSettings();
        resetAuthenticationToken();

        setInitialized(true);
    }
}

bool ConfigurationSettings::initialized() {
    return framDriver.read8(0x1) != 0;
}

void ConfigurationSettings::setInitialized(bool value) {
    framDriver.write8(0x1, (value ? 0xFF : 0x00));
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

    Log.println("Configuration settings reset to defaults.");
}

void ConfigurationSettings::clear() {
    for (int addr = 0; addr < 32000; addr++) {
        framDriver.write8(addr, 0x00);
    }
}

// AuthenticationToken_t ConfigurationSettings::getAuthenticationToken() {
//     AuthenticationToken_t result;

//     result.length = framDriver.read8(OPERATOR_TOKEN_LENGTH_ADDR);
//     if (result.length > 0) {
//         result.data = new byte[result.length];

//         for (byte index = 0; index < result.length; index++) {
//             result.data[index] = framDriver.read8(OPERATOR_TOKEN_ADDR + index);
//         }
//     }

//     return result;
// }

// void ConfigurationSettings::setAuthenticationToken(AuthenticationToken_t token) {
//     framDriver.write8(OPERATOR_TOKEN_ADDR, token.length);

//     for (byte index = 0; index < token.length; index++) {
//         framDriver.write8(OPERATOR_TOKEN_ADDR + index, token.data[index]);
//     }
// }

void ConfigurationSettings::resetAuthenticationToken() {
    for (uint16_t addr = OPERATOR_TOKEN_ADDR; addr < FEED_NORMAL_SPEED_ADDR; addr++) {
        framDriver.write8(addr, 0x00);
    }
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
        raw[index] = framDriver.read8(address + index);
    }

    return Convert.toInt32(raw);
}

void ConfigurationSettings::writeInt32(short address, int value) {
    byte* raw = Convert.toInt32Array(value);

    for (auto index = 0; index < 4; index++) {
        framDriver.write8(address + index, raw[index]);
    }

    delete[] raw;
}

float ConfigurationSettings::readFloat(short address) {
    byte raw[4];

    for (auto index = 0; index < 4; index++) {
        raw[index] = framDriver.read8(address + index);
    }

    return Convert.toFloat(raw);
}

void ConfigurationSettings::writeFloat(short address, float value) {
    byte* raw = Convert.toFloatArray(value);

    for (auto index = 0; index < 4; index++) {
        framDriver.write8(address + index, raw[index]);
    }

    delete[] raw;
}
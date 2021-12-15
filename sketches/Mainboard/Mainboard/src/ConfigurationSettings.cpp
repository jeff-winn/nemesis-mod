#include "ConfigurationSettings.h"
#include "shared/BitConverter.h"
#include "SdCard.h"

ConfigurationSettings Settings = ConfigurationSettings();

String readStringFromIni(const char* section, const char* key, const IniFile& ini) {
    const size_t len = 256;
    char buffer[len];

    ini.getValue(section, key, buffer, len);

    return String(buffer);
}

ConfigurationSettings::ConfigurationSettings() {
}

ConfigurationSettings::~ConfigurationSettings() {
}

void ConfigurationSettings::init() {
    Sdc.init();

    auto file = Sdc.openIni();
    m_pin = readStringFromIni("bluetooth", "pin", file);

    file.close();

    // if (!initialized()) {
    //     defaultSettings();
    //     resetAuthenticationToken();

    //     setInitialized(true);
    // }
}

bool ConfigurationSettings::initialized() {
    return true;

    // return framDriver.read(0x1) != 0;
}

void ConfigurationSettings::setInitialized(bool value) {
    // framDriver.write(0x1, (value ? 0xFF : 0x00));
}

void ConfigurationSettings::defaultSettings() {
    // setExistingPairing(false);
    // setIsHopperLockEnabled(true);

    // setFeedNormalSpeed(100);
    // setFeedMediumSpeed(175);
    // setFeedMaxSpeed(400);

    // setFlywheelKidSpeed(195);
    // setFlywheelNormalSpeed(215);
    // setFlywheelLudicrousSpeed(400);
    // setFlywheelTrimVariance(0.1F);
    // setFlywheelM1TrimAdjustment(1.0F);
    // setFlywheelM2TrimAdjustment(1.0F);
}

void ConfigurationSettings::clear() {
    // for (int addr = 0; addr < 32000; addr++) {
    //     framDriver.write(addr, 0x00);
    // }
}

const char* ConfigurationSettings::getPairingPin() {
    return m_pin.c_str();
}

bool ConfigurationSettings::hasExistingPairing() {
    return false;
    
    // return framDriver.read(HAS_EXISTING_PAIRING_ADDR) != 0x00;
}

void ConfigurationSettings::setExistingPairing(bool value) {
    // uint8_t raw = 0x00;
    // if (value) {
    //     raw = 0xFF;
    // }

    // framDriver.write(HAS_EXISTING_PAIRING_ADDR, raw);
}

void ConfigurationSettings::resetAuthenticationToken() {
    // for (uint16_t addr = OPERATOR_TOKEN_ADDR; addr < FEED_NORMAL_SPEED_ADDR; addr++) {
    //     framDriver.write(addr, 0x00);
    // }
}

int ConfigurationSettings::getFeedNormalSpeed() {
    return 1;

    // return readInt32(FEED_NORMAL_SPEED_ADDR);
}

void ConfigurationSettings::setFeedNormalSpeed(int value) {
    // writeInt32(FEED_NORMAL_SPEED_ADDR, value);
}

int ConfigurationSettings::getFeedMediumSpeed() {
    return 2;

    // return readInt32(FEED_MEDIUM_SPEED_ADDR);
}

void ConfigurationSettings::setFeedMediumSpeed(int value) {
    // writeInt32(FEED_MEDIUM_SPEED_ADDR, value);
}

int ConfigurationSettings::getFeedMaxSpeed() {
    return 3;

    // return readInt32(FEED_MAX_SPEED_ADDR);
}

void ConfigurationSettings::setFeedMaxSpeed(int value) {    
    // writeInt32(FEED_MAX_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelKidSpeed() {
    return 4;

    // return readInt32(FLYWHEEL_KID_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelKidSpeed(int value) {
    // writeInt32(FLYWHEEL_KID_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelNormalSpeed() {
    return 5;

    // return readInt32(FLYWHEEL_NORMAL_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelNormalSpeed(int value) {    
    // writeInt32(FLYWHEEL_NORMAL_SPEED_ADDR, value);
}

int ConfigurationSettings::getFlywheelLudicrousSpeed() {
    return 6;

    // return readInt32(FLYWHEEL_LUDICROUS_SPEED_ADDR);
}

void ConfigurationSettings::setFlywheelLudicrousSpeed(int value) {
    // writeInt32(FLYWHEEL_LUDICROUS_SPEED_ADDR, value);
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return 7.0F;

    // return readFloat(FLYWHEEL_TRIM_VARIANCE_ADDR);
}

void ConfigurationSettings::setFlywheelTrimVariance(float value) {
    // writeFloat(FLYWHEEL_TRIM_VARIANCE_ADDR, value);
}

float ConfigurationSettings::getFlywheelM1TrimAdjustment() {
    return 8.0F;

    // return readFloat(FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR);
}

void ConfigurationSettings::setFlywheelM1TrimAdjustment(float value) {
    // writeFloat(FLYWHEEL_M1_TRIM_ADJUSTMENT_ADDR, value);
}

float ConfigurationSettings::getFlywheelM2TrimAdjustment() {
    return 9.0F;
    
    // return readFloat(FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR);
}

void ConfigurationSettings::setFlywheelM2TrimAdjustment(float value) {
    // writeFloat(FLYWHEEL_M2_TRIM_ADJUSTMENT_ADDR, value);
}

bool ConfigurationSettings::isHopperLockEnabled() {
    return true;

    // return readBool(IS_HOPPER_LOCK_ENABLED_ADDR);
}

void ConfigurationSettings::setIsHopperLockEnabled(bool value) {
    // writeBool(IS_HOPPER_LOCK_ENABLED_ADDR, value);
}

bool ConfigurationSettings::readBool(short address) {
    return true;

    // auto value = readInt32(address);
    // return value != 0;
}

void ConfigurationSettings::writeBool(short address, bool value) {
    // uint32_t rawValue = 0;
    // if (value) {
    //     rawValue = 1;
    // }

    // writeInt32(address, rawValue);
}

int ConfigurationSettings::readInt32(short address) {
    return 0;

    // byte raw[4];

    // for (auto index = 0; index < 4; index++) {
    //     raw[index] = framDriver.read(address + index);
    // }

    // return Convert.toInt32(raw);
}

void ConfigurationSettings::writeInt32(short address, int value) {
    // byte* raw = Convert.toInt32Array(value);

    // for (auto index = 0; index < 4; index++) {
    //     framDriver.write(address + index, raw[index]);
    // }

    // delete[] raw;
}

float ConfigurationSettings::readFloat(short address) {
    return 0.0F;

    // byte raw[4];

    // for (auto index = 0; index < 4; index++) {
    //     raw[index] = framDriver.read(address + index);
    // }

    // return Convert.toFloat(raw);
}

void ConfigurationSettings::writeFloat(short address, float value) {
    // byte* raw = Convert.toFloatArray(value);

    // for (auto index = 0; index < 4; index++) {
    //     framDriver.write(address + index, raw[index]);
    // }

    // delete[] raw;
}
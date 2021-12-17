#include "ConfigurationSettings.h"
#include "shared/BitConverter.h"
#include "SdCard.h"

ConfigurationSettings Settings = ConfigurationSettings();

ConfigurationSettings::ConfigurationSettings() {
}

ConfigurationSettings::~ConfigurationSettings() {
}

void ConfigurationSettings::init() {
    Sdc.init();

    auto config = Sdc.readConfig();
    m_name = String(config["name"].as<const char*>());
    
    auto bluetooth = config["bluetooth"];
    if (bluetooth != NULL) {
        m_pin = String(bluetooth["pin"].as<const char*>());
        m_isBluetoothEnabled = bluetooth["enabled"].as<bool>();
    }
    
    auto defaults = config["defaults"];
    if (defaults != NULL) {
        unsigned int flywheelTrimVariance = defaults["flywheelTrimVariance"].as<unsigned int>();
        m_flywheelTrimVariance = flywheelTrimVariance / 100;

        unsigned int flywheel1TrimAdjustment = defaults["flywheel1TrimAdjustment"].as<unsigned int>();
        m_flywheel1TrimAdjustment = flywheel1TrimAdjustment / 100;

        unsigned int flywheel2TrimAdjustment = defaults["flywheel2TrimAdjustment"].as<unsigned int>();
        m_flywheel2TrimAdjustment = flywheel2TrimAdjustment / 100;
        m_isMagLockEnabled = defaults["maglock"].as<bool>();

        m_pusherSpeed = parsePusherSpeed(defaults["pusher"].as<const char*>());
        m_flywheelSpeed = parseFlywheelSpeed(defaults["flywheels"].as<const char*>());
    }

    auto pusher = config["pusher"];
    if (pusher != NULL) {
        m_pusherLow = pusher["low"].as<unsigned int>();
        m_pusherNormal = pusher["normal"].as<unsigned int>();
        m_pusherMax = pusher["max"].as<unsigned int>();
    }

    auto flywheels = config["flywheels"];
    if (flywheels != NULL) {
        m_flywheelsLow = flywheels["low"].as<unsigned int>();
        m_flywheelsNormal = flywheels["normal"].as<unsigned int>();
        m_flywheelsMax = flywheels["max"].as<unsigned int>();
    }
}

FlywheelSpeed ConfigurationSettings::parseFlywheelSpeed(const char* value) {
    if (value == "low") {
        return FlywheelSpeed::Low;
    }

    if (value == "max") {
        return FlywheelSpeed::Max;
    }

    return FlywheelSpeed::Normal;
}

BeltSpeed ConfigurationSettings::parsePusherSpeed(const char* value) {
    if (value == "low") {
        return BeltSpeed::Low;
    }

    if (value == "max") {
        return BeltSpeed::Max;
    }

    return BeltSpeed::Normal;
}

const char* ConfigurationSettings::getName() {
    return m_name.c_str();
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

FlywheelSpeed ConfigurationSettings::getFlywheelSpeed() {
    return m_flywheelSpeed;
}

void ConfigurationSettings::setFlywheelSpeed(FlywheelSpeed value) {
    m_flywheelSpeed = value;
}

BeltSpeed ConfigurationSettings::getPusherSpeed() {
    return m_pusherSpeed;
}

void ConfigurationSettings::setPusherSpeed(BeltSpeed value) {
    m_pusherSpeed = value;
}

void ConfigurationSettings::resetAuthenticationToken() {
    // for (uint16_t addr = OPERATOR_TOKEN_ADDR; addr < FEED_NORMAL_SPEED_ADDR; addr++) {
    //     framDriver.write(addr, 0x00);
    // }
}

int ConfigurationSettings::getFeedLowSpeed() {
    return m_pusherLow;
}

void ConfigurationSettings::setFeedLowSpeed(int value) {
    m_pusherLow = value;
}

int ConfigurationSettings::getFeedNormalSpeed() {
    return m_pusherNormal;
}

void ConfigurationSettings::setFeedNormalSpeed(int value) {
    m_pusherNormal = value;
}

int ConfigurationSettings::getFeedMaxSpeed() {
    return m_pusherMax;
}

void ConfigurationSettings::setFeedMaxSpeed(int value) {    
    m_pusherMax = value;
}

int ConfigurationSettings::getFlywheelLowSpeed() {
    return m_flywheelsLow;
}

void ConfigurationSettings::setFlywheelLowSpeed(int value) {
    m_flywheelsLow = value;
}

int ConfigurationSettings::getFlywheelNormalSpeed() {
    return m_flywheelsNormal;
}

void ConfigurationSettings::setFlywheelNormalSpeed(int value) {    
    m_flywheelsNormal = value;
}

int ConfigurationSettings::getFlywheelMaxSpeed() {
    return m_flywheelsMax;
}

void ConfigurationSettings::setFlywheelMaxSpeed(int value) {
    m_flywheelsMax = value;
}

float ConfigurationSettings::getFlywheelTrimVariance() {
    return m_flywheelTrimVariance;
}

void ConfigurationSettings::setFlywheelTrimVariance(float value) {
    m_flywheelTrimVariance = value;
}

float ConfigurationSettings::getFlywheelM1TrimAdjustment() {
    return m_flywheel1TrimAdjustment;
}

void ConfigurationSettings::setFlywheelM1TrimAdjustment(float value) {
    m_flywheel1TrimAdjustment = value;
}

float ConfigurationSettings::getFlywheelM2TrimAdjustment() {
    return m_flywheel2TrimAdjustment;
}

void ConfigurationSettings::setFlywheelM2TrimAdjustment(float value) {
    m_flywheel2TrimAdjustment = value;
}

bool ConfigurationSettings::isHopperLockEnabled() {
    return m_isMagLockEnabled;
}

void ConfigurationSettings::setIsHopperLockEnabled(bool value) {
    m_isMagLockEnabled = value;
}
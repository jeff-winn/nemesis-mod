#include "ConfigurationSettings.h"
#include "shared/BitConverter.h"
#include "SdCard.h"

ConfigurationSettings Settings = ConfigurationSettings();

void ConfigurationSettings::init() {
    auto sdc = getSdc();
    sdc.init();

    auto config = sdc.readConfig();
    m_name = String(config["name"].as<const char*>());
    
    auto bluetooth = config["bluetooth"];
    if (bluetooth != nullptr) {
        m_pin = String(bluetooth["pin"].as<const char*>());
        m_isBluetoothEnabled = bluetooth["enabled"].as<bool>();
    }
    
    auto defaults = config["defaults"];
    if (defaults != nullptr) {
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
    if (pusher != nullptr) {
        m_pusherLow = pusher["low"].as<unsigned int>();
        m_pusherNormal = pusher["normal"].as<unsigned int>();
        m_pusherMax = pusher["max"].as<unsigned int>();
    }

    auto flywheels = config["flywheels"];
    if (flywheels != nullptr) {
        m_flywheelsLow = flywheels["low"].as<unsigned int>();
        m_flywheelsNormal = flywheels["normal"].as<unsigned int>();
        m_flywheelsMax = flywheels["max"].as<unsigned int>();
    }
}

FlywheelSpeed ConfigurationSettings::parseFlywheelSpeed(const char* value) const {
    if (value == "low") {
        return FlywheelSpeed::Low;
    }

    if (value == "max") {
        return FlywheelSpeed::Max;
    }

    return FlywheelSpeed::Normal;
}

PusherSpeed ConfigurationSettings::parsePusherSpeed(const char* value) const {
    if (value == "low") {
        return PusherSpeed::Low;
    }

    if (value == "max") {
        return PusherSpeed::Max;
    }

    return PusherSpeed::Normal;
}

const char* ConfigurationSettings::getName() const {
    return m_name.c_str();
}

const char* ConfigurationSettings::getPairingPin() const {
    return m_pin.c_str();
}

FlywheelSpeed ConfigurationSettings::getFlywheelSpeed() const {
    return m_flywheelSpeed;
}

void ConfigurationSettings::setFlywheelSpeed(FlywheelSpeed value) {
    m_flywheelSpeed = value;
}

PusherSpeed ConfigurationSettings::getPusherSpeed() const {
    return m_pusherSpeed;
}

void ConfigurationSettings::setPusherSpeed(PusherSpeed value) {
    m_pusherSpeed = value;
}

int ConfigurationSettings::getPusherLowSpeed() const {
    return m_pusherLow;
}

void ConfigurationSettings::setPusherLowSpeed(int value) {
    m_pusherLow = value;
}

int ConfigurationSettings::getPusherNormalSpeed() const {
    return m_pusherNormal;
}

void ConfigurationSettings::setPusherNormalSpeed(int value) {
    m_pusherNormal = value;
}

int ConfigurationSettings::getPusherMaxSpeed() const {
    return m_pusherMax;
}

void ConfigurationSettings::setPusherMaxSpeed(int value) {    
    m_pusherMax = value;
}

int ConfigurationSettings::getFlywheelLowSpeed() const {
    return m_flywheelsLow;
}

void ConfigurationSettings::setFlywheelLowSpeed(int value) {
    m_flywheelsLow = value;
}

int ConfigurationSettings::getFlywheelNormalSpeed() const {
    return m_flywheelsNormal;
}

void ConfigurationSettings::setFlywheelNormalSpeed(int value) {    
    m_flywheelsNormal = value;
}

int ConfigurationSettings::getFlywheelMaxSpeed() const {
    return m_flywheelsMax;
}

void ConfigurationSettings::setFlywheelMaxSpeed(int value) {
    m_flywheelsMax = value;
}

float ConfigurationSettings::getFlywheelTrimVariance() const {
    return m_flywheelTrimVariance;
}

void ConfigurationSettings::setFlywheelTrimVariance(float value) {
    m_flywheelTrimVariance = value;
}

float ConfigurationSettings::getFlywheelM1TrimAdjustment() const {
    return m_flywheel1TrimAdjustment;
}

void ConfigurationSettings::setFlywheelM1TrimAdjustment(float value) {
    m_flywheel1TrimAdjustment = value;
}

float ConfigurationSettings::getFlywheelM2TrimAdjustment() const {
    return m_flywheel2TrimAdjustment;
}

void ConfigurationSettings::setFlywheelM2TrimAdjustment(float value) {
    m_flywheel2TrimAdjustment = value;
}

bool ConfigurationSettings::isHopperLockEnabled() const {
    return m_isMagLockEnabled;
}

void ConfigurationSettings::setIsHopperLockEnabled(bool value) {
    m_isMagLockEnabled = value;
}
#include "FlywheelSpeedCommand.h"

void FlywheelSpeedCommand::handleImpl(const uint8_t* data, const uint16_t len) {
    auto newSpeed = getSpeedFromPacket(data);
    m_controller->setSpeed(newSpeed);
}

FlywheelSpeed FlywheelSpeedCommand::getSpeedFromPacket(const uint8_t* data) const {
    auto value = data[0];

    switch (value) {
        case 1:
            return FlywheelSpeed::Low;

        case 255:
            return FlywheelSpeed::Max;

        default:
            return FlywheelSpeed::Normal;
    }
}
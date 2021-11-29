#include "FlywheelSpeedCommand.h"

void FlywheelSpeedCommand::handleImpl(uint8_t* data, uint16_t len) {
    auto newSpeed = getSpeedFromPacket(data);
    m_controller->setSpeed(newSpeed);
}

FlywheelSpeed FlywheelSpeedCommand::getSpeedFromPacket(uint8_t* data) {
    auto value = data[0];

    switch (value) {
        case 1: {
            return FlywheelSpeed::Kid;
        }
        case 255: {
            return FlywheelSpeed::Ludicrous;
        }
    }

    return FlywheelSpeed::Normal;
}
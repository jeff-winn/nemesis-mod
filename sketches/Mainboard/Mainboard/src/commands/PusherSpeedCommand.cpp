#include "PusherSpeedCommand.h"

PusherSpeedCommand::PusherSpeedCommand(PusherController* controller) {
    m_controller = controller;
}

PusherSpeedCommand::~PusherSpeedCommand() {
    m_controller = nullptr;
}

void PusherSpeedCommand::handleImpl(const uint8_t* data, const uint16_t len) {
    auto newSpeed = getSpeedFromPacket(data);
    m_controller->setSpeed(newSpeed);
}

PusherSpeed PusherSpeedCommand::getSpeedFromPacket(const uint8_t* data) const {
    auto value = data[0];

    switch (value) {
        case 2:
            return PusherSpeed::Low;            
        
        case 255:
            return PusherSpeed::Max;

        default:
            return PusherSpeed::Normal;
    }
}
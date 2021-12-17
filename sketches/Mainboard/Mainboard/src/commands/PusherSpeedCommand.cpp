#include "PusherSpeedCommand.h"

PusherSpeedCommand::PusherSpeedCommand(PusherController* controller) {
    m_controller = controller;
}

PusherSpeedCommand::~PusherSpeedCommand() {
    m_controller = NULL;
}

void PusherSpeedCommand::handleImpl(uint8_t* data, uint16_t len) {
    auto newSpeed = getSpeedFromPacket(data);
    m_controller->setSpeed(newSpeed);
}

PusherSpeed PusherSpeedCommand::getSpeedFromPacket(uint8_t* data) {
    auto value = data[0];

    switch (value) {
        case 2: {
            return PusherSpeed::Low;            
        }
        case 255: {
            return PusherSpeed::Max;
        }
    }

    return PusherSpeed::Normal;
}
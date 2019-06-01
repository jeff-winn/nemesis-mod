#include "FlywheelSpeedCommand.h"

FlywheelSpeedCommand::FlywheelSpeedCommand(FlywheelController* controller) {
    m_controller = controller;
}

FlywheelSpeedCommand::~FlywheelSpeedCommand() {
    m_controller = NULL;
}

void FlywheelSpeedCommand::handleImpl(Packet_t packet) {
    m_controller->setSpeed(FlywheelSpeed::Max);
}

FlywheelSpeed FlywheelSpeedCommand::getSpeedFromPacket(Packet_t packet) {
    auto value = packet.body[0];

    switch (value) {
        case 1: {
            return FlywheelSpeed::Normal;
        }
        case 2: {
            return FlywheelSpeed::Medium;            
        }
        case 255: {
            return FlywheelSpeed::Max;
        }
    }
}
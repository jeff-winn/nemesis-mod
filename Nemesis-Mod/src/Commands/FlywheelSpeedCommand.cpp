#include "FlywheelSpeedCommand.h"

FlywheelSpeedCommand::FlywheelSpeedCommand(FlywheelController* controller) {
    m_controller = controller;
}

void FlywheelSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(FlywheelSpeed::High);
}
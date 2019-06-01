#include "FlywheelSpeedCommand.h"

FlywheelSpeedCommand::FlywheelSpeedCommand(FlywheelController* controller) {
    m_controller = controller;
}

FlywheelSpeedCommand::~FlywheelSpeedCommand() {
    m_controller = NULL;
}

void FlywheelSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(FlywheelSpeed::Max);
}
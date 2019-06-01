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
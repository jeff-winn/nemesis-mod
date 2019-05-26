#include "ChangeFlywheelSpeedCommand.h"

ChangeFlywheelSpeedCommand::ChangeFlywheelSpeedCommand(FlywheelController* controller) {
    m_controller = controller;
}

void ChangeFlywheelSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(FlywheelSpeed::High);
}
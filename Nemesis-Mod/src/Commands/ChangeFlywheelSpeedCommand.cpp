#include "ChangeFlywheelSpeedCommand.h"

ChangeFlywheelSpeedCommand::ChangeFlywheelSpeedCommand(FlywheelController* controller) {
    m_controller = controller;
}

void ChangeFlywheelSpeedCommand::handle(Packet_t packet) {
    auto speed = (FlywheelSpeed)packet.body[0];
    Serial.println((byte)speed);

    m_controller->setSpeed(speed);
}
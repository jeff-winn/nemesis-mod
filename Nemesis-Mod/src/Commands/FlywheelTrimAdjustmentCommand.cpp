#include "FlywheelTrimAdjustmentCommand.h"

FlywheelTrimAdjustmentCommand::FlywheelTrimAdjustmentCommand(FlywheelController* controller) {
    m_controller = controller;
}

void FlywheelTrimAdjustmentCommand::handle(Packet_t packet) {
    m_controller->setMotorSpeedAdjustment(FlywheelMotor::Motor1, 1.0F);
    m_controller->setMotorSpeedAdjustment(FlywheelMotor::Motor2, 1.0F);
}
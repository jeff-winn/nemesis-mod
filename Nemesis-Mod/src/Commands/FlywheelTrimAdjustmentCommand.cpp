#include "FlywheelTrimAdjustmentCommand.h"

FlywheelTrimAdjustmentCommand::FlywheelTrimAdjustmentCommand(FlywheelController* controller) {
    m_controller = controller;
}

FlywheelTrimAdjustmentCommand::~FlywheelTrimAdjustmentCommand() {
    m_controller = NULL;
}

void FlywheelTrimAdjustmentCommand::handleImpl(Packet_t packet) {
    m_controller->setMotorSpeedAdjustment(FlywheelMotor::Motor1, 1.0F);
    m_controller->setMotorSpeedAdjustment(FlywheelMotor::Motor2, 1.0F);
}
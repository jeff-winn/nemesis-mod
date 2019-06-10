#include "FlywheelTrimAdjustmentCommand.h"

FlywheelTrimAdjustmentCommand::FlywheelTrimAdjustmentCommand(FlywheelController* controller) {
    m_controller = controller;
}

FlywheelTrimAdjustmentCommand::~FlywheelTrimAdjustmentCommand() {
    m_controller = NULL;
}

void FlywheelTrimAdjustmentCommand::handleImpl(Packet_t packet) {
    auto motor = getMotorFromPacket(packet);
    auto adjustment = getAdjustmentFromPacket(packet) / 255.0F;

    m_controller->setMotorSpeedAdjustment(motor, adjustment);
}

FlywheelMotor FlywheelTrimAdjustmentCommand::getMotorFromPacket(Packet_t packet) {
    auto value = packet.body[0];

    switch (value) {
        case 1: {
            return FlywheelMotor::Motor1;
        }
        case 2: {
            return FlywheelMotor::Motor2;
        }
    }
}

byte FlywheelTrimAdjustmentCommand::getAdjustmentFromPacket(Packet_t packet) {
    return packet.body[1];
}
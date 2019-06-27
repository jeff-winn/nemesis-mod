#include "FlywheelTrimAdjustmentCommand.h"
#include "../BitConverter.h"

void FlywheelTrimAdjustmentCommand::handleImpl(Packet_t packet) {
    auto motor = getMotorFromPacket(packet);

    auto adjustment = getAdjustmentFromPacket(packet);
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

float FlywheelTrimAdjustmentCommand::getAdjustmentFromPacket(Packet_t packet) {
    return Convert.toFloat(packet.body + 1);
}
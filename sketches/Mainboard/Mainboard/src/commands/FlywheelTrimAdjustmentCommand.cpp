#include "FlywheelTrimAdjustmentCommand.h"
#include "../shared/BitConverter.h"

FlywheelTrimAdjustmentCommand::FlywheelTrimAdjustmentCommand(uint8_t subtype, FlywheelController* controller) : FlywheelCommand(controller) {
    m_subtype = subtype;    
}

void FlywheelTrimAdjustmentCommand::handleImpl(const uint8_t* data, const uint16_t len) {
    auto motor = getMotor();
    auto adjustment = getAdjustmentFromPacket(data);

    m_controller->setMotorSpeedAdjustment(motor, adjustment);
}

FlywheelMotor FlywheelTrimAdjustmentCommand::getMotor() const {
    switch (m_subtype) {
        case 2:
            return FlywheelMotor::Motor2;

        default:
            return FlywheelMotor::Motor1;
    }
}

float FlywheelTrimAdjustmentCommand::getAdjustmentFromPacket(const uint8_t* data) const {
    return Convert.toFloat(data);
}
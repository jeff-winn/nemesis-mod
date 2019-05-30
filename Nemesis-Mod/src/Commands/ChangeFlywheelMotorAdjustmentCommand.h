#ifndef CHANGE_FLYWHEEL_MOTOR_ADJUSTMENT_COMMAND_H
#define CHANGE_FLYWHEEL_MOTOR_ADJUSTMENT_COMMAND_H

#include "../Controllers/FlywheelController.h"
#include "Command.h"

class ChangeFlywheelMotorAdjustmentCommand : public Command {
    public:
        ChangeFlywheelMotorAdjustmentCommand(FlywheelController* controller);

        void handle(Packet_t packet) override;

    private:
        FlywheelController* m_controller;
};

#endif
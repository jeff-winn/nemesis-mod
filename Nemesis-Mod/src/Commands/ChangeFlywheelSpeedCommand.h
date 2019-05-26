#ifndef CHANGE_FLYWHEEL_SPEED_COMMAND_H
#define CHANGE_FLYWHEEL_SPEED_COMMAND_H

#include "../Controllers/FlywheelController.h"
#include "Command.h"

// Provides a command which handles flywheel speed changes.
class ChangeFlywheelSpeedCommand : public Command {
    public:
        ChangeFlywheelSpeedCommand(FlywheelController* controller);

        // Handles the packet.
        void handle(Packet_t packet) override;
    
    private:
        FlywheelController* m_controller;
};

#endif
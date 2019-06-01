#ifndef FLYWHEEL_SPEED_COMMAND_H
#define FLYWHEEL_SPEED_COMMAND_H

#include "../Controllers/FlywheelController.h"
#include "Command.h"

// Provides a command which handles flywheel speed changes.
class FlywheelSpeedCommand : public Command {
    public:
        FlywheelSpeedCommand(FlywheelController* controller);

        ~FlywheelSpeedCommand() override;

    protected:
        FlywheelSpeed getSpeedFromPacket(Packet_t packet);
        void handleImpl(Packet_t packet) override;
    
    private:
        FlywheelController* m_controller;
};

#endif
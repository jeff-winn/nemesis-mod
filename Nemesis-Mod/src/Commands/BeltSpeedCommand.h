#ifndef CHANGE_BELT_SPEED_COMMAND_H
#define CHANGE_BELT_SPEED_COMMAND_H

#include "../Controllers/FeedController.h"
#include "Command.h"

// Provides a command to change the belt speed.
class BeltSpeedCommand : public Command {
    public:
        BeltSpeedCommand(FeedController* controller);

        // Handles the packet.
        void handle(Packet_t packet) override;

    private:
        FeedController* m_controller;
};

#endif
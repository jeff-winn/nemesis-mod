#ifndef PUSHER_SPEED_COMMAND_H
#define PUSHER_SPEED_COMMAND_H

#include "../Command.h"
#include "../PusherController.h"

// Provides a command to change the pusher speed.
class PusherSpeedCommand : public Command {
    public:
        explicit PusherSpeedCommand(PusherController* controller);

    protected:
        void handleImpl(const uint8_t* data, const uint16_t len) override;
        PusherSpeed getSpeedFromPacket(const uint8_t* data) const;

    private:
        PusherController* m_controller;
};

#endif /* PUSHER_SPEED_COMMAND_H */
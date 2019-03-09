#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "../Hardware/GPIO/AnalogPin.h"

// Provides a mechanism to control the feed assembly.
class FeedController {
    public:
        FeedController(AnalogPin* pin);

        // Initializes the controller.
        virtual void init();

        // Starts the feed.
        virtual void start();

        // Stops the feed.
        virtual void stop();

    private:
        AnalogPin* m_pin;
        bool m_isRunning;
};

#endif
#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

// Provides a mechanism to control the feed assembly.
class FeedController {
    public:
        // Starts the feed.
        virtual void start();

        // Stops the feed.
        virtual void stop();

    private:
        bool m_isRunning;
};

#endif
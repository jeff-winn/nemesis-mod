#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <Arduino.h>
#include "AuthenticationToken_t.h"

// Provides access to the configuration settings.
class ConfigurationSettings {
    public:
        AuthenticationToken_t getAuthenticationToken();
        void setAuthenticationToken(AuthenticationToken_t token);
        void resetAuthenticationToken();

        int getFeedNormalSpeed();
        void setFeedNormalSpeed(int value);

        int getFeedHighSpeed();
        void setFeedHighSpeed(int value);

        int getFeedMaxSpeed();
        void setFeedMaxSpeed(int value);

        float getFlywheelTrimVariance();
        void setFlywheelTrimVariance(float value);

        int getFlywheelNormalSpeed();
        void setFlywheelNormalSpeed(int value);

        int getFlywheelMediumSpeed();
        void setFlywheelMediumSpeed(int value);

        int getFlywheelMaxSpeed();
        void setFlywheelMaxSpeed(int value);

        float getFlywheelM1TrimAdjustment();
        void setFlywheelM1TrimAdjustment(float value);

        float getFlywheelM2TrimAdjustment();
        void setFlywheelM2TrimAdjustment(float value);

        // Initializes the configuration settings.
        void init();

        // Defaults all of the configuration settings.
        void defaultSettings();

        // Clears the configuration settings.
        void clear();

    protected:
        bool initialized();
        void setInitialized(bool value);

        int readInt32(short address);
        void writeInt32(short address, int value);

        float readFloat(short address);
        void writeFloat(short address, float value);
};

// Defines the instance of configuration settings used by the hardware.
extern ConfigurationSettings Settings;

#endif
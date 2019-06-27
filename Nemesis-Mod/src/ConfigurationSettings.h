#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <Adafruit_FRAM_I2C.h>

// Provides access to the configuration settings.
class ConfigurationSettings {
    public:
        ConfigurationSettings(Adafruit_FRAM_I2C* fram);

        ~ConfigurationSettings();

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

        // Initializes the configuration settings.
        void init();

        // Defaults all of the configuration settings.
        void defaultSettings();

    protected:
        bool initialized();
        void setInitialized(bool value);

        int readInt32(short address);
        void writeInt32(short address, int value);

        float readFloat(short address);
        void writeFloat(short address, float value);

    private:
        Adafruit_FRAM_I2C* m_fram;
};

#endif
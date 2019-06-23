#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <Adafruit_FRAM_I2C.h>

// Provides access to the configuration settings.
class ConfigurationSettings {
    public:
        ConfigurationSettings(Adafruit_FRAM_I2C* fram);

        ~ConfigurationSettings();

        int getFeedNormalSpeed();
        int getFeedHighSpeed();
        int getFeedMaxSpeed();

        float getFlywheelTrimVariance();
        int getFlywheelNormalSpeed();
        int getFlywheelMediumSpeed();
        int getFlywheelMaxSpeed();

        // Initializes the configuration settings.
        void init();
    private:
        Adafruit_FRAM_I2C* m_fram;
};

#endif
#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <Arduino.h>
#include "FlywheelController.h"
#include "FeedController.h"

// Provides access to the configuration settings.
class ConfigurationSettings {
    public:
        ConfigurationSettings();
        ~ConfigurationSettings();

        void resetAuthenticationToken();

        void setExistingPairing(bool value);
        bool hasExistingPairing();

        const char* getName();
        const char* getPairingPin();

        int getFeedLowSpeed();
        void setFeedLowSpeed(int value);

        int getFeedNormalSpeed();
        void setFeedNormalSpeed(int value);

        int getFeedMaxSpeed();
        void setFeedMaxSpeed(int value);

        float getFlywheelTrimVariance();
        void setFlywheelTrimVariance(float value);

        int getFlywheelKidSpeed();
        void setFlywheelKidSpeed(int value);

        int getFlywheelNormalSpeed();
        void setFlywheelNormalSpeed(int value);

        int getFlywheelLudicrousSpeed();
        void setFlywheelLudicrousSpeed(int value);

        float getFlywheelM1TrimAdjustment();
        void setFlywheelM1TrimAdjustment(float value);

        float getFlywheelM2TrimAdjustment();
        void setFlywheelM2TrimAdjustment(float value);

        bool isHopperLockEnabled();
        void setIsHopperLockEnabled(bool value);

        FlywheelSpeed getFlywheelSpeed();
        void setFlywheelSpeed(FlywheelSpeed value);

        BeltSpeed getPusherSpeed();
        void setPusherSpeed(BeltSpeed value);

        // Initializes the configuration settings.
        void init();

    protected:
        FlywheelSpeed parseFlywheelSpeed(const char* value);
        BeltSpeed parsePusherSpeed(const char* value);

    private:
        String m_name;
        bool m_isBluetoothEnabled;
        String m_pin;
        float m_flywheelTrimVariance;
        float m_flywheel1TrimAdjustment;
        float m_flywheel2TrimAdjustment;
        bool m_isMagLockEnabled;

        unsigned int m_pusherLow;
        unsigned int m_pusherNormal;
        unsigned int m_pusherMax;

        unsigned int m_flywheelsLow;
        unsigned int m_flywheelsNormal;
        unsigned int m_flywheelsMax;

        FlywheelSpeed m_flywheelSpeed;
        BeltSpeed m_pusherSpeed;
};

// Defines the instance of configuration settings used by the hardware.
extern ConfigurationSettings Settings;

#endif /* CONFIGURATION_SETTINGS_H */
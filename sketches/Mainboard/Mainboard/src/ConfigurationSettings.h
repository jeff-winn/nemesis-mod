#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <Arduino.h>
#include "FlywheelController.h"
#include "PusherController.h"

// Provides access to the configuration settings.
class ConfigurationSettings {
    public:
        ConfigurationSettings() = default;
        ~ConfigurationSettings() = default;

        void resetAuthenticationToken();

        void setExistingPairing(bool value);
        bool hasExistingPairing() const;

        const char* getName() const;
        const char* getPairingPin() const;

        int getPusherLowSpeed() const;
        void setPusherLowSpeed(int value);

        int getPusherNormalSpeed() const;
        void setPusherNormalSpeed(int value);

        int getPusherMaxSpeed() const;
        void setPusherMaxSpeed(int value);

        float getFlywheelTrimVariance() const;
        void setFlywheelTrimVariance(float value);

        int getFlywheelLowSpeed() const;
        void setFlywheelLowSpeed(int value);

        int getFlywheelNormalSpeed() const;
        void setFlywheelNormalSpeed(int value);

        int getFlywheelMaxSpeed() const;
        void setFlywheelMaxSpeed(int value);

        float getFlywheelM1TrimAdjustment() const;
        void setFlywheelM1TrimAdjustment(float value);

        float getFlywheelM2TrimAdjustment() const;
        void setFlywheelM2TrimAdjustment(float value);

        bool isHopperLockEnabled() const;
        void setIsHopperLockEnabled(bool value);

        FlywheelSpeed getFlywheelSpeed() const;
        void setFlywheelSpeed(FlywheelSpeed value);

        PusherSpeed getPusherSpeed() const;
        void setPusherSpeed(PusherSpeed value);

        // Initializes the configuration settings.
        void init();

    protected:
        FlywheelSpeed parseFlywheelSpeed(const char* value) const;
        PusherSpeed parsePusherSpeed(const char* value) const;

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
        PusherSpeed m_pusherSpeed;
};

// Defines the instance of configuration settings used by the hardware.
extern ConfigurationSettings Settings;

#endif /* CONFIGURATION_SETTINGS_H */
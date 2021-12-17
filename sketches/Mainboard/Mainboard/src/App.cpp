#include "App.h"
#include "Button.h"
#include "CommandFactory.h"
#include "ConfigurationSettings.h"
#include "FeedController.h"
#include "FlywheelController.h"
#include "hardware/NRF52.h"
#include "Mainboard.h"
#include "shared/Constants.h"

const uint32_t SYSTEM_OFF_IN_MSECS = 600000;        // The duration of time (in milliseconds) the system should delay.
const uint32_t REV_BUTTON_PIN = 13;                 // The GPIO pin handling the rev trigger.
const uint32_t FIRING_BUTTON_PIN = 12;              // The GPIO pin handling the firing trigger.
const uint32_t HOPPER_LOCK_BUTTON_PIN = 19;         // The GPIO pin handling the soft lock whether the blaster should be disabled.
const unsigned long TRIGGER_DELAY_IN_MSECS = 10;    // The duration of time to delay while the triggers are active.

App Application = App();
Button RevTrigger = Button(REV_BUTTON_PIN);
Button FiringTrigger = Button(FIRING_BUTTON_PIN);
Button HopperLock = Button(HOPPER_LOCK_BUTTON_PIN);

void OnRemoteCommandReceivedCallback(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len) {
    Application.onRemoteCommandReceived(type, subtype, data, len);
}

App::App() {
    m_commandFactory = CommandFactory();
    m_isAuthorized = true;
    m_firing = false;
}

void App::run() {
    checkForAsyncCommands();

    if (shouldAllowRevvingFlywheels()) {
        revFlywheels();

        while (shouldAllowRevvingFlywheels()) {                        
            while (shouldAllowFiringRounds()) {
                if (!isAlreadyFiring()) {
                    startFiring();
                }

                checkForAsyncCommands();
                MCU.delaySafe(TRIGGER_DELAY_IN_MSECS);
            }            
            
            stopFiring();

            checkForAsyncCommands();
            MCU.delaySafe(TRIGGER_DELAY_IN_MSECS);
        }

        stopFlywheels();
    }
}

void App::checkForAsyncCommands() {
    if (BT.hasPendingPackets()) {
        BT.readPacket(OnRemoteCommandReceivedCallback);
    }
}

void App::revFlywheels() {
    Flywheels.start();
}

bool App::isAlreadyFiring() {
    return m_firing;
}

void App::startFiring() {
    m_firing = true;

    Belt.start();
}

void App::stopFiring() {
    Belt.stop();

    m_firing = false;
}

void App::stopFlywheels() {
    Flywheels.stop();
}

bool App::shouldAllowRevvingFlywheels() {
    return isAuthorized() && !isLockedOut() && RevTrigger.isPressed();
}

bool App::shouldAllowFiringRounds() {
    return isAuthorized() && !isLockedOut() && FiringTrigger.isPressed();
}

bool App::isLockedOut() {
    return Settings.isHopperLockEnabled() && !HopperLock.isPressed();    
}

bool App::isAuthorized() {
    return m_isAuthorized;
}

void App::init() {
    Settings.init(); 
    
    Flywheels.init();
    Belt.init();
    FiringTrigger.init();
    RevTrigger.init();
    HopperLock.init();

    BT.init();
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len) {   
    auto command = m_commandFactory.createCommand(type, subtype);
    if (command) {
        auto requiresAuthorization = command->requiresAuthorization();
        if (!requiresAuthorization || (requiresAuthorization && isAuthorized())) {
            command->handle(data, len);
        }
        
        delete command;
    }
}

void App::authenticate() {
    m_isAuthorized = true;
}

void App::revokeAuthorization() {
    m_isAuthorized = false;
}

void App::clear() {
    // Settings.clear();

    resetCore();
}

void App::reset() {
    Settings.resetAuthenticationToken();
    // Settings.defaultSettings();

    resetCore();
}

void App::resetCore() {
    revokeAuthorization();
    BT.reset();
}
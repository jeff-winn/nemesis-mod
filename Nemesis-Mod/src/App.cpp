#include "App.h"
#include "BLEController.h"
#include "Button.h"
#include "Callbacks.h"
#include "CommandFactory.h"
#include "FeedController.h"
#include "FlywheelController.h"
#include "Log.h"
#include "Mainboard.h"

const uint32_t SYSTEM_OFF_IN_MSECS = 600000; // 10 minutes
const uint32_t REV_BUTTON_PIN = 16;
const uint32_t FIRING_BUTTON_PIN = 15;

App Application = App();
Button RevTrigger = Button(REV_BUTTON_PIN);
Button FiringTrigger = Button(FIRING_BUTTON_PIN);

// Indicates whether the operator is authorized (allowing release of the software lock).
bool IS_OPERATOR_AUTHORIZED = true;
// #ifndef __RELEASE__
//     true;
// #else
//     false;
// #endif

App::App() {
    m_commandFactory = CommandFactory();
}

void App::run() {
    sendCurrentNotifications();

    if (isAuthorized() && RevTrigger.isPressed()) {
        Log.println("Revving flywheels...");

        m_revvedAtMillis = millis();
        Flywheels.start();

        auto firing = false;
        while (RevTrigger.isPressed()) {
            sendCurrentNotifications();

            if (FiringTrigger.isPressed()) {
                if (!firing) {
                    firing = true;

                    Log.println("Firing!");
                    Belt.start();
                }
            }
            else {
                Belt.stop();
                firing = false;
            }

            MCU.delaySafe(10);
        }

        Belt.stop();
        Flywheels.stop();
        m_revvedAtMillis = millis();

        Log.println("Flywheels stopped.");
    }

    waitForRevTriggerToBePressed();
}

void App::waitForRevTriggerToBePressed() {
    auto diff = millis() - m_revvedAtMillis;
    if (diff >= SYSTEM_OFF_IN_MSECS) {
#if __RELEASE__
        MCU.waitforEventSafe(REV_BUTTON_PIN, HIGH);
#endif
    }
    else {
        MCU.delaySafe(50);
    }
}

bool App::isAuthorized() {
    return IS_OPERATOR_AUTHORIZED;
}

// Receives notifications whenever a bluetooth command has been received. 
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
    Application.onRemoteCommandReceived(type, data, len, subtype);
}

void App::init() {
    Log.println("Initializing application...");

    Settings.init(); 
    Flywheels.init(&Settings);
    Flywheels.setSpeed(FlywheelSpeed::Normal);

    Belt.init(&Settings);
    Belt.setSpeed(BeltSpeed::Normal);

    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);
    BLE.init();
    BLE.startAdvertising();

    FiringTrigger.init();
    RevTrigger.init();

    m_revvedAtMillis = millis();

    Log.println("Completed application initialization.\n");
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {   
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
    auto authorized = true;
    // auto existingToken = Settings.getAuthenticationToken();

    // if (token.length > 0 && existingToken.length == 0) {
    //     // The user has not stored the authentication data yet, update it.
    //     Settings.setAuthenticationToken(token);        
    // }
    // else if (existingToken.length != token.length) {
    //     authorized = false;
    // }
    // else if (existingToken.length > 0) {
    //     for (byte index = 0; index < existingToken.length; index++) {
    //         authorized &= existingToken.data[index] == token.data[index];
    //     }
    // }

    IS_OPERATOR_AUTHORIZED = authorized;
}

void App::revokeAuthorization() {
    IS_OPERATOR_AUTHORIZED = false;
}

void App::sendCurrentNotifications() {
    auto flywheel1 = Flywheels.getMotorCurrentMilliamps(FlywheelMotor::Motor1);
    auto flywheel2 = Flywheels.getMotorCurrentMilliamps(FlywheelMotor::Motor2);
    BLE.notifyFlywheelCurrentMilliamps(flywheel1, flywheel2, RevTrigger.isPressed());

    auto feed = Belt.getMotorCurrentMilliamps();
    BLE.notifyBeltCurrentMilliamps(feed, FiringTrigger.isPressed());
}

void App::clear() {
    Settings.clear();

    resetCore();
}

void App::reset() {
    Settings.resetAuthenticationToken();
    Settings.defaultSettings();

    resetCore();
}

void App::resetCore() {
    revokeAuthorization();
    BLE.clearBonds();
}
#include "commands/BeltSpeedCommand.h"
#include "commands/ChangeConfigurationSettingCommand.h"
#include "commands/FlywheelTrimAdjustmentCommand.h"
#include "commands/FlywheelSpeedCommand.h"
#include "App.h"
#include "BluetoothController.h"
#include "Button.h"
#include "Callbacks.h"
#include "Command.h"
#include "FeedController.h"
#include "FlywheelController.h"
#include "Log.h"
#include "Mainboard.h"

App Application = App();

const uint32_t SYSTEM_OFF_IN_MSECS = 300000; // 5 minutes
const uint32_t NOTIFICATION_INTERVAL_IN_MSECS = 10000; // 5 seconds
const uint32_t NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS = 1000; // 1 second

const uint32_t REV_BUTTON_PIN = 16;
const uint32_t FIRING_BUTTON_PIN = 15;

Button RevTrigger = Button(REV_BUTTON_PIN);
Button FiringTrigger = Button(FIRING_BUTTON_PIN);

// Indicates whether the operator is authorized (allowing release of the software lock).
bool IS_OPERATOR_AUTHORIZED = true;
// #ifndef __RELEASE__
//     true;
// #else
//     false;
// #endif

void App::run() {
    sendCurrentNotifications(NOTIFICATION_INTERVAL_IN_MSECS);

    if (isAuthorized() && RevTrigger.isPressed()) {
        Log.println("Revving flywheels...");

        revvedAtMillis = millis();
        Flywheels.start();

        auto firing = false;
        while (RevTrigger.isPressed()) {
            sendCurrentNotifications(NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS);

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
        revvedAtMillis = millis();

        Log.println("Flywheels stopped.");
    }

    waitForRevTriggerToBePressed();
}

void App::waitForRevTriggerToBePressed() {
    auto diff = millis() - revvedAtMillis;
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
    Packet_t packet;
    packet.header.type = type;
    packet.header.subtype = subtype;
    packet.header.len = len;
    packet.body = data;

    Application.onRemoteCommandReceived(packet);
}

void App::init() {
    Log.println("Initializing application...");

    Settings.init(); 
    Flywheels.init();
    Belt.init();

    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);

    BLE.init();
    BLE.startAdvertising();

    FiringTrigger.init();
    RevTrigger.init();

    Flywheels.setSpeed(FlywheelSpeed::Normal);
    Belt.setSpeed(BeltSpeed::Normal);

    auto current = millis();
    revvedAtMillis = current;
    lastCurrentNotifiedAtMillis = current;

    Log.println("Completed application initialization.\n");
}

void App::onRemoteCommandReceived(Packet_t packet) {   
    auto command = createCommandFromPacket(packet);
    if (command) {
        auto requiresAuthorization = command->requiresAuthorization();
        if (!requiresAuthorization || (requiresAuthorization && isAuthorized())) {
            command->handle(packet);
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

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 10: {
            return new ChangeConfigurationSettingCommand();
        }
        case 100: {
            return new BeltSpeedCommand(&Belt);
        }
        case 200: {
            return new FlywheelSpeedCommand(&Flywheels);
        }
        case 201: {
            return new FlywheelTrimAdjustmentCommand(&Flywheels);        
        }
    }

    return NULL;
}

void App::revokeAuthorization() {
    IS_OPERATOR_AUTHORIZED = false;
}

void App::sendCurrentNotifications(uint32_t interval) {
    auto diff = millis() - lastCurrentNotifiedAtMillis;
    if (diff < interval) {
        return;
    }

    auto m1 = Flywheels.getMotorCurrentMilliamps(FlywheelMotor::Motor1);
    auto m2 = Flywheels.getMotorCurrentMilliamps(FlywheelMotor::Motor2);    

    lastCurrentNotifiedAtMillis = millis();
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
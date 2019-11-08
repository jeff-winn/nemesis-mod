#include "bluetooth/BluetoothController.h"
#include "commands/AuthenticateOperatorCommand.h"
#include "commands/BeltSpeedCommand.h"
#include "commands/ChangeConfigurationSettingCommand.h"
#include "commands/DefaultConfigurationSettingsCommand.h"
#include "commands/FlywheelTrimAdjustmentCommand.h"
#include "commands/FlywheelSpeedCommand.h"
#include "commands/RevokeOperatorAuthorizationCommand.h"
#include "hardware/Mainboard.h"
#include "App.h"
#include "Button.h"
#include "Command.h"
#include "FeedController.h"
#include "FlywheelController.h"

BluetoothController Bluetooth = BluetoothController();
FlywheelController Flywheels = FlywheelController();
FeedController Belt = FeedController();
Button RevTrigger = Button(16);
Button FiringTrigger = Button(15);
Button ResetButton = Button(28, true);

const uint16_t CLEAR_HOLD_IN_MSECS = 30000;
const uint16_t RESET_HOLD_IN_MSECS = 5000;

// Indicates whether the operator is authorized (allowing release of the software lock).
bool IS_OPERATOR_AUTHORIZED = 
#ifndef __RELEASE__
    true;
#else
    false;
#endif

void App::run() {
    if (ResetButton.isPressed()) {
        handleResetAttempt();
    }
    else {
        if (isAuthorized() && RevTrigger.isPressed()) {
            Flywheels.start();

            while (RevTrigger.isPressed()) {
                if (FiringTrigger.isPressed()) {
                    Belt.start();
                }
                else {
                    Belt.stop();
                }

                MCU.delaySafe(10);
            }

            Flywheels.stop();
        }
    }

    MCU.delaySafe(50);
}

bool App::isAuthorized() {
    return IS_OPERATOR_AUTHORIZED;
}

void App::init() {
    Bluetooth.beginInit();
    FiringTrigger.init();
    RevTrigger.init();
    ResetButton.init();
    Flywheels.init();
    Belt.init();
    Settings.init();
    
    Flywheels.setSpeed(FlywheelSpeed::Normal);
    Belt.setSpeed(BeltSpeed::Normal);
    Bluetooth.endInit();
}

void App::handleAnyExternalCommands() {
    // auto packet = ble->readPacket();
    
    // auto command = createCommandFromPacket(packet);
    // if (command) {
    //     auto requiresAuthorization = command->requiresAuthorization();
    //     if (!requiresAuthorization || (requiresAuthorization && isAuthorized())) {
    //         command->handle(packet);
    //     }
        
    //     delete command;
    // }
}

void App::authenticate(AuthenticationToken_t token) {
    auto authorized = true;
    auto existingToken = Settings.getAuthenticationToken();

    if (token.length > 0 && existingToken.length == 0) {
        // The user has not stored the authentication data yet, update it.
        Settings.setAuthenticationToken(token);        
    }
    else if (existingToken.length != token.length) {
        authorized = false;
    }
    else if (existingToken.length > 0) {
        for (byte index = 0; index < existingToken.length; index++) {
            authorized &= existingToken.data[index] == token.data[index];
        }
    }

    IS_OPERATOR_AUTHORIZED = authorized;
}

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 1: {
            return new AuthenticateOperatorCommand(this);
        }
        case 2: {
            return new RevokeOperatorAuthorizationCommand(this);
        }
        case 10: {
            return new DefaultConfigurationSettingsCommand();
        }
        case 11: {
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

void App::handleResetAttempt() {    
    auto started = millis();
    while (ResetButton.isPressed()) {
        MCU.delaySafe(50);
    }

    auto successful = false;
    auto diff = millis() - started;

    if (diff >= CLEAR_HOLD_IN_MSECS) {
        Settings.clear();
        successful = true;
    }
    else if (diff >= RESET_HOLD_IN_MSECS) {
        Settings.resetAuthenticationToken();
        Settings.defaultSettings();
        successful = true;
    }

    if (successful) {
        revokeAuthorization();
    }
}

void App::revokeAuthorization() {
    IS_OPERATOR_AUTHORIZED = false;
}
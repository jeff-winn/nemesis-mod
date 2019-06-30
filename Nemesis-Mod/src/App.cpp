#include "commands/AuthenticateOperatorCommand.h"
#include "commands/BeltSpeedCommand.h"
#include "commands/ChangeConfigurationSettingCommand.h"
#include "commands/DefaultConfigurationSettingsCommand.h"
#include "commands/FlywheelTrimAdjustmentCommand.h"
#include "commands/FlywheelSpeedCommand.h"
#include "App.h"

const uint16_t CLEAR_HOLD_IN_MSECS = 30000;
const uint16_t RESET_HOLD_IN_MSECS = 5000;

// Indicates whether the operator has authenticated (allowing the release of the software lock).
bool HAS_OPERATOR_AUTHENTICATED = 
#ifndef __RELEASE__
    true;
#else
    false;
#endif

App::App(FlywheelController* const flywheelController, FeedController* feedController, Button* revTrigger, Button* firingTrigger, Button* resetButton, BluetoothManager* ble, ConfigurationSettings* config, Mainboard* hardware) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    m_resetButton = resetButton;
    m_ble = ble;
    m_config = config;
    m_hardware = hardware;
}

App::~App() {
    m_flywheelController = NULL;
    m_feedController = NULL;
    m_revTrigger = NULL;
    m_firingTrigger = NULL;
    m_resetButton = NULL;
    m_ble = NULL;
    m_config = NULL;
    m_hardware = NULL;
}

void App::run() {
    if (m_resetButton->isPressed()) {
        handleResetAttempt();
    }
    else {
        handleAnyExternalCommands();

        if (HAS_OPERATOR_AUTHENTICATED) {
            while (m_revTrigger->isPressed()) {
                m_flywheelController->start();

                while (m_firingTrigger->isPressed()) {
                    m_feedController->start();
                    m_hardware->delaySafe(10);
                }

                m_feedController->stop();
                m_hardware->delaySafe(10);
            }

            m_flywheelController->stop();
        }
    }

    m_hardware->delaySafe(50);
}

void App::init() {
    m_ble->beginInit();
    m_ble->setName("Nerf Nemesis MXVII-10K\n");
    m_ble->endInit();

    m_firingTrigger->init();
    m_revTrigger->init();
    m_resetButton->init();
    m_flywheelController->init();
    m_feedController->init();
    m_config->init();
    
    m_flywheelController->setSpeed(FlywheelSpeed::Normal);
    m_feedController->setSpeed(BeltSpeed::Normal);
}

void App::handleAnyExternalCommands() {
    auto packet = m_ble->readPacket();
    
    auto command = createCommandFromPacket(packet);
    if (command) {
        auto requiresAuthentication = command->requiresAuthentication();
        if (!requiresAuthentication || (requiresAuthentication && HAS_OPERATOR_AUTHENTICATED)) {
            command->handle(packet);
        }
        
        delete command;
    }
}

void App::authenticate(AuthenticationToken_t token) {
    auto authenticated = true;
    auto existingToken = m_config->getAuthenticationToken();

    if (token.length > 0 && existingToken.length == 0) {
        // The user has not stored the authentication data yet, update it.
        m_config->setAuthenticationToken(token);        
    }
    else if (existingToken.length != token.length) {
        authenticated = false;
    }
    else if (existingToken.length > 0) {
        for (byte index = 0; index < existingToken.length; index++) {
            authenticated &= existingToken.data[index] == token.data[index];
        }
    }

    HAS_OPERATOR_AUTHENTICATED = authenticated;
}

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 1: {
            return new AuthenticateOperatorCommand(this);
        }
        case 10: {
            return new DefaultConfigurationSettingsCommand(m_config);
        }
        case 11: {
            return new ChangeConfigurationSettingCommand(m_config);
        }
        case 100: {
            return new BeltSpeedCommand(m_feedController);
        }
        case 200: {
            return new FlywheelSpeedCommand(m_flywheelController);
        }
        case 201: {
            return new FlywheelTrimAdjustmentCommand(m_flywheelController);        
        }
    }

    return NULL;
}

void App::handleResetAttempt() {    
    auto started = millis();
    while (m_resetButton->isPressed()) {
        m_hardware->delaySafe(50);
    }

    auto successful = false;
    auto diff = millis() - started;

    if (diff >= CLEAR_HOLD_IN_MSECS) {
        m_config->clear();
        successful = true;
    }
    else if (diff >= RESET_HOLD_IN_MSECS) {
        m_config->resetAuthenticationToken();
        m_config->defaultSettings();
        successful = true;
    }

    if (successful) {
        deauthenticate();
    }
}

void App::deauthenticate() {
    HAS_OPERATOR_AUTHENTICATED = false;
}
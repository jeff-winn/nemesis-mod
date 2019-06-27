#include "commands/AuthenticateOperatorCommand.h"
#include "commands/BeltSpeedCommand.h"
#include "commands/ChangeConfigurationSettingCommand.h"
#include "commands/FlywheelTrimAdjustmentCommand.h"
#include "commands/FlywheelSpeedCommand.h"
#include "commands/ResetConfigurationCommand.h"
#include "App.h"

#ifdef __RELEASE__
    bool HAS_OPERATOR_AUTHENTICATED = false;
#else
    // Indicates whether the operator has authenticated (allowing the release of the software lock).
    bool HAS_OPERATOR_AUTHENTICATED = true;
#endif

App::App(FlywheelController* flywheelController, FeedController* feedController, PolledButton* revTrigger, PolledButton* firingTrigger, BluetoothManager* ble, ConfigurationSettings* config, Mainboard* hardware) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    m_ble = ble;
    m_config = config;
    m_hardware = hardware;
}

App::~App() {
    m_flywheelController = NULL;
    m_feedController = NULL;
    m_revTrigger = NULL;
    m_firingTrigger = NULL;
    m_ble = NULL;
    m_config = NULL;
    m_hardware = NULL;
}

void App::run() {   
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

    m_hardware->delaySafe(50);
}

void App::init() {
    m_ble->beginInit();
    m_ble->setName("Nerf Nemesis MXVII-10K\n");
    m_ble->endInit();

    m_firingTrigger->init();
    m_revTrigger->init();
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

void App::authenticate() {
    HAS_OPERATOR_AUTHENTICATED = true;
}

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 1: {
            return new AuthenticateOperatorCommand(this);
        }
        case 10: {
            return new ResetConfigurationCommand(m_config);
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
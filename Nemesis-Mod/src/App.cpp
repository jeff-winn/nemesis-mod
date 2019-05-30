#include "Commands/AuthenticateOperatorCommand.h"
#include "Commands/ChangeFlywheelMotorAdjustmentCommand.h"
#include "Commands/ChangeFlywheelSpeedCommand.h"
#include "Commands/ChangeBeltSpeedCommand.h"
#include "App.h"

#ifdef __RELEASE__
    bool HAS_OPERATOR_AUTHENTICATED = false;
#else
    // Indicates whether the operator has authenticated (allowing the release of the software lock).
    bool HAS_OPERATOR_AUTHENTICATED = true;
#endif

App::App(FlywheelController* flywheelController, FeedController* feedController, PolledButton* revTrigger, PolledButton* firingTrigger, BluetoothAdapter* ble, Mainboard* hardware) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    m_ble = ble;
    m_hardware = hardware;    
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
    
    m_flywheelController->setSpeed(FlywheelSpeed::Normal);
    m_feedController->setSpeed(BeltSpeed::Normal);
}

void App::handleAnyExternalCommands() {
    auto packet = m_ble->readPacket();

    auto command = createCommandFromPacket(packet);
    if (command) {
        command->handle(packet);
    }
}

void App::authenticate() {
    HAS_OPERATOR_AUTHENTICATED = true;
}

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 'A': {
            return new AuthenticateOperatorCommand(this);
        }        
        case 'B': {
            return new ChangeBeltSpeedCommand(m_feedController);
        }
        case 'F': {
            return new ChangeFlywheelSpeedCommand(m_flywheelController);
        }
        case 'M': {
        }
    }

    return NULL;
}
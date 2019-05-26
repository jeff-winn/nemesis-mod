#include "Commands/ChangeFlywheelSpeedCommand.h"
#include "Commands/ChangeBeltSpeedCommand.h"
#include "App.h"

// Indicates whether the operator has authenticated prior to releasing the software lock.
bool HAS_OPERATOR_AUTHENTICATED = true;

App::App(FlywheelController* flywheelController, FeedController* feedController, PolledButton* revTrigger, PolledButton* firingTrigger, Mainboard* hardware, BluetoothAdapter* ble) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    m_hardware = hardware;    
    m_ble = ble;
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
        Serial.println("Command executed.");
    }
}

Command* App::createCommandFromPacket(Packet_t packet) {
    switch (packet.header.type) {
        case 'F': {
            return new ChangeFlywheelSpeedCommand(m_flywheelController);
        }
        case 'B': {
            return new ChangeBeltSpeedCommand(m_feedController);
        }
    }

    return NULL;
}
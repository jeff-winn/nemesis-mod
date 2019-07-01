#include "DeauthorizeOperatorCommand.h"

DeauthorizeOperatorCommand::DeauthorizeOperatorCommand(App* app) {
    m_app = app;
}

DeauthorizeOperatorCommand::~DeauthorizeOperatorCommand() {
    m_app = NULL;
}

void DeauthorizeOperatorCommand::handleImpl(Packet_t packet) {
    m_app->deauthorize();
}
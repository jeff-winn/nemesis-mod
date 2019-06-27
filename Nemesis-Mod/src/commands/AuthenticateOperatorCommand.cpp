#include "AuthenticateOperatorCommand.h"

AuthenticateOperatorCommand::AuthenticateOperatorCommand(App* app) {
    m_app = app;
}

AuthenticateOperatorCommand::~AuthenticateOperatorCommand() {
    m_app = NULL;
}

bool AuthenticateOperatorCommand::requiresAuthentication() {
    return false;
}

void AuthenticateOperatorCommand::handleImpl(Packet_t packet) {
    m_app->authenticate();
}
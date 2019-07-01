#include "AuthenticateOperatorCommand.h"

AuthenticateOperatorCommand::AuthenticateOperatorCommand(App* app) {
    m_app = app;
}

AuthenticateOperatorCommand::~AuthenticateOperatorCommand() {
    m_app = NULL;
}

bool AuthenticateOperatorCommand::requiresAuthorization() {
    return false;
}

void AuthenticateOperatorCommand::handleImpl(Packet_t packet) {
    AuthenticationToken_t token;
    m_app->authenticate(token);
}
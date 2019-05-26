#include "AuthenticateOperatorCommand.h"

AuthenticateOperatorCommand::AuthenticateOperatorCommand(App* app) {
    m_app = app;
}

void AuthenticateOperatorCommand::handle(Packet_t packet) {
    m_app->authenticate();
}
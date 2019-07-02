#include "RevokeOperatorAuthorizationCommand.h"

RevokeOperatorAuthorizationCommand::RevokeOperatorAuthorizationCommand(App* app) {
    m_app = app;
}

RevokeOperatorAuthorizationCommand::~RevokeOperatorAuthorizationCommand() {
    m_app = NULL;
}

void RevokeOperatorAuthorizationCommand::handleImpl(Packet_t packet) {
    m_app->revokeAuthorization();
}
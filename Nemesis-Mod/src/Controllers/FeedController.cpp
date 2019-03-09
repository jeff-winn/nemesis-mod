#include "FeedController.h"

void FeedController::start() {
    if (m_isRunning) {
        return;
    }

    m_isRunning = true;
}

void FeedController::stop() {
    if (!m_isRunning) {
        return;
    }

    m_isRunning = false;
}
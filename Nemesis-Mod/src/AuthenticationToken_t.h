#ifndef AUTHENTICATION_TOKEN_T_H
#define AUTHENTICATION_TOKEN_T_H

#include <Arduino.h>

// Describes an authentication token.
struct AuthenticationToken_t {
    byte length;
    byte* data;
};

#endif
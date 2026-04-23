#pragma once

#include <cstdint>

struct RPCHeader
{
    RPCHeader(uint16_t requestId, uint16_t command) : requestId(requestId), command(command) {}
    uint16_t requestId;
    uint16_t command;
};
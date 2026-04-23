#pragma once

#include <string>

class IPCService
{
public:
    virtual ~IPCService() = default;
    virtual void log(std::string) = 0;
};
#pragma once

#include <string>

class ILogger
{
public:
    virtual void log(std::string) = 0;
    virtual ~ILogger() = default;
};
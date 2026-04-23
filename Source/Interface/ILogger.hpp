#pragma once

#include <string>

class ILogger
{
public:
    virtual void info(std::string) = 0;
    virtual void error(std::string) = 0;
    virtual ~ILogger() = default;
};
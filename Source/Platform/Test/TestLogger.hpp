#pragma once

#include "Interface/ILogger.hpp"

class TestLogger : public ILogger
{
public:
    void log(std::string);
};
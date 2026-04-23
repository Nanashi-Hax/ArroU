#pragma once

#include "Interface/ILogger.hpp"

class TestLogger : public ILogger
{
public:
    TestLogger();
    void log(std::string);
};
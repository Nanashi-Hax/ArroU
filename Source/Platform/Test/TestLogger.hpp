#pragma once

#include "Interface/ILogger.hpp"

class TestLogger : public ILogger
{
public:
    void info(std::string) override;
    void error(std::string) override;
};
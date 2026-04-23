#pragma once

#include "Interface/ILogger.hpp"

#include <format>

class Logger
{
public:
    Logger(ILogger*);

    void log(std::string);

    template<typename... Args>
    void logf(std::string_view fmt, Args&&... args)
    {
        logger->log(std::vformat(fmt, std::make_format_args(args...)));
    }

private:
    ILogger* logger;
};
#pragma once

#include "Interface/ILogger.hpp"

#include <format>

class Logger
{
public:
    Logger(ILogger*);

    void info(std::string);

    template<typename... Args>
    void infof(std::string_view fmt, Args&&... args)
    {
        logger->info(std::vformat(fmt, std::make_format_args(args...)));
    }

    void error(std::string);

    template<typename... Args>
    void errorf(std::string_view fmt, Args&&... args)
    {
        logger->error(std::vformat(fmt, std::make_format_args(args...)));
    }

private:
    ILogger* logger;
};
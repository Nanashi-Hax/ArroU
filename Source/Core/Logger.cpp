#include "Core/Logger.hpp"

Logger::Logger(ILogger* logger) : logger(logger) {}

void Logger::info(std::string msg)
{
    logger->info(msg);
}

void Logger::error(std::string msg)
{
    logger->error(msg);
}
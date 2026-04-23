#include "Core/Logger.hpp"

Logger::Logger(ILogger* logger) : logger(logger) {}

void Logger::log(std::string msg)
{
    logger->log(msg);
}
#include "App/Test/App.hpp"

App::App(IStream* stream, ILogger* logger) : stream(stream), logger(logger) {}

int App::run()
{
    logger.logf("Hello Test {}", 1);
    return 0;
}
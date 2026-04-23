#include "App/Test/App.hpp"

App::App(INetwork* network, ILogger* logger) : network(network), logger(logger) {}

int App::run()
{
    logger.logf("Hello Test {}", 1);
    return 0;
}
#include "App/Test/App.hpp"

App::App(IStream* stream, ILogger* logger) : stream(stream), logger(logger) {}

int App::run()
{
    stream.write<int>(5);
    int res;
    stream.read<int>(res);
    logger.logf("Hello Test {}", res);
    return 0;
}
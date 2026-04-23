#pragma once

#include "Interface/IStream.hpp"
#include "Core/Logger.hpp"

class App
{
public:
    App(IStream*, ILogger*);
    int run();

private:
    IStream* stream;
    Logger logger;
};
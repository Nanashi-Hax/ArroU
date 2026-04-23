#pragma once

#include "Core/Stream.hpp"
#include "Core/Logger.hpp"

class App
{
public:
    App(IStream*, ILogger*);
    int run();

private:
    Stream stream;
    Logger logger;
};
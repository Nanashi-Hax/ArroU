#pragma once

#include "Interface/INetwork.hpp"
#include "Core/Logger.hpp"

class App
{
public:
    App(INetwork*, ILogger*);
    int run();

private:
    INetwork* network;
    Logger logger;
};
#pragma once

#include "Core/Stream.hpp"
#include "Core/Logger.hpp"

#include "Interface/Service/IPCService.hpp"

class App
{
public:
    App(IStream*, ILogger*, IPCService*);
    int run();

private:
    Stream stream;
    Logger logger;
    IPCService* pc;
};
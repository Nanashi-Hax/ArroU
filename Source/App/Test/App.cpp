#include "App/Test/App.hpp"
#include "Core/RPCPC.hpp"

App::App(IStream* stream, ILogger* logger, IPCService* pc) : stream(stream), logger(logger), pc(pc) {}

int App::run()
{
    PCClient client(stream);
    PCServer server(stream);

    client.log("Hello");
    if(!server.dispatch(pc))
    {
        logger.error("dispatch failed");
        return 1;
    }

    return 0;
}
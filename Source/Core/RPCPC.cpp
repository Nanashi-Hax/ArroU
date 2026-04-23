#include "Core/RPCPC.hpp"

PCClient::PCClient(Stream& s) : stream(s) {}

void PCClient::log(std::string msg)
{
    send(PCCommand::Log, msg);
}

PCServer::PCServer(Stream& s) : stream(s) {}

void PCServer::dispatch(IPCService* service)
{
    uint16_t id;
    uint16_t cmd;

    stream.read(id);
    stream.read(cmd);

    switch(static_cast<PCCommand>(cmd))
    {
        case PCCommand::Log:
        {
            std::string msg;
            stream.read(msg);
            service->log(msg);
            break;
        }
    }
}
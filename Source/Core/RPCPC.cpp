#include "Core/RPCPC.hpp"

PCClient::PCClient(Stream& s) : stream(s) {}

void PCClient::log(std::string msg)
{
    send(PCCommand::Log, msg);
}

PCServer::PCServer(Stream& s) : stream(s) {}

bool PCServer::dispatch(IPCService* service)
{
    uint16_t id;
    uint16_t cmd;

    if (!stream.read(id)) return false;
    if (!stream.read(cmd)) return false;

    switch(static_cast<PCCommand>(cmd))
    {
        case PCCommand::Log:
        {
            std::string msg;
            if(!stream.read(msg)) return false;
            service->log(msg);
            return true;
        }

        default: return false;
    }
}
#include "Core/RPCPC.hpp"

void PCClient::log(std::string msg)
{
    send(PCCommand::Log, msg);
}

void PCServer::dispatch(IPCService& service)
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
            service.log(msg.c_str());
            break;
        }
    }
}
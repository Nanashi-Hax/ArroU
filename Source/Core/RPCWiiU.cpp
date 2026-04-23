#include "Core/RPCWiiU.hpp"

void WiiUClient::launchTitle(uint64_t title)
{
    send(WiiUCommand::LaunchTitle, title);
}

void WiiUServer::dispatch(IWiiUService& service)
{
    uint16_t id;
    uint16_t cmd;

    stream.read(id);
    stream.read(cmd);

    switch(static_cast<WiiUCommand>(cmd))
    {
        case WiiUCommand::LaunchTitle:
        {
            uint64_t title;
            stream.read(title);
            service.launchTitle(title);
            break;
        }
    }
}
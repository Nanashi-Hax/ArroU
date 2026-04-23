#include "Core/RPCWiiU.hpp"

WiiUClient::WiiUClient(Stream& s) : stream(s) {}

void WiiUClient::launchTitle(uint64_t title)
{
    send(WiiUCommand::LaunchTitle, title);
}

WiiUServer::WiiUServer(Stream& s) : stream(s) {}

void WiiUServer::dispatch(IWiiUService* service)
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
            service->launchTitle(title);
            break;
        }
    }
}
#include "Core/RPCWiiU.hpp"

WiiUClient::WiiUClient(Stream& s) : stream(s) {}

void WiiUClient::launchTitle(uint64_t title)
{
    send(WiiUCommand::LaunchTitle, title);
}

WiiUServer::WiiUServer(Stream& s) : stream(s) {}

bool WiiUServer::dispatch(IWiiUService* service)
{
    uint16_t id;
    uint16_t cmd;

    if (!stream.read(id)) return false;
    if (!stream.read(cmd)) return false;

    switch(static_cast<WiiUCommand>(cmd))
    {
        case WiiUCommand::LaunchTitle:
        {
            uint64_t title;
            if (!stream.read(title)) return false;
            service->launchTitle(title);
            return true;
        }

        default: return false;
    }
}
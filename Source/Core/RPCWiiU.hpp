#pragma once

#include "Core/Stream.hpp"
#include "Interface/Service/IWiiUService.hpp"

enum class WiiUCommand : uint16_t
{
    LaunchTitle = 0,
};

class WiiUClient
{
public:
    explicit WiiUClient(Stream& s);

    void launchTitle(uint64_t title);

private:
    template<typename... Args>
    void send(WiiUCommand cmd, Args... args)
    {
        uint16_t id = nextId++;

        stream.write(id);
        stream.write(static_cast<uint16_t>(cmd));
        (stream.write(args), ...);
    }

    Stream& stream;
    uint16_t nextId = 1;
};

class WiiUServer
{
public:
    explicit WiiUServer(Stream& s);

    void dispatch(IWiiUService* service);

private:
    Stream& stream;
};
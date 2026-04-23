#pragma once

#include "Core/Stream.hpp"
#include "Interface/Service/IPCService.hpp"

enum class PCCommand : uint16_t
{
    Log = 0,
};

class PCClient
{
public:
    explicit PCClient(Stream& s);

    void log(std::string);

private:
    template<typename... Args>
    void send(PCCommand cmd, Args... args)
    {
        uint16_t id = nextId++;

        stream.write(id);
        stream.write(static_cast<uint16_t>(cmd));
        (stream.write(args), ...);
    }

    Stream& stream;
    uint16_t nextId = 1;
};

class PCServer
{
public:
    explicit PCServer(Stream& s);

    void dispatch(IPCService* service);

private:
    Stream& stream;
};
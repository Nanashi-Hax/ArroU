#pragma once

class IPCService
{
public:
    virtual ~IPCService() = default;
    virtual void log(char const *) = 0;
};
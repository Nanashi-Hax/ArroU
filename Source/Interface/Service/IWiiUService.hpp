#pragma once

#include <cstdint>

class IWiiUService
{
public:
    virtual ~IWiiUService() = default;
    virtual void launchTitle(uint64_t) = 0;
};
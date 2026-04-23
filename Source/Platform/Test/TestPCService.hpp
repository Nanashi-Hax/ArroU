#pragma once

#include "Interface/Service/IPCService.hpp"
#include <string>

class TestPCService : public IPCService
{
public:
    void log(std::string) override;
};
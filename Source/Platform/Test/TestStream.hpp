#pragma once

#include "Interface/IStream.hpp"

#include <vector>
#include <cstdint>

class TestStream : public IStream
{
public:
    bool write(const void* data, size_t size) override;
    bool read(void* data, size_t size) override;

private:
    std::vector<uint8_t> buffer;
    size_t readPos = 0;
};
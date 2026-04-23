#pragma once

#include <cstddef>

class IStream
{
public:
    virtual ~IStream() = default;
    virtual bool write(const void* data, size_t size) = 0;
    virtual bool read(void* data, size_t size) = 0;
};
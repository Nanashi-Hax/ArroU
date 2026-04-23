#pragma once

#include "Interface/IStream.hpp"

class TestStream : public IStream
{
public:
    bool write(const void* data, size_t size);
    bool read(void* data, size_t size);

private:
    int buffer;
};
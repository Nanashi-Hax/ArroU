#include "Platform/Test/TestStream.hpp"

#include <cstring>

bool TestStream::write(const void* data, size_t size)
{
    if(size < sizeof(int)) return false;

    int value;
    std::memcpy(&value, data, sizeof(int));

    value += 1;

    buffer = value;

    return true;
}

bool TestStream::read(void* data, size_t size)
{
    if(size < sizeof(int)) return false;

    std::memcpy(data, &buffer, sizeof(int));

    return false;
}
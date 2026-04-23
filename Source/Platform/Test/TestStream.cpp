#include "Platform/Test/TestStream.hpp"

#include <cstring>

bool TestStream::write(const void* data, size_t size)
{
    const uint8_t* p = static_cast<const uint8_t*>(data);

    buffer.insert(buffer.end(), p, p + size);
    return true;
}

bool TestStream::read(void* data, size_t size)
{
    if (readPos + size > buffer.size())
        return false;

    std::memcpy(data, buffer.data() + readPos, size);
    readPos += size;

    return true;
}
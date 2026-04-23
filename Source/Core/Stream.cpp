#include "Core/Stream.hpp"

Stream::Stream(IStream* stream) : stream(stream) {}

bool Stream::write(const std::string& str)
{
    uint32_t size = static_cast<uint32_t>(str.size());
    if (!write(size)) return false;
    return stream->write(str.data(), size);
}

bool Stream::read(std::string& str)
{
    uint32_t size;
    if (!read(size)) return false;

    str.resize(size);
    return stream->read(str.data(), size);
}
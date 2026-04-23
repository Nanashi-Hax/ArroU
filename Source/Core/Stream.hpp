#pragma once

#include "Interface/IStream.hpp"
#include "Core/Endian.hpp"

class Stream
{
public:
    Stream(IStream*);

    template<typename T>
    requires std::is_trivially_copyable_v<T>
    bool write(const T& value)
    {
        T v = Endian::toNetwork(value);
        return stream->write(&v, sizeof(T));
    }

    template<typename T>
    requires std::is_trivially_copyable_v<T>
    bool read(T& value)
    {
        T v;
        if (!stream->read(&v, sizeof(T))) return false;
        value = Endian::fromNetwork(v);
        return true;
    }

private:
    IStream* stream;
};
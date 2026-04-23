#pragma once

#include "Interface/IStream.hpp"
#include "Core/Endian.hpp"

#include <string>

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

    bool write(const std::string& str);

    template<typename T>
    requires std::is_trivially_copyable_v<T>
    bool read(T& value)
    {
        T v;
        if (!stream->read(&v, sizeof(T))) return false;
        value = Endian::fromNetwork(v);
        return true;
    }

    bool read(std::string& str);

private:
    IStream* stream;
};
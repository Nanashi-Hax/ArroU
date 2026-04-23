#pragma once

#include <cstdint>
#include <cstring>
#include <bit>

namespace Endian
{
    template<typename T>
    concept EndianSafe = std::is_trivially_copyable_v<T>;

    template<typename T>
    T swapBytes(T v)
    {
        static_assert(EndianSafe<T>);

        T result;
        std::memcpy(&result, &v, sizeof(T));

        auto* bytes = reinterpret_cast<uint8_t*>(&result);

        for (size_t i = 0; i < sizeof(T) / 2; ++i)
        {
            std::swap(bytes[i], bytes[sizeof(T) - 1 - i]);
        }

        return result;
    }

    template<typename T>
    T toNetwork(T v)
    {
        if constexpr (std::endian::native == std::endian::little)
            return swapBytes(v);
        else
            return v;
    }

    template<typename T>
    T fromNetwork(T v)
    {
        return toNetwork(v);
    }
}
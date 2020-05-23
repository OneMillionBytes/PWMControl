#ifndef PWMOUT_UTIL_HPP
#define PWMOUT_UTIL_HPP

#include "stdint.h"

template <typename T>
struct Optional {
    bool valid = 0;
    T value;

    Optional(T a_value) :
        valid(true),
        value(a_value){}

        Optional() = default;
};

using ArgVal = Optional<uint32_t>;

ArgVal GetUint32Argument(
        uint8_t aArgumentPosition,
        char* aBuffer,
        uint16_t a_ui16Len);


#endif //PWMOUT_UTIL_HPP

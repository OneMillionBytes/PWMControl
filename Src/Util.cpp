#include "Util.hpp"
#include "stdlib.h"

ArgVal FindChar(uint8_t Char, char* Buf, uint16_t a_ui16Len){
    for(uint8_t i = 0; i < a_ui16Len; i++){
        if(Buf[i] == Char){
            return ArgVal(i);
        }
    }
    return ArgVal();
}

ArgVal GetUint32Argument(
        uint8_t aArgumentPosition,
        char* aBuffer,
        uint16_t a_ui16Len) {
    // find beginning of first argument
    uint16_t _begin = 0;
    for(uint8_t i = 0; i < aArgumentPosition + 1; i++){
        auto [valid, len] = FindChar(':', &aBuffer[_begin], a_ui16Len);
        if(not valid) {
            return ArgVal();
        }
        _begin += (len + 1);
        a_ui16Len -= (len + 1);
    }

    return ArgVal(atoi((char*)&aBuffer[_begin]));
}

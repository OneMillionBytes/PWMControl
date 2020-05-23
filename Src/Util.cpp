#include "Util.hpp"
#include "stdlib.h"

uint8_t FindChar(uint8_t Char, char* Buf){
    for(uint8_t i = 0; i < 255; i++){
        if(Buf[i] == Char){
            return i;
        }
    }
    return 0;
}

uint32_t GetArgument(uint8_t aArgumentPosition, char* aBuffer){
    // find beginning of first argument
    uint16_t _begin = 0;
    for(uint8_t i = 0; i < aArgumentPosition + 1; i++){
        _begin += FindChar(':', &aBuffer[_begin]);
        _begin += 1;
    }

    return atoi((char*)&aBuffer[_begin]);
}

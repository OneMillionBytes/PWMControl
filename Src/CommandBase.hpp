#ifndef PWMOUT_COMMANDBASE_HPP
#define PWMOUT_COMMANDBASE_HPP

#include "stdint.h"
#include "PWMTimer.hpp"

class CommandBase {

    const char* m_sCommandName;
    uint8_t m_ui8CommandLen;

    virtual bool _RunCommand(PWMTimer* a_poTimer, char* a_sArguments, uint8_t a_ui8ArgumentsLength) = 0;

public:

    CommandBase(const char* a_sCommandName, uint8_t a_ui8CommandLen);

    uint8_t IsCommand(char* a_sCommandName);

    void RunCommand(PWMTimer* a_poTimer, char* a_sArguments, uint8_t a_ui8ArgumentsLength);
};


#endif //PWMOUT_COMMANDBASE_HPP

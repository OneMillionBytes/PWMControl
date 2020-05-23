#include "CommandBase.hpp"
#include "string.h"

CommandBase::CommandBase(const char *a_sCommandName, uint8_t a_ui8CommandLen) :
    m_sCommandName(a_sCommandName),
    m_ui8CommandLen(a_ui8CommandLen){}

uint8_t CommandBase::IsCommand(char *a_sCommandName) {
    if(0 == strncmp(m_sCommandName, a_sCommandName, m_ui8CommandLen)) {
        return m_ui8CommandLen;
    }
    return 0;
}

void CommandBase::RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    _RunCommand(a_poTimer, a_sArguments, a_ui8ArgumentsLength);
}

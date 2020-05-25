#include "Commands.hpp"
#include "Util.hpp"
#include "string.h"
#include "stdio.h"
#include "usbd_cdc_if.h"

const char* helpString =
        "Syntax: <timer>:<command>:<argument>\n"
        "<timer> [t1,t2]\n"
        "t1........... Timer connected to A8\n"
        "t2........... Timer connected to A9\n"
        "<command>:<arguments>\n"
        "help ........ Prints this output\n"
        "start ....... starts PWM\n"
        "stop ........ stops PWM\n"
        "duty ........ sets duty cycle [0..100]\n"
        "period ...... sets the period [0..65535]\n"
        "compare ..... sets compare value [0.65535]\n"
        "prescaler ... sets the prescaler [0..65535]\n"
        "status ...... prints the current configuration\n";

const char* statusTemplate =
        "Clock: %u\n";

uint32_t status(char* const buffer) {
    return sprintf(buffer, statusTemplate, HAL_RCC_GetHCLKFreq());
}

bool StartCommand::_RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    a_poTimer->start();
    return true;
}

bool HelpCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    CDC_Transmit_FS((uint8_t *) helpString, strlen(helpString));
    return true;
}

bool StopCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    a_poTimer->stop();
    return true;
}

bool DutyCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    auto [valid, duty] = GetUint32Argument(0, a_sArguments, a_ui8ArgumentsLength);
    if(not valid) {
        return false;
    }
    a_poTimer->setDutyCycle(duty);
    return true;
}

bool PeriodCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    auto [valid, period] = GetUint32Argument(0, a_sArguments, a_ui8ArgumentsLength);
    if(not valid) {
        return false;
    }
    a_poTimer->setPeriod(period);
    return true;
}

bool CompareCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    auto [valid, compare] = GetUint32Argument(0, a_sArguments, a_ui8ArgumentsLength);
    if(not valid) {
        return false;
    }
    a_poTimer->setCompare(compare);
    return true;
}

bool PrescalerCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    auto [valid, prescaler] = GetUint32Argument(0, a_sArguments, a_ui8ArgumentsLength);
    if(not valid) {
        return false;
    }
    a_poTimer->setPrescaler(prescaler);
    return true;
}

char statusMessage[80];
bool StatusCommand::_RunCommand(PWMTimer *a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) {
    uint32_t len = status(statusMessage);

    len += a_poTimer->status(statusMessage + len);
    CDC_Transmit_FS((uint8_t *) statusMessage, len);
    return true;
}

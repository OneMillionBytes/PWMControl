#ifndef PWMOUT_PWMTIMER_HPP
#define PWMOUT_PWMTIMER_HPP

#include "stm32f1xx_hal.h"

class PWMTimer {

    TIM_HandleTypeDef& m_TimerHandle;

public:

    PWMTimer(TIM_HandleTypeDef& a_TimerHandle);

    ~PWMTimer() = default;

    void setDutyCycle(uint8_t dutyCycle);

    void setPeriod(uint16_t period);

    void setCompare(uint16_t compare);

    void setPrescaler(uint16_t prescaler);

    void start();

    void stop();

    uint16_t status(char* const buffer);
};


#endif //PWMOUT_PWMTIMER_HPP

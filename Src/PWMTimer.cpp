//
// Created by Christian Tille on 05.05.20.
//

#include "PWMTimer.hpp"

#include "stm32f1xx_hal.h"

#include "stdio.h"

const char* timerStatusTemplate =
        "Prescaler: %u\n"
        "Period: %u\n"
        "Compare: %u\n";

PWMTimer::PWMTimer(TIM_HandleTypeDef& a_TimerHandle) :
    m_TimerHandle(a_TimerHandle) {}

void PWMTimer::setDutyCycle(uint8_t dutyCycle) {
    float compare = m_TimerHandle.Instance->ARR;
    compare /= 100;
    compare *= dutyCycle;
    m_TimerHandle.Instance->CCR1 = compare - 1;
}

void PWMTimer::setPeriod(uint16_t period) {
    m_TimerHandle.Instance->ARR = period - 1;
    m_TimerHandle.Instance->CNT = 0;
}

void PWMTimer::setCompare(uint16_t compare) {
    m_TimerHandle.Instance->CCR1 = compare - 1;
}

void PWMTimer::setPrescaler(uint16_t prescaler) {
    m_TimerHandle.Instance->PSC = prescaler - 1;
}

void PWMTimer::start() {
    HAL_TIM_PWM_Start(&m_TimerHandle, TIM_CHANNEL_1);
}

void PWMTimer::stop() {
    HAL_TIM_PWM_Stop(&m_TimerHandle, TIM_CHANNEL_1);
}

uint16_t PWMTimer::status(char* const buffer) {
    return sprintf(buffer, timerStatusTemplate, m_TimerHandle.Instance->PSC, m_TimerHandle.Instance->ARR, m_TimerHandle.Instance->CCR1);
}
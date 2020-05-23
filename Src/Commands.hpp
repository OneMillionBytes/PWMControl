#ifndef PWMOUT_COMMANDS_HPP
#define PWMOUT_COMMANDS_HPP

#include "CommandBase.hpp"

class StartCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class StopCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class DutyCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class PeriodCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class CompareCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class PrescalerCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class HelpCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class StatusCommand : public CommandBase {
    void _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};
#endif //PWMOUT_COMMANDS_HPP
#ifndef PWMOUT_COMMANDS_HPP
#define PWMOUT_COMMANDS_HPP

#include "CommandBase.hpp"

class StartCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class StopCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class DutyCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class PeriodCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class CompareCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class PrescalerCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class HelpCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};

class StatusCommand : public CommandBase {
    bool _RunCommand(PWMTimer* a_poTimer, char *a_sArguments, uint8_t a_ui8ArgumentsLength) override;
public:
    using CommandBase::CommandBase;
};
#endif //PWMOUT_COMMANDS_HPP
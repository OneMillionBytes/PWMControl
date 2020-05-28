# PWMControl
**PWMControl** allows you to setup two PWM outputs by directly controlling their approprieate registers. The application is written for the STM32f103 a.k.a. BluePill but may be easily ported to other controllers of the STM32 family.  
After you've compiled and flashed the binary, jsut connect via USB-VCP, and command as you whish.  
## Features

* Two timers. Control two PWM outputs independently
* Serial over USB. Just connect via USB and go
* Extendable! Missing some features? PWMControl is easy to extend!
## Commands        
The command syntax is as follows:  
`<timer>:<command>[:<argument>]`  
where `<timer>` is the desired timer `t1`or `t2`.`<command>` and `<argument>` are described below:

|Command      | Function         | Arguments |
|---|---|---|
|`start`|Starts the timer|N/A
|`stop`|Stops timer execution|N/A
|`duty`|Sets the duty cycle|0..100|
|`period`|Sets the period|[0..65535]
|`compare`|Sets the comare value|[0..65535]
|`prescaler`|Sets the prescaler|[0..65535]
|`status`|Prints the status of the timer|N/A

Each recognized command is acknowledged with an `OK`. The only exception to this scheme is the `help`command. In order to get help, just type `help`.

## Examples
### help example
The output of help is as follows:  
```
help
OK
Syntax: <timer>:<command>[:<argument>]

<timer>...... [t1,t2]
    t1........... Timer connected to A8
    t2........... Timer connected to A9
<command>[:<arguments>]
    start ....... starts PWM
    stop ........ stops PWM
    duty ........ sets duty cycle [0..100]
    period ...... sets the period [0..65535]
    compare ..... sets compare value [0.65535]
    prescaler ... sets the prescaler [0..65535]
    status ...... prints the current configuration
```
### status example
The output of `t1:status` may look as follows:
```
t1:status
OK
Clock: 72000000
Prescaler: 0
Period: 80
Compare: 27
```

### PWM example  
In order to run timer1 with **50%** dutycycle and a period of **1ms** assuming the the clock is running at **72MHz** issue the following commands:  
```
t1:prescaler:719
OK
t1:period:99
OK
t1:compare:49
OK
t1:start
OK
```
`t1:prescaler:7199` will set the prescaler to `719`. At a clock speed of **72MHz** the timer clock will become **100kHz**. Then the period is set to `99` and compare `49`. If you are confused due to of the odd values, dont't forget that the timer values `period`, `prescaler` and `compare` are always substracted by `1`.

## Pinout
![Pinout](pinout.png)

|Pin      | Function         |
|---|---|
|PA6|Timer1 Output|
|PA8|Timer2 Output|

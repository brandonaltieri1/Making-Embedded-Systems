### What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.)

The GPIO port bit set/reset registers (GPIOx_BSRR) are the registers used by the HAL to control the state (set or reset) of all output GPIO pins.

### What are the registers that you read in order to find out the state of the button?

The GPIO port input data registers (GPIOx_IDR) are the registers that contain the state (high/low) of all GPIO input pins.

### Can you read the register directly and see the button change in a debugger or by printing out the value of the memory at the register’s address?

Yes - the state of the button can be read from the GPIOA_IDR register - i.e. the 0th bit of address `0x40020010`.

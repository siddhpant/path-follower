#pragma once

// Standard library dependencies:
#include <stdint.h>
#include <stdbool.h>


/*
Class for controlling the Mecanum wheels using Hercules motor driver.

This class is solely for providing input to wheels.
There's a separate class for abstract interfacing with Hercules motor driver.

Conn Pins can be found in the following datasheet (for a version of it):
www.nex-robotics.com/images/downloads/Hercules 6V-36V, 15Amp Motor V2.pdf

The logic table can be found on page 5.
*/

class Mecanum {
    private:
        // Using uint8_t for 0-255 range.
        uint8_t input_pin_1;
        uint8_t input_pin_2;
        uint8_t pwm_pin;
        bool inc_pwm;

    public:
        Mecanum(uint8_t, uint8_t, uint8_t, bool inc_pwm = false);

        void rotate_cw(uint8_t);
        void rotate_anti_cw(uint8_t);

        void apply_brake(uint8_t);
        void let_free(void);
}; // End of class Mecanum


// End of file

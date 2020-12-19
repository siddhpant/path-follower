#pragma once

// Standard library dependencies
#include <stdint.h>
#include <stdbool.h>


/*
Class for interfacing with a Cytron LSA 08 sensor.

Datasheet can be found on the following link:
https://wecl-stem.com/wp-content/uploads/2018/09/058-70-0011-Datasheet.pdf

We will be using it in analog o/p mode.
*/

class Lsa08 {
    private:
        uint8_t analog_output_pin;
        uint8_t junction_pulse_pin;

    public:
        Lsa08(uint8_t, uint8_t);
        uint8_t get_position(void);
        bool recieved_junction_pulse(void);
};  // End of class Lsa08


// End of file

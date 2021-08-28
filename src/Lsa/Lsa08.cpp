// Standard library dependencies:
#include <stdint.h>
#include <stdbool.h>

// Custom dependencies:
#include "Arduino.h"
#include "Lsa08.hpp"  // Contains class methods' declaration.


Lsa08::Lsa08(uint8_t analog_output_pin, uint8_t junction_pulse_pin) {
    this->analog_output_pin = analog_output_pin;
    this->junction_pulse_pin = junction_pulse_pin;

    pinMode(junction_pulse_pin, INPUT);
}  // End of Lsa08's constructor


uint8_t Lsa08::get_position(void) {
    /*
    Return line position as a value between 0 to 70 (255 if no line detected).

    We read voltage from the analog o/p pin, and convert it to value using:
            position = 70 * analog_output_pin_voltage (in V) / 4.5V

    Refer to datasheet's page 37 for more info.

    Arduino's ADC module used in analogRead converts voltages in a step to a
    10-bit number; we do not get the voltage level as it is.

    921 is the 10-bit ADC representation of 4.5V.
    */

    return (uint8_t)(70.0F * analogRead(analog_output_pin)/921.0F);
}


bool Lsa08::recieved_junction_pulse(void) {
    if (digitalRead(junction_pulse_pin)) {
        return true;
    }
    else {
        return false;
    }
}


// End of file

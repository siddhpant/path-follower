// Standard library dependencies:
#include <stdint.h>
#include <stdbool.h>

// Custom dependencies:
#include "Arduino.h"
#include "Mecanum.hpp"  // Contains class methods' declaration.


Mecanum::Mecanum(
    uint8_t input_pin_1, uint8_t input_pin_2, uint8_t pwm_pin,
    bool inc_pwm // = false by default (Default arg already in declaration)
) {
    this->input_pin_1 = input_pin_1;
    this->input_pin_2 = input_pin_2;
    this->pwm_pin = pwm_pin;
    this->inc_pwm = inc_pwm;
}  // End of Mecanum's constructor


/* To rotate clockwise */
void Mecanum::rotate_cw(uint8_t pwm) {
    digitalWrite(input_pin_1, HIGH);
    digitalWrite(input_pin_2, LOW);
    analogWrite(pwm_pin, pwm);
}


/* To rotate counter-clockwise (anti-clockwise) */
void Mecanum::rotate_anti_cw(uint8_t pwm) {
    digitalWrite(input_pin_1, LOW);
    digitalWrite(input_pin_2, HIGH);
    analogWrite(pwm_pin, pwm);
}


/* To apply brake, i.e., stop a motor */
void Mecanum::apply_brake(uint8_t pwm) {
    digitalWrite(input_pin_1, HIGH);
    digitalWrite(input_pin_2, HIGH);
    analogWrite(pwm_pin, pwm);
}


/* Don't do or supply anything and let the motor rotate freely */
void Mecanum::let_free(void) {
    digitalWrite(input_pin_1, LOW);
    digitalWrite(input_pin_2, LOW);
    analogWrite(pwm_pin, 0);
}


// End of file

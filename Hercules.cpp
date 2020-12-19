// Standard library dependencies:
#include <stdint.h>

// Custom dependencies:
#include "Hercules.hpp"  // Contains class methods' declaration.
#include "Mecanum.hpp"


// Initialise motor pointers
Hercules::Hercules(
    Mecanum* top_left, Mecanum* top_right,
    Mecanum* bottom_left, Mecanum* bottom_right
) {
    this->top_left = top_left;
    this->top_right = top_right;
    this->bottom_left = bottom_left;
    this->bottom_right = bottom_right;
}  // End of Hercules's constructor


/*
Move the bot in specified directions.

From a bird's-eye view, two motors on different sides may seem to move in a
single direction, sya forward. But the rotation of the motors are actually
opposite, as the motors are mounted differently (flipped 180 degrees)

                            < O---|     |---O >

Thus, for the example of driving forward, seeing from the axis of motor from
outside, left motor is rotating anti-clockwise while the right motor rotates
clockwise.

Function names are self-explanatory.
*/


void Hercules::lose_control(void) {  // Free-wheeling!
    top_left->let_free();
    top_right->let_free();
    bottom_left->let_free();
    bottom_right->let_free();
}


void Hercules::stop_driving(uint8_t pwm) {  // Apply brakes on all motors.
    top_left->apply_brake(pwm);
    top_right->apply_brake(pwm);
    bottom_left->apply_brake(pwm);
    bottom_right->apply_brake(pwm);
}


void Hercules::drive_forward(uint8_t pwm) {
    top_left->rotate_anti_cw(pwm);
    bottom_left->rotate_anti_cw(pwm);

    top_right->rotate_cw(pwm);
    bottom_right->rotate_cw(pwm);
}


void Hercules::drive_backward(uint8_t pwm) {
    top_left->rotate_cw(pwm);
    bottom_left->rotate_cw(pwm);

    top_right->rotate_anti_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);
}


void Hercules::drive_left(uint8_t pwm) {
    top_left->rotate_cw(pwm);
    top_right->rotate_cw(pwm);

    bottom_left->rotate_anti_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);
}


void Hercules::drive_right(uint8_t pwm) {
    top_left->rotate_anti_cw(pwm);
    top_right->rotate_anti_cw(pwm);

    bottom_left->rotate_cw(pwm);
    bottom_right->rotate_cw(pwm);
}


void Hercules::drive_top_left(uint8_t pwm) {
    top_right->rotate_cw(pwm);
    bottom_left->rotate_anti_cw(pwm);

    top_left->let_free();
    bottom_right->let_free();
}


void Hercules::drive_top_right(uint8_t pwm) {
    top_left->rotate_anti_cw(pwm);
    bottom_right->rotate_cw(pwm);

    bottom_left->let_free();
    top_right->let_free();
}


void Hercules::drive_bottom_left(uint8_t pwm) {
    top_left->rotate_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);

    top_right->let_free();
    bottom_left->let_free();
}


void Hercules::drive_bottom_right(uint8_t pwm) {
    bottom_left->rotate_cw(pwm);
    top_right->rotate_anti_cw(pwm);

    top_left->let_free();
    bottom_right->let_free();
}


void Hercules::drive_clockwise(uint8_t pwm) {
    top_left->rotate_anti_cw(pwm);
    top_right->rotate_anti_cw(pwm);
    bottom_left->rotate_anti_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);
}


void Hercules::drive_anti_clockwise(uint8_t pwm) {
    top_left->rotate_cw(pwm);
    top_right->rotate_cw(pwm);
    bottom_left->rotate_cw(pwm);
    bottom_right->rotate_cw(pwm);
}


// Sweep like a car's windshield wiper / ammeter's hand.

void Hercules::sweep_left_pivot_back(uint8_t pwm) {
    top_left->rotate_cw(pwm);
    top_right->rotate_cw(pwm);

    bottom_left->apply_brake(pwm);
    bottom_right->apply_brake(pwm);
}


void Hercules::sweep_right_pivot_back(uint8_t pwm) {
    top_left->rotate_anti_cw(pwm);
    top_right->rotate_anti_cw(pwm);

    bottom_left->apply_brake(pwm);
    bottom_right->apply_brake(pwm);
}


// Sweep like a pendulum.

void Hercules::sweep_left_pivot_front(uint8_t pwm) {
    top_left->apply_brake(pwm);
    top_right->apply_brake(pwm);

    bottom_left->rotate_anti_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);
}


void Hercules::sweep_right_pivot_front(uint8_t pwm) {
    top_left->apply_brake(pwm);
    top_right->apply_brake(pwm);

    bottom_left->rotate_cw(pwm);
    bottom_right->rotate_cw(pwm);
}


// The above but w.r.t. sides. Hopefully, the names are clear.

void Hercules::sweep_up_pivot_left(uint8_t pwm) {
    top_left->apply_brake(pwm);
    bottom_left->apply_brake(pwm);

    top_right->rotate_cw(pwm);
    bottom_right->rotate_cw(pwm);
}


void Hercules::sweep_down_pivot_left(uint8_t pwm) {
    top_left->apply_brake(pwm);
    bottom_left->apply_brake(pwm);

    top_right->rotate_anti_cw(pwm);
    bottom_right->rotate_anti_cw(pwm);
}


void Hercules::sweep_up_pivot_right(uint8_t pwm) {
    top_right->apply_brake(pwm);
    bottom_right->apply_brake(pwm);

    top_left->rotate_cw(pwm);
    bottom_left->rotate_cw(pwm);
}


void Hercules::sweep_down_pivot_right(uint8_t pwm) {
    top_right->apply_brake(pwm);
    bottom_right->apply_brake(pwm);

    top_left->rotate_anti_cw(pwm);
    bottom_left->rotate_anti_cw(pwm);
}


// End of file

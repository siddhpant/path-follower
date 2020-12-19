// Standard library dependencies
#include <stdint.h>
#include <stdbool.h>

#include "Arduino.h"

// Include custom classes
#include "Driver.hpp"
#include "Lsa08.hpp"
#include "Mecanum.hpp"

// Custom definitions
#define pwm 35


/*
LSAs are arranged in the following manner:

                                    70      0
                                  +-----------+
                                  |   LSA 1   |
                        +---------+-----------+--------+
                        |                              |
                    +---+                              +---+
                  0 | L |                              | L | 70
                    | S |                              | S |
                    | A |                              | A |
                    |   |                              |   |
                 70 | 3 |                              | 2 | 0
                    +---+                              +---+
                        |                              |
                        +------------------------------+

Setting up stuff w.r.t. an initial position taking LSA 2 as top.
*/

Mecanum top_left(24, 26, 5);  // Passed i/p and pwm pins.
Mecanum top_right(28, 30, 6);
Mecanum bottom_left(36, 38, 11);
Mecanum bottom_right(32, 34, 7);

// Passing Mecanum ptrs, LSA pins, and tell to follow using 2 sensors or not.

Driver steering_wheel_1(&bottom_left, &top_left, &bottom_right, &top_right,
                        A8, A9, false);

Driver steering_wheel_2(&top_left, &top_right, &bottom_left, &bottom_right,
                        A10, A11, true);

Driver steering_wheel_3(&bottom_right, &bottom_left, &top_right, &top_left,
                        A12, A13, true);


Driver* steering_wheel;

// Counters and stuff

unsigned int junction_counter = 0;


void setup(void) {
    Serial.begin(9600);
    steering_wheel = &steering_wheel_2;
}


void loop(void) {
    // Go forward from steering wheel's frame of reference.
    steering_wheel->follow_line(pwm);

    // Example code to turn left at a junction (provided line at left exists).

    bool junction_found = false;

    while(steering_wheel->recieved_junction_pulse()) {
        junction_found = true;
        // Let bot move somewhat ahead, do nothing.
    }

    if (junction_found) {
        junction_counter++;
        steering_wheel->stop(pwm);

        // Change frame of reference, so forward would mean another direction.
        if (junction_counter == 1) {
            steering_wheel = &steering_wheel_1;
        }
    }

    // Plan the path in a similar way, using counters, etc.
}


// End of file

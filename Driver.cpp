// Standard library dependencies:
#include <stdint.h>
#include <stdlib.h>

// Custom dependencies:
#include "Arduino.h"
#include "Driver.hpp"  // Contains class methods' declaration.
#include "Hercules.hpp"
#include "Lsa08.hpp"
#include "Mecanum.hpp"

// Custom definitions
#define range 5


Driver::Driver(
    Mecanum* top_left, Mecanum* top_right,
    Mecanum* bottom_left, Mecanum* bottom_right,
    uint8_t analog_output_pin, uint8_t junction_pulse_pin,
    bool use_two_sensors
):  // Pass params to base classes:
        Hercules(top_left, top_right, bottom_left, bottom_right),
        Lsa08(analog_output_pin, junction_pulse_pin)
{
    this->use_two_sensors = use_two_sensors;
}  // End of Driver's constructor


/* To stop driving the robot manually. */
void Driver::stop(uint8_t pwm) {
    stop_driving(pwm);
}


/* Decide here which function to call */
void Driver::follow_line(uint8_t pwm) {
    // TODO implement two sensors; For now check with one sensor only
    follow_line_with_one_sensor(&pwm);
}


/* Code to move forward using just the forward LSA.*/
void Driver::follow_line_with_one_sensor(uint8_t* pwm) {

    int position = get_position();

    if (position >= 75) {
        stop_driving(*pwm);
    }
    else if (position < 25) {
        drive_anti_clockwise(*pwm);
    }
    else if (position > 45) {
        drive_clockwise(*pwm);
    }
    else {
        drive_forward(*pwm);
    }
}  // End of follow_line_with_one_sensor()


/*
Incomplete(?) code to move forward using 2 sensors.
TODO: Incorporate the other LSA in class, and fix the following code.


void Driver::set_pos(void) {
    // Get positions and offset from middle (LSAs mounted opposite)
    up_pos = 35 - lsa_top->get_position();
    up_pos_mag = abs(up_pos);  // Magnitude
    down_pos = lsa_bottom->get_position() - 35;  // Since this at back
    down_pos_mag = abs(down_pos);
}  // End of set_pos()


void Driver::follow_line_with_two_sensors(uint8_t* pwm) {

    unsigned long time = millis();
    set_pos();


    if (up_pos_mag > 35 && down_pos_mag > 35) {
        stop_driving(*pwm);
    }

    else if ((up_pos && down_pos) || (!up_pos && !down_pos)) {
        // Both LSAs are out or in

        if (up_pos_mag <= range && down_pos_mag <= range) {
            // Both on line
            while(up_pos_mag <= range && down_pos_mag <= range) {
                drive_forward(*pwm);
                set_pos();
            }
        }

        else if ((up_pos ^ down_pos) >= 0) {
            // Same sign, so both LSAs out on same side of line

            if (up_pos < 0 && (up_pos ^ down_pos) >= 0) {
                while (up_pos < 0 && (up_pos ^ down_pos) >= 0) {
                    drive_top_right(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }

            else {
                while (up_pos > 0 && (up_pos ^ down_pos) >= 0) {
                    drive_left(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }
        }

        else if (up_pos > down_pos) {  // Slanted towards right
            while(up_pos > down_pos && (up_pos ^ down_pos) < 0) {
                drive_clockwise(*pwm);
                set_pos();
            }

            drive_forward(*pwm);
        }

        else if (down_pos > up_pos) {  // Slanted towards left
            while(down_pos > up_pos && (up_pos ^ down_pos) < 0) {
                drive_anti_clockwise(*pwm);
                set_pos();
            }

            drive_forward(pwm);
        }

        else if (up_pos_mag > range && down_pos_mag <= range) {
            // Top LSA out, bottom LSA under range

            if (up_pos > 0) {
                while(up_pos > range && down_pos_mag <= range) {
                    sweep_left_pivot_back(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }

            else {
                while(up_pos > (-1 * range) && down_pos_mag <= range) {
                    sweep_right_pivot_back(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }
        }

        else if (down_pos_mag > range && up_pos_mag <= range) {
            // Bottom LSA out, top LSA under range

            if (down_pos > 0) {
                while(down_pos > range && up_pos_mag <= range) {
                    sweep_left_pivot_front(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }

            else {
                while(down_pos > (-1 * range) && up_pos_mag <= range) {
                    sweep_right_pivot_front(*pwm);
                    set_pos();
                }

                drive_forward(*pwm);
            }
        }
    }  // End of XNOR conditional

    else if (up_pos_mag > range) {  // Top LSA out, bottom LSA on line

        if (up_pos > 0) {
            while(up_pos > range && down_pos_mag <= range) {
                sweep_left_pivot_back(*pwm);
                set_pos();
            }

            drive_forward(*pwm);
        }

        else {
            while(up_pos > (-1 * range) && down_pos_mag <= range) {
                sweep_right_pivot_back(*pwm);
                set_pos();
            }

            drive_forward(*pwm);
        }
    }

    else if (down_pos_mag > range) {  // Bottom LSA out, top LSA on line

        if (down_pos > 0) {
            while(down_pos > range && up_pos_mag <= range) {
                sweep_left_pivot_front(*pwm);
                set_pos();
            }

            drive_forward(*pwm);
        }

        else {
            while(down_pos > (-1 * range) && up_pos_mag <= range) {
                sweep_right_pivot_front(*pwm);
                set_pos();
            }

            drive_forward(*pwm);
        }
    }

    else{
        // Either up_pos or down_pos == 0, and the other < range
        drive_forward(*pwm);
    }

}  // End of follow_line_with_two_sensors()
*/


// End of file

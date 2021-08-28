#pragma once

// Standard library dependencies
#include <stdint.h>

// Custom dependencies
#include "../Mecanum/Mecanum.hpp"


/*
Class to control a simple quad-base bot using the Hercules motor driver.

Rotation of Mecanum wheels are abstracted away in a separate class.

The alignment of wheels is assumed to be the same as that of a simple car.
*/

class Hercules {
    private:
        Mecanum* top_left;
        Mecanum* top_right;
        Mecanum* bottom_left;
        Mecanum* bottom_right;

    public:
        Hercules(Mecanum*, Mecanum*, Mecanum*, Mecanum*);

        void lose_control(void);
        void stop_driving(uint8_t);

        void drive_forward(uint8_t);
        void drive_backward(uint8_t);

        void drive_left(uint8_t);
        void drive_right(uint8_t);

        void drive_top_left(uint8_t);
        void drive_top_right(uint8_t);

        void drive_bottom_left(uint8_t);
        void drive_bottom_right(uint8_t);

        void drive_clockwise(uint8_t);
        void drive_anti_clockwise(uint8_t);

        void sweep_left_pivot_back(uint8_t);
        void sweep_right_pivot_back(uint8_t);

        void sweep_left_pivot_front(uint8_t);
        void sweep_right_pivot_front(uint8_t);

        void sweep_up_pivot_left(uint8_t);
        void sweep_down_pivot_left(uint8_t);

        void sweep_up_pivot_right(uint8_t);
        void sweep_down_pivot_right(uint8_t);
};  // End of class Hercules


// End of file

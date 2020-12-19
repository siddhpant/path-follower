#pragma once

// Standard library dependencies
#include <stdint.h>
#include <stdbool.h>

// Custom dependencies
#include "Hercules.hpp"
#include "Lsa08.hpp"
#include "Mecanum.hpp"


/*
Abstracting the following of line and other related tasks to this class.

Different functions are present for following line differently.

Junction detection logic is NOT implemented here.
*/

class Driver: private Hercules, public Lsa08 {
    private:
        bool use_two_sensors;
        void follow_line_with_one_sensor(uint8_t*);
        void follow_line_with_two_sensors(uint8_t*);

    public:
        Driver(Mecanum*, Mecanum*, Mecanum*, Mecanum*, uint8_t, uint8_t, bool);
        void follow_line(uint8_t);
        void stop(uint8_t);
};


// End of file

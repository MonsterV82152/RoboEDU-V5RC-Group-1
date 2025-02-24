#include "globals.hpp"

#ifndef WING_CPP
#define WING_CPP

class mogoClamp {
    private:
        pros::ADIDigitalOut piston;
        bool wingState;
    public:
        mogoClamp()
        :  piston(PORT_mogo_clamp),
            wingState(false)
        {}
        void init() {
            piston.set_value(false);
        }
        void toggle() {
            wingState = !wingState;
            if (wingState) {
                piston.set_value(true);
            } else {
                piston.set_value(false);
            }
        }
        bool getState() {
            return wingState;
        }
};

#endif
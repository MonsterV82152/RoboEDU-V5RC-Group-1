#include "globals.hpp"

#ifndef MOGO_CPP
#define MOGO_CPP

class mogoClamp {
    private:
        pros::ADIDigitalOut piston;
        bool clampState;
    public:
        mogoClamp()
        :  piston(PORT_mogo_clamp),
            clampState(false)
        {}
        void init() {
            piston.set_value(false);
        }
        void toggle() {
            clampState = !clampState;
            if (clampState) {
                piston.set_value(true);
            } else {
                piston.set_value(false);
            }
        }
        bool getState() {
            return clampState;
        }
};

#endif
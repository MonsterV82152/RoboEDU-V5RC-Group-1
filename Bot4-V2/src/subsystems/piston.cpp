#include "globals.hpp"

#ifndef PISTON_CPP
#define PISTON_CPP

class Piston {
    private:
        pros::ADIDigitalOut *piston;
        bool state;
    public:
        Piston(pros::ADIDigitalOut *piston)
        :  piston(piston),
            state(false)
        {}
        void init() {
            piston->set_value(false);
        }
        void toggle() {
            state = !state;
            if (state) {
                piston->set_value(true);
            } else {
                piston->set_value(false);
            }
        }
        void setState(bool state) {
            this->state = state;
            if (this->state) {
                piston->set_value(true);
            } else {
                piston->set_value(false);
            }
        }
        bool getState() {
            return state;
        }

};

#endif
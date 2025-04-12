#ifndef MOGOCLAMP_CPP
#define MOGOCLAMP_CPP

#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"

class MogoClamp {
    private:
        Piston *mogoClamp;
        Intake *intake;
        
    public:
        MogoClamp(Piston *mogoClamp, Intake *intake)
            : mogoClamp(mogoClamp), intake(intake) {}
        void toggle() {
            mogoClamp->toggle();
            if (!mogoClamp->getState()) {
                intake->setOverwriteSpeed(-126,100);
            }
        }
        void setState(bool state) {
            mogoClamp->setState(state);
            if (!mogoClamp->getState()) {
                intake->setOverwriteSpeed(-126,100);
            }
        }

        bool getState() {
            mogoClamp->getState();
        }
};

#endif
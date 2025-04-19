#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"

#ifndef MOGOCLAMP_CPP
#define MOGOCLAMP_CPP

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
                pros::Task([&](){intake->setOverwriteSpeed(-560,100);});
            }
        }
        void setState(bool state) {
            mogoClamp->setState(state);
            if (!mogoClamp->getState()) {
                pros::Task([&](){intake->setOverwriteSpeed(-560,100);});
            }
        }

        bool getState() {
            mogoClamp->getState();
        }
};

#endif
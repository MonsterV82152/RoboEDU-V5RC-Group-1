#include "globals.hpp"
#include "hook.cpp"
#include "piston.cpp"

#ifndef MOGOCLAMP_CPP
#define MOGOCLAMP_CPP

class MogoClamp {
    private:
        Piston *mogoClamp;
        Hook *hook;
        pros::Distance *backDistanceR;
        pros::Distance *backDistanceL;
        bool ifMogo;
        
    public:
        MogoClamp(Piston *mogoClamp, pros::Distance *backDistanceR, pros::Distance *backDistanceL, Hook *hook)
            : mogoClamp(mogoClamp), backDistanceR(backDistanceR), backDistanceL(backDistanceL), hook(hook) {}
        void toggle() {
            mogoClamp->toggle();
            if (mogoClamp->getState() && (backDistanceR->get() < 10 && backDistanceL->get() < 10)) {
                ifMogo = true;
            } else if (!mogoClamp->getState()) {
                if (ifMogo) {
                    hook->setOverwriteSpeed(-127,2);
                }
                ifMogo = false;
            }
        }
        void setState(bool state) {
            mogoClamp->setState(state);
            if (mogoClamp->getState() && (backDistanceR->get() < 10 && backDistanceL->get() < 10)) {
                ifMogo = true;
            } else if (!mogoClamp->getState()) {
                if (ifMogo) {
                    hook->setOverwriteSpeed(-127,2);
                }
                ifMogo = false;
            }
        }

        bool hasMogo() {
            return ifMogo;
        }
};

#endif
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
        pros::Task *mogoClampTask;
        bool driverOverride;
        bool hasMogo;

        void loop(void *param) {
            while (true) {
                if (driverOverride) {
                    if (backDistanceR->get() > 80 && backDistanceL->get() > 80) {driverOverride = false; hasMogo = false;}
                    pros::delay(20);
                    continue;
                }
                if (backDistanceR->get() < 20 && backDistanceL->get() < 20 && !hasMogo) {
                    hasMogo = true;
                    mogoClamp->setState(true);
                }
                pros::delay(20);
            }
        }

    public:
        MogoClamp(Piston *mogoClamp, pros::Distance *backDistanceR, pros::Distance *backDistanceL, Hook *hook)
            : mogoClamp(mogoClamp), backDistanceR(backDistanceR), backDistanceL(backDistanceL), hook(hook), mogoClampTask(nullptr), driverOverride(false) {}
        void toggle() {
            mogoClamp->toggle();
            driverOverride = true;
            if (mogoClamp->getState() && (backDistanceR->get() < 10 && backDistanceL->get() < 10)) {
                hasMogo = true;
            } else if (!mogoClamp->getState()) {
                if (hasMogo) {
                    hook->setOverwriteSpeed(-127,2);
                }
                hasMogo = false;
            }
        }
        void init() {
            mogoClampTask = new pros::Task([this] { loop(nullptr); });
            mogoClampTask->suspend();
        }
        void start() {
            if (mogoClampTask == nullptr) {
                mogoClampTask = new pros::Task([this] { loop(nullptr); });
            } else {
                mogoClampTask->resume();
            }
        }

        void stop() {
            if (mogoClampTask != nullptr) {
                mogoClampTask->suspend();
            }
        }

        ~MogoClamp() {
            if (mogoClampTask != nullptr) {
                mogoClampTask->remove();
                delete mogoClampTask;
            }
        }
};

#endif
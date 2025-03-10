#include "globals.hpp"
#include "hook.cpp"
#include "intake.cpp"
#include "ladyBrown.cpp"
#include "colourSorter.cpp"
#include "mogoClamp.cpp"

#ifndef CONTROLS_CPP
#define CONTROLS_CPP

class Controls {
    private:
        pros::Task *task = nullptr;
        Intake *intake;
        Hook *hook;
        LadyBrown *ladyBrown;
        ColourSorter *colourSorter;
        MogoClamp *mogoClamp;
        pros::Controller *master;
        int LadyBrownState = 0;

        void updateAll(void *param) {
            while (true) {
                hook->update();
                intake->update();
                ladyBrown->update();
                pros::delay(20); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
    /**
     * @brief Construct a new Controls object
     * @param intake Intake object
     * @param hook Hook object
     * @param ladyBrown LadyBrown object
     * @param colourSorter ColourSorter object
     * @param mogoClamp MogoClamp object
     * @param master Controller object
     */
        Controls(Intake *intake, Hook *hook, LadyBrown *ladyBrown, ColourSorter *colourSorter, MogoClamp *mogoClamp, pros::Controller *master) : intake(intake), hook(hook), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), master(master) {
        }
        void driverControls() {
            chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital(Controller::button_L2)) {
                hook->setOverwriteSpeed(-127);
                intake->setOverwriteSpeed(-127);
            } else {
                if (hook->getOverwriteSpeed() == -127) {
                    hook->clearOverwrite();
                    intake->clearOverwrite();
                }
            }
            if (master->get_digital_new_press(Controller::button_R1)) {
                if (intake->getDefaultSpeed() > 0) intake->setSpeed(0);
                else intake->setSpeed(127);
            }
            if (master->get_digital_new_press(Controller::button_R2)) {
                if (hook->getDefaultSpeed() > 0) hook->setSpeed(0);
                else hook->setSpeed(127); intake->setSpeed(127);
            }

            if (master->get_digital_new_press(Controller::button_DOWN)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::LOADING) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::LOADING);
                } else {
                    ladyBrown->setSetPoint(0);
                }
            } 
            if (master->get_digital_new_press(Controller::button_B)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::SCORING) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::SCORING);
                } else {
                    ladyBrown->setSetPoint(0);
                }
            }
            if (master->get_digital_new_press(Controller::button_X)) {
                mogoClamp->toggle();
            }
            if (master->get_digital_new_press(Controller::button_RIGHT)) {
                if (colourSorter->isRunning()) {
                    colourSorter->stop();
                } else {
                    colourSorter->start();
                }
            }

        }
        void init() {
            task = new pros::Task([this] { updateAll(nullptr); });
            task->suspend();
        }
        void start() {
            if (task == nullptr) {
                task = new pros::Task([this] { updateAll(nullptr); });
            } else {
                task->resume();
            }
        }

        void stop() {
            if (task != nullptr) {
                task->suspend();
            }
        }

        ~Controls() {
            if (task != nullptr) {
                task->remove();
                delete task;
            }
        }
};

#endif
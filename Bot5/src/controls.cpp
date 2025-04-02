#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"
#include "ladyBrown.cpp"
#include "colourSorter.cpp"
#include "mogoClamp.cpp"

#ifndef CONTROLS_CPP
#define CONTROLS_CPP

class Controls {
    private:
        pros::Task *task = nullptr;
        Intake *intake;
        LadyBrown *ladyBrown;
        ColourSorter *colourSorter;
        MogoClamp *mogoClamp;
        Piston *doinker;
        pros::Controller *master;
        int LadyBrownState = 0;

        void updateAll(void *param) {
            while (true) {
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
        Controls(Intake *intake, LadyBrown *ladyBrown, ColourSorter *colourSorter, MogoClamp *mogoClamp, Piston *doinker, pros::Controller *master) : intake(intake), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), doinker(doinker), master(master) {
        }
        void driverControls() {
            chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital(Controller::button_L1)) {
                intake->setOverwriteSpeed(-127);
            } else {
                if (intake->getOverwriteSpeed() == -127) {
                    intake->clearOverwrite();
                }
            }
            if (master->get_digital_new_press(Controller::button_L2)) {
                doinker->toggle();
            }
            if (master->get_digital_new_press(Controller::button_R2)) {
                if (intake->getDefaultSpeed() > 0) intake->setSpeed(0);
                else {intake->setSpeed(127); intake->clearAllOverwrites();}
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
                if (colourSorter->isSorting()) {
                    colourSorter->setSorting(false);
                } else {
                    colourSorter->setSorting(true);
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
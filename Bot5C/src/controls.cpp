#ifndef CONTROLS_CPP
#define CONTROLS_CPP

#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"
#include "ladyBrown.cpp"
#include "hookTasks.cpp"
#include "mogoClamp.cpp"

class Controls {
    private:
        pros::Task *task = nullptr;
        Intake *intake;
        LadyBrown *ladyBrown;
        HookTasks *colourSorter;
        MogoClamp *mogoClamp;
        Piston *doinker;
        pros::Controller *master;
        Piston *tierThree;
        int LadyBrownState = 0;

        void updateAll(void *param) {
            while (true) {
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
        Controls(Intake *intake, LadyBrown *ladyBrown, HookTasks *colourSorter, MogoClamp *mogoClamp, Piston *doinker, Piston *tierThree, pros::Controller *master) : intake(intake), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), doinker(doinker), tierThree(tierThree), master(master) {
        }
        void driverControls() {
            if (driverTrain) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            // if (master->get_digital_new_press(Controller::button_R1)) {
            //     pros::Task([&]() {
            //         ladyBrown->setSetPoint(LadyBrownConfigs::SCORING);
            //         ladyBrown->waitUntilAtSetpoint(500);
            //         ladyBrown->setSetPoint(LadyBrownConfigs::LOADING);
            //         ladyBrown->waitUntilAtSetpoint(500);
            //         intake->setSpeed(127);
            //         while (Manipulator::dist.get_distance() > 30) {
            //             pros::delay(10);
            //         }
            //         pros::delay(100);
            //         intake->setSpeed(0);
            //         ladyBrown->setSetPoint(LadyBrownConfigs::SCORING);
            //         ladyBrown->waitUntilAtSetpoint(500);
            //         ladyBrown->setSetPoint(0);

            //     });
            // }
            if (master->get_digital_new_press(Controller::button_UP)) {
                pros::Task([&]() {
                    driverTrain = false;
                    chassis.setPose(0,0,0);
                    chassis.moveToPoint(0,-7.5,700,{false});
                    chassis.waitUntilDone();
                    driverTrain = true;
                });
            }
            if (master->get_digital(Controller::button_L1)) {
                intake->setOverwriteSpeed(-600);
            } else {
                if (intake->getOverwriteSpeed() == -600) {
                    intake->clearOverwrite();
                }
            }
            if (master->get_digital_new_press(Controller::button_L2)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::ALLIANCE) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::ALLIANCE);
                } else {
                    ladyBrown->setSetPoint(0);
                };
            }
            if (master->get_digital_new_press(Controller::button_A)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::HOLD) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::HOLD);
                } else {
                    ladyBrown->setSetPoint(0);
                };
            }
            // Make a button that cycles through descore ladybrown states
            if (master->get_digital_new_press(Controller::button_Y)) {
                if (ladyBrown->getSetPoint() == LadyBrownConfigs::DESCORE4) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::DESCORE5);
                } else if (ladyBrown->getSetPoint() == LadyBrownConfigs::DESCORE3) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::DESCORE4);
                } else if (ladyBrown->getSetPoint() == LadyBrownConfigs::DESCORE2) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::DESCORE3);
                } else if (ladyBrown->getSetPoint() == LadyBrownConfigs::DESCORE1) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::DESCORE2);
                } else if (ladyBrown->getSetPoint() != LadyBrownConfigs::DESCORE1) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::DESCORE1);
                }
            }
            if (master->get_digital_new_press(Controller::button_R2)) {
                if (intake->getDefaultSpeed() > 0) intake->setSpeed(0);
                else {intake->setSpeed(600); intake->clearAllOverwrites();}
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
            // if (master->get_digital(Controller::button_X)) {
            //     ladyBrown->setVelocity(-127);
            // } else if (master->get_digital(Controller::button_DOWN)) {
            //     ladyBrown->setVelocity(127);
            // } else {
            //     ladyBrown->setVelocity(0);
            // }
            if (master->get_digital_new_press(Controller::button_X)) {
                mogoClamp->toggle();
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
#ifndef CONTROLS_CPP
#define CONTROLS_CPP

#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"
#include "ladyBrown.cpp"
#include "hookTasks.cpp"
#include "mogoClamp.cpp"

#define driveBack pros::Task([&](){moveChassis = false; chassis.arcade(-50,0); pros::delay(220); chassis.arcade(10,0); pros::delay(50); moveChassis = true;})

class Controls {
    private:
        pros::Task *task = nullptr;
        Intake *intake;
        LadyBrown *ladyBrown;
        HookTasks *colourSorter;
        MogoClamp *mogoClamp;
        Piston *doinker;
        pros::Controller *master;
        pros::Controller *slave;
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
        Controls(Intake *intake, LadyBrown *ladyBrown, HookTasks *colourSorter, MogoClamp *mogoClamp, Piston *doinker, pros::Controller *master, pros::Controller *slave) : intake(intake), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), doinker(doinker),  master(master), slave(slave) {
        }
        
        void driverControls() {
            if (moveChassis) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital_new_press(Controller::button_LEFT)) {
                colourSorter->setSorting(!colourSorter->isSorting());
            }
            if (master->get_digital_new_press(Controller::button_UP)) {
                doinker->toggle();
            }
            if (master->get_digital(Controller::button_X)) {
                intake->setOverwriteSpeed(-600);
            } else {
                if (intake->getOverwriteSpeed() == -600) {
                    intake->clearOverwrite();
                }
            }
            if (master->get_digital_new_press(Controller::button_RIGHT)) {
                colourSorter->holdNextRing();
            }
            if (master->get_digital_new_press(Controller::button_L2)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::MOGOTIP) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::MOGOTIP);
                } else {
                    ladyBrown->setSetPoint(0);
                };
            }
            if (master->get_digital_new_press(Controller::button_A)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::ALLIANCE) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::ALLIANCE);
                } else {
                    ladyBrown->setSetPoint(0);
                };
            }
            if (master->get_digital_new_press(Controller::button_L1)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::HOLD) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::HOLD);
                } else {
                    ladyBrown->setSetPoint(0);
                };
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
            if (master->get_digital_new_press(Controller::button_R1)) {
                mogoClamp->toggle();
            }

            if (master->get_digital_new_press(Controller::button_Y)) {
                moveChassis = false;
                chassis.setPose(0,0,0);
                chassis.moveToPoint(0,-8, 1000,{false});
                pros::delay(400);
                ladyBrown->setSetPoint(LadyBrownConfigs::ALLIANCE);
                chassis.waitUntilDone();
                moveChassis = true;
                
            }
        }
        void programmerControls() {
            if (moveChassis) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital_new_press(Controller::button_R1)) {
                correct_position(rightSensor, &chassis, true, true);
            }
            if (master->get_digital_new_press(Controller::button_R2)) {
                correct_position(rightSensor, &chassis, false, true);
            }
            if (master->get_digital_new_press(Controller::button_L1)) {
                correct_position(leftSensor, &chassis, true, true);
            }
            if (master->get_digital_new_press(Controller::button_L2)) {
                correct_position(leftSensor, &chassis, false, true);
            }
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
        void slaveControls() {
            if (slave->get_digital_new_press(Controller::button_Y)) {
                colourSorter->setSorting(!colourSorter->isSorting());
                if (colourSorter->isSorting()) {
                    slave->print(1, 0, "C");
                } else {
                    slave->print(1,0," ");
                }
            }
            
        }
        
        
    };

#endif
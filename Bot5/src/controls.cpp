#ifndef CONTROLS_CPP
#define CONTROLS_CPP

#include "globals.hpp"
#include "intake.cpp"
#include "piston.cpp"
#include "ladyBrown.cpp"
#include "colourSorter.cpp"
#include "mogoClamp.cpp"

#define driveBack pros::Task([&](){moveChassis = false; chassis.arcade(-50,0); pros::delay(220); chassis.arcade(10,0); pros::delay(50); moveChassis = true;})

class Controls {
    private:
        pros::Task *task = nullptr;
        Intake *intake;
        LadyBrown *ladyBrown;
        ColourSorter *colourSorter;
        MogoClamp *mogoClamp;
        Piston *doinker;
        pros::Controller *master;
        Piston *tierThree;
        Piston *PTO;
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
        Controls(Intake *intake, LadyBrown *ladyBrown, ColourSorter *colourSorter, MogoClamp *mogoClamp, Piston *doinker, Piston *tierThree, pros::Controller *master, Piston *PTO) : intake(intake), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), doinker(doinker), tierThree(tierThree), master(master), PTO(PTO) {
        }
        
        void driverControls() {
            if (moveChassis) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital(Controller::button_L1)) {
                intake->setOverwriteSpeed(-127);
            } else {
                if (intake->getOverwriteSpeed() == -127) {
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

            if (master->get_digital_new_press(Controller::button_UP)) {
                
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
        void climbControlsNOMACROS() {
            if (moveChassis) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital(Controller::button_UP)) {
                ladyBrown->setVelocity(127);
            } else if (master->get_digital(Controller::button_DOWN)) {
                ladyBrown->setVelocity(-127);
            } else {
                ladyBrown->setVelocity(0);
            }
            if (master->get_digital_new_press(Controller::button_L2)) {
                tierThree->toggle();
            }
            if (master->get_digital_new_press(Controller::button_L1)) {
                PTO->toggle();
            }
            // Code intake controls
            if (master->get_digital(Controller::button_R1)) {
                intake->setOverwriteSpeed(-127);
            } else {
                if (intake->getOverwriteSpeed() == -127) {
                    intake->clearOverwrite();
                }
            }
            if (master->get_digital_new_press(Controller::button_R2)) {
                if (intake->getDefaultSpeed() > 0) intake->setSpeed(0);
                else {intake->setSpeed(127); intake->clearAllOverwrites();}
            }
            
        }
        void climbControlsMacro() {
            if (moveChassis && !isClimbing && !safeMode) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (!safeMode) {
                if (master->get_digital_new_press(Controller::button_UP)) {
                    safeMode = true;
                    moveChassis = false;
                    PTO->setState(false);
                    ladyBrown->setSetPoint(LadyBrownConfigs::SCORING);
                    ladyBrown->waitUntilAtSetpoint();
                    tierThree->setState(true);
                    pros::delay(500);
                    ladyBrown->setSetPoint(LadyBrownConfigs::HOLD);
                    PTO->setState(true);
                    chassis.arcade(-50,0);
                    ladyBrown->waitUntilAtSetpoint(800);
                    chassis.arcade(0,0);
                    safeMode = false;
                }
                if (master->get_digital(Controller::button_DOWN)) {
                    moveChassis = false;
                    if (OdometryConfigs::IMU.get_accel().z > 1 && tierThree->getState()) {
                        tierThree->setState(false);
                    }
                    isClimbing = true; 
                    chassis.setBrakeMode(MotorConfigs::HOLD);
                    ladyBrown->setVelocity(-127);
                    chassis.arcade(-127,OdometryConfigs::IMU.get_pitch());
                } else if (master->get_digital_new_press(Controller::button_Y)) {
                    isClimbing = false;
                    moveChassis = true;
                    chassis.setBrakeMode(MotorConfigs::COAST);
                } else if (isClimbing) {
                    chassis.arcade(0,0);
                }
                
                if (master->get_digital(Controller::button_R1)) {
                    ladyBrown->setVelocity(127);
                } else if (master->get_digital(Controller::button_R2)) {
                    ladyBrown->setVelocity(-127);
                } else {
                    ladyBrown->setVelocity(0);
                }
                if (master->get_digital_new_press(Controller::button_L2)) {
                    tierThree->toggle();
                }
                if (master->get_digital_new_press(Controller::button_L1)) {
                    PTO->toggle();
                    if (PTO->getState()) {
                        moveChassis = false;
                    } else {
                        moveChassis = true;
                    }
                }
            }


        }
        
        
    };

#endif
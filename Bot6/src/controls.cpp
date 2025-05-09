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
        Controls(Intake *intake, LadyBrown *ladyBrown, HookTasks *colourSorter, MogoClamp *mogoClamp, Piston *doinker, Piston *tierThree, pros::Controller *master, pros::Controller *slave, Piston *PTO) : intake(intake), ladyBrown(ladyBrown), colourSorter(colourSorter), mogoClamp(mogoClamp), doinker(doinker), tierThree(tierThree), master(master), slave(slave), PTO(PTO) {
        }
        
        void driverControls() {
            if (!climbControls) {
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
                    tierThree->toggle();
                    // if (ladyBrown->getSetPoint() != LadyBrownConfigs::ALLIANCE) {
                    //     ladyBrown->setSetPoint(LadyBrownConfigs::ALLIANCE);
                    // } else {
                    //     ladyBrown->setSetPoint(0);
                    // };
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
        }
        void programmerControls() {
            if (moveChassis) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (master->get_digital_new_press(Controller::button_A)) {
                tierThree->toggle();
            }
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
            if (master->get_digital_new_press(Controller::button_B)) {
                if (ladyBrown->getSetPoint() != LadyBrownConfigs::TEST) {
                    ladyBrown->setSetPoint(LadyBrownConfigs::TEST);
                } else {
                    ladyBrown->setSetPoint(0);
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
        void slaveControls() {
            if (slave->get_digital_new_press(Controller::button_A)) {
                climbControls = !climbControls;
                if (climbControls) {
                    slave->rumble(".");
                } else {
                    master->rumble(".");
                }
            }
            if (slave->get_digital_new_press(Controller::button_X)) {
                climbControls = true;
                moveChassis = false;
                isClimbing = true;
                chassis.setBrakeMode(MotorConfigs::BRAKE);
                chassis.setPose(0,0,0);
                chassis.moveToPoint(0,6,500);
                chassis.waitUntilDone();
                ladyBrown->setSetPoint(260,true);
                ladyBrown->waitUntilAtSetpoint();
                tierThree->setState(true);
                chassis.moveToPoint(0,0,500,{false});
                chassis.waitUntilDone();
                PTO->setState(true);
                ladyBrown->setVelocity(10);
                chassis.arcade(-100,OdometryConfigs::IMU.get_pitch()*16);
                pros::delay(300);

                while ((abs(DriveTrain::left.get_actual_velocity())+abs(DriveTrain::right.get_actual_velocity()))/2 > 2 || abs(OdometryConfigs::IMU.get_roll()) > 20 || ladyBrown->getPosition() > 120) {
                    chassis.arcade(-127,OdometryConfigs::IMU.get_pitch()*16);
                    pros::delay(50);
                }
                ladyBrown->setSetPoint(0);
                tierThree->setState(false);
                pros::delay(200);
                for (double i = 10; i--; i > 0) {
                    chassis.arcade(-10*i,OdometryConfigs::IMU.get_pitch()*2);
                    pros::delay(50);
                }
                chassis.setBrakeMode(MotorConfigs::COAST);
                chassis.arcade(0,0);
                pros::delay(500);
                while (!slave->get_digital_new_press(Controller::button_X)) {
                    pros::delay(20);
                }
                ladyBrown->setSetPoint(290,true);
                chassis.arcade(50,0);
                PTO->setState(false);
                ladyBrown->waitUntilAtSetpoint();
                chassis.arcade(0,0);
                tierThree->setState(true);
                pros::delay(500);
                ladyBrown->setVelocity(10);
                PTO->setState(true);
                pros::delay(200);
                chassis.arcade(-127,OdometryConfigs::IMU.get_pitch()*2);
                pros::delay(200);
                while ((abs(DriveTrain::left.get_actual_velocity())+abs(DriveTrain::right.get_actual_velocity()))/2 > 10 || abs(OdometryConfigs::IMU.get_roll()) > 20) {
                    chassis.arcade(-127,OdometryConfigs::IMU.get_pitch()*2);
                    pros::delay(50);
                }
                tierThree->setState(false);
                pros::delay(200);
                for (double i = 10; i--; i > 0) {
                    chassis.arcade(-10*i,OdometryConfigs::IMU.get_pitch()*2);
                    pros::delay(50);
                }
                chassis.setBrakeMode(MotorConfigs::COAST);
                chassis.arcade(0,0);
                pros::delay(500);
                while (!slave->get_digital_new_press(Controller::button_X)) {
                    pros::delay(20);
                }
                ladyBrown->setSetPoint(290,true);
                chassis.arcade(50,0);
                PTO->setState(false);
                ladyBrown->waitUntilAtSetpoint();
                chassis.arcade(0,0);
                tierThree->setState(true);
                pros::delay(500);
                ladyBrown->setVelocity(10);
                PTO->setState(true);
                pros::delay(200);
                chassis.arcade(-127,OdometryConfigs::IMU.get_pitch()*2);
                pros::delay(200);
                while ((abs(DriveTrain::left.get_actual_velocity())+abs(DriveTrain::right.get_actual_velocity()))/2 > 10 || abs(OdometryConfigs::IMU.get_roll()) > 20) {
                    chassis.arcade(-127,OdometryConfigs::IMU.get_pitch()*2);
                    pros::delay(50);
                }
                tierThree->setState(false);
                pros::delay(200);
                for (double i = 10; i--; i > 0) {
                    chassis.arcade(-10*i,OdometryConfigs::IMU.get_pitch()*2);
                    pros::delay(50);
                }
                chassis.setBrakeMode(MotorConfigs::COAST);
                chassis.arcade(0,0);
                pros::delay(500);







            }
            if (climbControls) {
                if (moveChassis) chassis.arcade(slave->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), slave->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
                if (isClimbing) chassis.arcade(slave->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), OdometryConfigs::IMU.get_pitch());
                if (slave->get_digital_new_press(Controller::button_Y)) {
                    moveChassis = !moveChassis;
                    isClimbing = !isClimbing;
                }
                if (slave->get_digital(Controller::button_UP)) {
                    ladyBrown->setVelocity(127);
                } else if (slave->get_digital(Controller::button_DOWN)) {
                    ladyBrown->setVelocity(-127);
                } else {
                    ladyBrown->setVelocity(0);
                }
                if (slave->get_digital_new_press(Controller::button_L2)) {
                    tierThree->toggle();
                }
                if (slave->get_digital_new_press(Controller::button_L1)) {
                    PTO->toggle();
                }
                // Code intake controls
                if (slave->get_digital(Controller::button_R1)) {
                    intake->setOverwriteSpeed(-127);
                } else {
                    if (intake->getOverwriteSpeed() == -127) {
                        intake->clearOverwrite();
                    }
                }
                if (slave->get_digital_new_press(Controller::button_R2)) {
                    if (intake->getDefaultSpeed() > 0) intake->setSpeed(0);
                    else {intake->setSpeed(600); intake->clearAllOverwrites();}
                }
            }
            
            
        }
        void climbControlsMacro() {
            if (moveChassis && !isClimbing && !safeMode) chassis.arcade(master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), false, 0.54);
            if (!safeMode) {
                if (master->get_digital_new_press(Controller::button_UP)) {
                    safeMode = true;
                    moveChassis = false;
                    chassis.arcade(100,0);
                    ladyBrown->setSetPoint(LadyBrownConfigs::SCORING, true);
                    ladyBrown->waitUntilAtSetpoint();
                    tierThree->setState(true);
                    pros::delay(500);
                    ladyBrown->setSetPoint(LadyBrownConfigs::HOLD, true);
                    PTO->setState(true);
                    chassis.arcade(-50,0);
                    ladyBrown->waitUntilAtSetpoint(800);
                    chassis.arcade(0,0);
                    safeMode = false;
                }
                if (master->get_digital_new_press(Controller::button_X)) {
                    safeMode = true;
                    moveChassis = false;
                    PTO->setState(false);
                    ladyBrown->setSetPoint(LadyBrownConfigs::SCORING, true);
                    ladyBrown->waitUntilAtSetpoint();
                    tierThree->setState(true);
                    pros::delay(500);
                    ladyBrown->setSetPoint(LadyBrownConfigs::HOLD, true);
                    PTO->setState(true);
                    chassis.arcade(-50,0);
                    ladyBrown->waitUntilAtSetpoint(800);
                    chassis.arcade(0,0);
                    safeMode = false;
                }
                if (master->get_digital(Controller::button_DOWN)) {
                    moveChassis = false;
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
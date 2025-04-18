#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

// void redNeg() {
//     chassis.setPose(-60,13.5,225);
//     ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
//     ladyBrown.waitUntilAtSetpoint(1000);
//     chassis.moveToPoint(-24,24,1000);
//     ladyBrown.setSetPoint(0);
//     chassis.waitUntilDone();
//     mogoClamp.setState(true);
//     intake.setSpeed(127);
//     chassis.turnToPoint(-4,45, 700);
//     chassis.moveToPoint(-4,45, 700);
//     chassis.turnToPoint(-4,51, 700);
//     chassis.moveToPoint(-4,51, 700);
//     chassis.moveToPoint(-4,45, 700, {false});
//     chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000);
//     chassis.moveToPoint(-24,48, 700);
//     chassis.moveToPoint(-48,48, 700);
//     chassis.turnToPoint(-70,70, 700);
//     ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
//     chassis.moveToPoint(-70,70,1000);
//     chassis.moveToPoint(-48,48,700,{false});
//     chassis.moveToPoint(-60,60,700);
//     ladyBrown.setSetPoint(0);
//     chassis.moveToPoint(-48,48,700,{false});
//     chassis.moveToPoint(-48,-12,1000);
// }

void redNeg() {
    chassis.setPose(-145,25,225);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-60,60,1000);
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    chassis.turnToPoint(-4,45, 700);
    chassis.moveToPoint(-4,45, 700);
    chassis.turnToPoint(-4,51, 700);
    chassis.moveToPoint(-4,51, 700);
    chassis.moveToPoint(-4,45, 700, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000);
    chassis.moveToPoint(-24,48, 700);
    chassis.moveToPoint(-48,48, 700);
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(-70,70,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-60,60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-48,-12,1000);
}


// void redPos() {
//     chassis.setPose(-48, -36, 105);
//     ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
//     chassis.moveToPoint(-17, -43,700);
//     pros::delay(369);
//     intake.setSpeed(127);
//     ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
//     chassis.moveToPoint(-24, -52, 700, {false});
//     intake.stop();
    // chassis.turnToPoint(-24, -24, 700, {false});
//     ladyBrown.setSetPoint(0);
//     chassis.moveToPoint(-24, -24, 700,{false});
//     chassis.waitUntilDone();
//     mogoClamp.setState(true);
//     intake.setSpeed(127);
// }

void redPos(){
    chassis.setPose(-56, -58, 90);
    intake.setSpeed(127);
    chassis.moveToPoint(-9, -54, 700);
    chassis.waitUntilDone();
    doinker.setState(true);
    pros::delay(380);
    intake.stop();
    chassis.moveToPoint(-26, -47, 700, {false});
    pros::delay(420);
    doinker.setState(false);
    chassis.waitUntilDone();
    chassis.turnToPoint(-12, -27, 700, {false});
    chassis.moveToPoint(-12, -30, 700, {false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    chassis.turnToPoint(-50, -35, 700, {false});
    chassis.moveToPoint(-50, -35, 700, {false});
    pros::delay(300);
    mogoClamp.setState(false);
    chassis.waitUntilDone();
    chassis.turnToPoint(-45, -125, 700, {false});



}

#endif
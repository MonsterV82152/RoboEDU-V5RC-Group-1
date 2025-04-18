#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

void redNeg() {
    chassis.setPose(-56,13.8,225);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-24,24,1000,{false});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(-4,45, 700);
    chassis.moveToPoint(-4,45, 700);
    chassis.turnToPoint(-4,51, 700);
    chassis.moveToPoint(-4,51, 700);
    chassis.moveToPoint(-4,45, 700, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000);
    chassis.moveToPoint(-24,48, 300);
    chassis.moveToPoint(-48,48, 700);
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(-70,70,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-60,60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-12,12,1000,{false});
    // chassis.moveToPoint(-48,-12,1000);
}

void redPos() {
    chassis.setPose(-48, -36.5, 105);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-17, -43,700);
    pros::delay(300);
    intake.setSpeed(127);
    pros::delay(100);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(-24, -48, 700, {false});
    intake.stop();
    chassis.turnToPoint(-24, -24, 700, {false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-24, -24, 700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(-70,-70,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(-70,-70,1200);
    chassis.moveToPoint(-48,-48,700,{false});
    chassis.moveToPoint(-60,-60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-12,-12,1000,{false});
}

void blueNeg() {
    chassis.setPose(60,13.5,135);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(24,24,1000);
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(4,45, 700);
    chassis.moveToPoint(4,45, 700);
    chassis.turnToPoint(4,51, 700);
    chassis.moveToPoint(4,51, 700);
    chassis.moveToPoint(4,45, 700, {false});
    chassis.swingToPoint(24,48, lemlib::DriveSide::LEFT, 1000);
    chassis.moveToPoint(24,48, 300);
    chassis.moveToPoint(48,48, 700);
    chassis.turnToPoint(70,70, 700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(70,70,1000);
    chassis.moveToPoint(48,48,700,{false});
    chassis.moveToPoint(60,60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(12,12,1000,{false});
}

void bluePos() {
    chassis.setPose(48, -36.5, 255);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(17, -43,700);
    pros::delay(300);
    intake.setSpeed(127);
    pros::delay(100);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(24, -48, 700, {false});
    intake.stop();
    chassis.turnToPoint(24, -24, 700, {false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(24, -24, 700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(70,-70,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(70,-70,1200);
    chassis.moveToPoint(48,-48,700,{false});
    chassis.moveToPoint(60,-60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(12,-12,1000,{false});
}

void redSAWP() {
    team = true;
    chassis.setPose(-56.2, 14.4, 225);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-24,24,1000,{false});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(-4,45, 700);
    chassis.moveToPoint(-4,45, 1000);
    chassis.turnToPoint(-4,51, 700);
    chassis.moveToPoint(-4,51, 1000);
    chassis.moveToPoint(-4,45, 1000, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000);
    chassis.moveToPoint(-24,48, 500);
    chassis.moveToPoint(-48,48, 700);
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(200);
    chassis.moveToPoint(-70,70,700);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-60,60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-48,48,700,{false});
}

#endif
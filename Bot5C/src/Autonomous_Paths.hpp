#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

void redNeg() {
    chassis.setPose(-57,13,225);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(100);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-48,24,700,{false});
    chassis.turnToPoint(-24,20, 400,{false});
    chassis.moveToPoint(-35,20, 700, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(-20,20,700,{.forwards = false, .maxSpeed = 30});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-11,30, 700);
    chassis.moveToPoint(-11,30, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-7,53, 700);
    chassis.moveToPoint(-7,35, 1000, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 300);
    chassis.moveToPoint(-48,48, 700);
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(-70,70,1000);
    chassis.moveToPoint(-48,48,600,{false});
    chassis.moveToPoint(-65,65,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.turnToPoint(-48,-12, 700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-48,24,700,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-48,-12,1000, {.maxSpeed = 50});
}

void redPos() {
    chassis.setPose(-48, -36.5, 105);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-17, -43,700);
    pros::delay(300);
    intake.setSpeed(600);
    pros::delay(100);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(-24, -48, 700, {false});
    intake.stop();
    chassis.turnToPoint(-24, -24, 700, {false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-24, -24, 700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
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
    intake.setSpeed(600);
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
    intake.setSpeed(600);
    pros::delay(100);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(24, -48, 700, {false});
    intake.stop();
    chassis.turnToPoint(24, -24, 700, {false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(24, -24, 700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(70,-70,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    chassis.moveToPoint(70,-70,1200);
    chassis.moveToPoint(48,-48,700,{false});
    chassis.moveToPoint(60,-60,700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(12,-12,1000,{false});
}

void blueSAWP() {

}

#endif
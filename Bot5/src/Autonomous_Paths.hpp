#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

void redNeg() {
    chassis.setPose(-57,13,225);
    correct_position(rightSensor, &chassis, true);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(90);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-48,22,700,{false});
    chassis.turnToPoint(-24,22, 400,{false});
    chassis.moveToPoint(-35,22, 700, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(-18,22,700,{.forwards = false, .maxSpeed = 30});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-12,29, 700);
    chassis.moveToPoint(-12,29, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-7,58, 1000);
    correct_position(leftSensor, &chassis, true);
    chassis.moveToPoint(-8,35, 1000, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 300);
    chassis.moveToPoint(-48,48, 1000,{.maxSpeed = 100});
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(-70,70,1000,{.minSpeed = 127});
    chassis.moveToPoint(-48,48,600,{false});
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(-65,65,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.turnToPoint(-48,-12, 700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-48,0,700,{.minSpeed = 50, .earlyExitRange = 3});
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
    chassis.setPose(57,13,135);
    correct_position(leftSensor, &chassis, true);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(90);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(48,22,700,{false});
    chassis.turnToPoint(24,22, 400,{false});
    chassis.moveToPoint(35,22, 700, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(18,22,700,{.forwards = false, .maxSpeed = 30});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(12,29, 700);
    chassis.moveToPoint(12,29, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(7,58, 1000);
    correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(8,35, 1000, {false});
    chassis.swingToPoint(24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(24,48, 300);
    chassis.moveToPoint(48,48, 1000,{.maxSpeed = 100});
    chassis.turnToPoint(70,70, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(70,70,1000,{.minSpeed = 127});
    chassis.moveToPoint(48,48,600,{false});
    correct_position(leftSensor, &chassis, false);
    chassis.moveToPoint(65,65,1000);
    chassis.moveToPoint(48,48,700,{false});
    chassis.turnToPoint(48,-12, 700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(48,0,700,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(48,-12,1000, {.maxSpeed = 50});
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

void skills() {
    chassis.setPose(-57,-13,315);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    


}

#endif
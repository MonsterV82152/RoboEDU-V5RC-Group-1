#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

void redNeg() {
    chassis.setPose(-57,13,225);
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
    chassis.moveToPoint(-8,35, 1000, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 300);
    chassis.moveToPoint(-48,48, 1000,{.maxSpeed = 100});
    chassis.turnToPoint(-70,70, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(-70,70,1000,{.minSpeed = 127});
    chassis.moveToPoint(-48,48,600,{false});
    chassis.moveToPoint(-65,65,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.turnToPoint(-48,-12, 700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-48,0,700,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-48,-12,1000, {.maxSpeed = 50});
}

void redPos() {
    chassis.setPose(-48, -38, 104);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-24,-48, 700, {.minSpeed = 127, .earlyExitRange = 3});
    hookTasks.holdNextRing();
    chassis.turnToHeading(90, 200);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE+40);

    chassis.moveToPoint(-14, -48, 700, {.minSpeed = 80});
    ladyBrown.setSetPoint(LadyBrownConfigs::MOGOTIP);

    chassis.turnToHeading(270, 700, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 127});

    chassis.turnToPoint(-26, -24, 700, {false});
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-26, -24, 1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    // chassis.turnToPoint(-70,-70,700);
    // ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    // chassis.moveToPoint(-48,-48,1000);
    // chassis.waitUntilDone();
    // pros::delay(200);
    // chassis.moveToPoint(-70,-70,700, {.minSpeed = 127});
    // chassis.moveToPoint(-48,-48,700,{false});
    // chassis.moveToPoint(-60,-60,700);
    // ladyBrown.setSetPoint(0);
    // chassis.moveToPoint(-12,-12,1000,{false});
}

void blueNeg() {
    chassis.setPose(57,13,135);
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
    chassis.moveToPoint(8,35, 1000, {false});
    chassis.swingToPoint(24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(24,48, 300);
    chassis.moveToPoint(48,48, 1000,{.maxSpeed = 100});
    chassis.turnToPoint(70,70, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(70,70,1000,{.minSpeed = 127});
    chassis.moveToPoint(48,48,600,{false});
    chassis.moveToPoint(65,65,1000);
    chassis.moveToPoint(48,48,700,{false});
    chassis.turnToPoint(48,-12, 700);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(48,0,700,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(48,-12,1000, {.maxSpeed = 50});
}

void bluePos() {
    chassis.setPose(48, -36, 256);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(24
        , -48
        , 1000
        // , {.minSpeed = 127, .earlyExitRange = 3}
    );
    hookTasks.holdNextRing();
    chassis.turnToHeading(270, 700);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE+40);

    chassis.moveToPoint(14, -48, 700, {.minSpeed = 80});
    ladyBrown.setSetPoint(LadyBrownConfigs::MOGOTIP);

    chassis.turnToHeading(90, 700, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 127});

    chassis.turnToPoint(26, -24, 700, {false});
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(26, -24, 1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    // chassis.turnToPoint(-70,-70,700);
    // ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    // chassis.moveToPoint(-48,-48,1000);
    // chassis.waitUntilDone();
    // pros::delay(200);
    // chassis.moveToPoint(-70,-70,700, {.minSpeed = 127});
    // chassis.moveToPoint(-48,-48,700,{false});
    // chassis.moveToPoint(-60,-60,700);
    // ladyBrown.setSetPoint(0);
    // chassis.moveToPoint(-12,-12,1000,{false});
}

void blueSAWP() {

}

#endif
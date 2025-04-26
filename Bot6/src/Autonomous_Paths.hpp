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
    chassis.setPose(-48, -38, 104);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-24,-48, 700, {.minSpeed = 127, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, false);
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
    team = false;
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
    team = false;
    chassis.setPose(48, -38, 256);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(24,-48, 1000
        // , {.minSpeed = 127, .earlyExitRange = 3}
    );
    pros::delay(100);
    correct_position(leftSensor, &chassis, false);

    hookTasks.holdNextRing();
    chassis.turnToHeading(270, 300);

    chassis.moveToPoint(15, -47.2, 1000
        // , {.minSpeed = 80}
    );
    correct_position(leftSensor, &chassis, false);

    pros::delay(500);

    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE+20);


    // pros::delay(100);
    // ladyBrown.setSetPoint(LadyBrownConfigs::MOGOTIP);

    chassis.turnToHeading(90, 700, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 127});

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

void redSAWP() {
    team = false;
    chassis.setPose(-57,13,225);
    correct_position(rightSensor, &chassis, true);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(90);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(600);
    chassis.moveToPoint(-48,22,300,{false});
    chassis.turnToPoint(-24,22, 300,{false});
    chassis.moveToPoint(-35,22, 500, {.forwards = false, .minSpeed = 80, .earlyExitRange = 3});
    chassis.moveToPoint(-18,22,400,{.forwards = false, .maxSpeed = 60});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-8.5,33, 300);
    chassis.moveToPoint(-8.5,33, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-6.5,58, 700);
    // correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(-8,35, 700, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 600,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.turnToPoint(-48,14, 300);
    chassis.moveToPoint(-48,14,1000,{.minSpeed = 50, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(-48,-24, 400);
    chassis.moveToPoint(-48,-24,1100, {.maxSpeed = 70});
    chassis.turnToPoint(-60,-60,700,{false});
    chassis.moveToPoint(-60,-60,700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    chassis.moveToPoint(-48,-48,400);
    chassis.turnToPoint(-24,-48,300);
    chassis.moveToPoint(-24,-48,1000);
    correct_position(rightSensor, &chassis, false);  
    hookTasks.holdNextRing(true);
    chassis.turnToPoint(-26,-24,400,{false});
    chassis.moveToPoint(-26,-24,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(300);
    intake.setSpeed(600);
    chassis.turnToPoint(0,0,700);
    pros::delay(200);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
}

void blueSAWP() {
    team = false;
    chassis.setPose(57,13,135);
    correct_position(leftSensor, &chassis, true);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(90);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(600);
    chassis.moveToPoint(48,22,300,{false});
    chassis.turnToPoint(24,22, 300,{false});
    chassis.moveToPoint(35,22, 500, {.forwards = false, .minSpeed = 80, .earlyExitRange = 3});
    chassis.moveToPoint(18,22,400,{.forwards = false, .maxSpeed = 60});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(8.5,33, 300);
    chassis.moveToPoint(8.5,33, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(6.5,58, 700);
    // correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(8,35, 700, {false});
    chassis.swingToPoint(24,48, lemlib::DriveSide::RIGHT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(24,48, 600,{.minSpeed = 50, .earlyExitRange = 3});
    chassis.turnToPoint(48,14, 300);
    chassis.moveToPoint(48,14,1000,{.minSpeed = 50, .earlyExitRange = 3});
    correct_position(leftSensor, &chassis, true);
    chassis.turnToPoint(48,-24, 400);
    chassis.moveToPoint(48,-24,1100, {.maxSpeed = 70});
    chassis.turnToPoint(60,-60,700,{false});
    chassis.moveToPoint(60,-60,700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    chassis.moveToPoint(48,-48,400);
    chassis.turnToPoint(24,-48,300);
    chassis.moveToPoint(24,-48,1000);
    correct_position(leftSensor, &chassis, false);  
    hookTasks.holdNextRing(true);
    chassis.turnToPoint(26,-24,400,{false});
    chassis.moveToPoint(26,-24,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(300);
    intake.setSpeed(600);
    chassis.turnToPoint(0,0,700);
    pros::delay(200);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);



}

#endif
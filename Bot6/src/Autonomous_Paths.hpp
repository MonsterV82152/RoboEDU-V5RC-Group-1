#ifndef AUTON_HPP
#define AUTON_HPP

#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File

void redNeg() {
    chassis.setPose(-57,13,225);
    correct_position(rightSensor, &chassis, true);
    chassis.arcade(70,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(100);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-48,22,700,{false});
    chassis.turnToPoint(-24,22, 400,{false});
    chassis.waitUntilDone();
    correct_position(rightSensor,&chassis, false);
    chassis.moveToPoint(-35,22, 700, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(-18,22,700,{.forwards = false, .maxSpeed = 30});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-13,29, 700);
    chassis.moveToPoint(-13,29, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-8,58, 1000);
    correct_position(leftSensor, &chassis, true);
    chassis.moveToPoint(-9,35, 1000, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 300);
    chassis.moveToPoint(-48,48, 1000,{.maxSpeed = 100});
    chassis.turnToPoint(-80,80, 700);
    ladyBrown.setSetPoint(180);
    chassis.moveToPoint(-80,80,1000,{.minSpeed = 127});
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
    chassis.setPose(-57,13,225);
    correct_position(rightSensor, &chassis, true);
    chassis.arcade(70,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(100);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(1000);
    chassis.moveToPoint(-48,22,700,{false});
    chassis.turnToPoint(-24,22, 400,{false});
    chassis.waitUntilDone();
    correct_position(rightSensor,&chassis, false);
    chassis.moveToPoint(-35,22, 700, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(-18,22,700,{.forwards = false, .maxSpeed = 30});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-13,29, 700);
    chassis.moveToPoint(-13,29, 700, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-8,58, 1000);
    correct_position(leftSensor, &chassis, true);
    chassis.moveToPoint(-9,35, 1000, {false});
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
void RedRingRushA() {
    chassis.setBrakeMode(MotorConfigs::BRAKE);  
    chassis.setPose(-55,36,90);
    // correct_position(leftSensor, &chassis, false);
    hookTasks.holdNextRing();
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{.forwards = false, .maxSpeed = 70});

    chassis.waitUntilDone();
    chassis.setBrakeMode(MotorConfigs::COAST);
    mogoClamp.setState(true);
    pros::delay(200);
    hookTasks.clearCommand();
    intake.setSpeed(600);
    chassis.moveToPoint(-24,52,1000);
    chassis.turnToPoint(-9,55,700);
    chassis.moveToPoint(-9,55,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-24,48,500,{false});
    chassis.turnToPoint(-48,48,500);
    chassis.moveToPoint(-48,48,700);
    chassis.waitUntilDone();
    hookTasks.raiseLBNextRing();
    chassis.turnToPoint(-80,80,1000,{.maxSpeed = 70});
    
    chassis.moveToPoint(-80,80,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-52,52,800);
    pros::delay(500);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-48,0,1000,{false});
    chassis.turnToPoint(-70,0,700);
    chassis.moveToPoint(-70,0,700);
    chassis.waitUntilDone();
    lemlib::Pose pose = chassis.getPose();
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,-7,700, {false});
    chassis.waitUntilDone();
    lemlib::Pose newPose = chassis.getPose();
    chassis.setPose(pose.x+newPose.x, pose.y+newPose.y, pose.theta+newPose.theta);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(700);
    chassis.moveToPoint(24,24,1000,{false});
    pros::delay(200);
    ladyBrown.setSetPoint(100);
    chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    
}
void RedRingRush() {
    chassis.setBrakeMode(MotorConfigs::BRAKE);  
    chassis.setPose(-55,36,90);
    // correct_position(leftSensor, &chassis, false);
    hookTasks.holdNextRing();
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{.forwards = false, .maxSpeed = 70});

    chassis.waitUntilDone();
    chassis.setBrakeMode(MotorConfigs::COAST);
    mogoClamp.setState(true);
    pros::delay(200);
    hookTasks.clearCommand();
    intake.setSpeed(600);
    chassis.moveToPoint(-24,52,1000);
    chassis.turnToPoint(-9,55,700);
    chassis.moveToPoint(-9,55,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-24,48,500,{false});
    chassis.turnToPoint(-48,48,500);
    chassis.moveToPoint(-48,48,700);
    chassis.waitUntilDone();
    chassis.turnToPoint(-80,80,1000,{.maxSpeed = 70});
    
    chassis.moveToPoint(-80,80,1000);
    chassis.moveToPoint(-48,48,700,{false});
    chassis.moveToPoint(-52,52,800);
    pros::delay(500);
    chassis.moveToPoint(-48,0,1000,{false});
    chassis.turnToPoint(-70,0,700);
    chassis.moveToPoint(-70,0,700);
    chassis.waitUntilDone();
    
}
void fastBlueNegA() {
    team = false;
    chassis.setPose(51.5, 38, 270);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(18,37,700,{.minSpeed = 70, .earlyExitRange = 3}); 
    hookTasks.holdNextRing();
    doinker.setState(true);
    chassis.moveToPoint(6.5, 43, 550);
    chassis.moveToPoint(9.5,41,200,{.forwards = false, .minSpeed = 70, .earlyExitRange = 1});
    chassis.moveToPoint(24,24,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    hookTasks.clearCommand();
    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.turnToHeading(340, 1000);
    pros::delay(400);
    doinker.setState(false);
    intake.stop();
    // pros::delay(200);
    // chassis.turnToPoint(8,8,700);
    // chassis.moveToPoint(8,8,800,{.maxSpeed = 100});
    // doinker.setState(true);
    // chassis.moveToPoint(38,19,700,{.forwards = false});
    // chassis.turnToHeading(320,900);
    // pros::delay(200);
    // doinker.setState(false);
    chassis.turnToPoint(24,48,200);
    intake.setSpeed(600);
    chassis.moveToPoint(19,55,1100,{.maxSpeed = 60});
    chassis.turnToPoint(48,48,400);
    chassis.moveToPoint(60,48,1000);
    correct_position(leftSensor, &chassis, false);
    chassis.turnToPoint(65,80,300);
    chassis.moveToPoint(65,60,800);
    chassis.moveToPoint(65,80,1000,{.minSpeed = 90});
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    correct_position(rightSensor, &chassis, true);
    chassis.waitUntilDone();
    pros::delay(300);
    chassis.moveToPoint(44,44,700,{false});
    chassis.moveToPoint(60,56,800);
    chassis.moveToPoint(55,3,1200,{false});
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    intake.clearAllOverwrites();
    intake.setSpeed(600);
    pros::delay(200);
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(70,2,700);
    pros::delay(500);
    chassis.moveToPoint(70,2,700,{.maxSpeed = 70});
    chassis.waitUntilDone();
    lemlib::Pose pose = chassis.getPose();
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,-9,700, {false});
    chassis.waitUntilDone();
    lemlib::Pose newPose = chassis.getPose();
    chassis.setPose(pose.x+newPose.x, pose.y+newPose.y, pose.theta+newPose.theta);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(700);
    chassis.moveToPoint(24,24,1000,{false});
    pros::delay(200);
    ladyBrown.setSetPoint(100);
    chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,1000);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);


}
void fastBlueNeg() {
    team = false;
    chassis.setPose(51.5, 38, 270);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(18,37,700,{.minSpeed = 70, .earlyExitRange = 3}); 
    hookTasks.holdNextRing();
    doinker.setState(true);
    chassis.moveToPoint(7, 42.5, 500);
    chassis.moveToPoint(9.5,41,200,{.forwards = false, .minSpeed = 70, .earlyExitRange = 1});
    chassis.moveToPoint(24,24,800,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    hookTasks.clearCommand();
    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.turnToHeading(350, 500);
    pros::delay(400);
    doinker.setState(false);
    intake.stop();
    pros::delay(200);
    chassis.turnToPoint(8,8,700);
    chassis.moveToPoint(8,8,800,{.maxSpeed = 100});
    doinker.setState(true);
    chassis.moveToPoint(38,19,700,{.forwards = false});
    chassis.turnToHeading(320,900);
    pros::delay(200);
    doinker.setState(false);
    chassis.turnToPoint(24,48,200);
    intake.setSpeed(600);
    chassis.moveToPoint(19,55,1350,{.maxSpeed = 45});
    chassis.turnToPoint(48,48,400);
    chassis.moveToPoint(60,48,1000);
    correct_position(leftSensor, &chassis, false);
    chassis.turnToPoint(65,80,300);
    chassis.moveToPoint(65,80,600);
    correct_position(rightSensor, &chassis, true);
    chassis.waitUntilDone();
    pros::delay(300);
    chassis.moveToPoint(44,44,700,{false});
    chassis.moveToPoint(56,56,800);
    chassis.moveToPoint(24,24,1000,{false});

}
void autonSkills() {
    chassis.setPose(-57,-12,315);
    correct_position(leftSensor, &chassis, true);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(700);
    chassis.moveToPoint(-46,-28,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(0);

    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.turnToPoint(-28,-24,400);
    chassis.moveToPoint(-28,-24,700);
    chassis.turnToPoint(48,-58,500);
    chassis.moveToPoint(24,-48,1000);
    correct_position(rightSensor, &chassis, false);
    pros::delay(500);
    hookTasks.raiseLBNextRing();
    chassis.moveToPoint(48,-58,1200,{.maxSpeed = 50});
    chassis.moveToPoint(3,-40,1000,{.forwards = false});
    chassis.turnToPoint(3,-80,700);
    chassis.moveToPoint(3,-80,1000,{.maxSpeed = 60});
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    pros::delay(300);
    intake.clearAllOverwrites();
    hookTasks.holdNextRing();
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    ladyBrown.waitUntilAtSetpoint(600);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint();
    intake.setSpeed(600);
    pros::delay(500);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    ladyBrown.waitUntilAtSetpoint(600);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(2,-48,1000,{.forwards = false});
    hookTasks.clearCommand();
    chassis.turnToPoint(-65,-48,700);
    intake.clearAllOverwrites();
    intake.setSpeed(600);
    chassis.moveToPoint(-36,-48,1000,{.minSpeed = 70, .earlyExitRange = 3});
    correct_position(leftSensor, &chassis, false);
    chassis.moveToPoint(-65,-48,700,{.maxSpeed = 70});
    pros::delay(200);
    correct_position(leftSensor, &chassis, false);
    chassis.moveToPoint(-48,-40,700,{.forwards = false});
    chassis.turnToPoint(-45,-65,700);
    chassis.moveToPoint(-45,-65,700);
    chassis.moveToPoint(-48,-48,700,{.forwards = false});
    chassis.turnToPoint(0,0,700);
    chassis.moveToPoint(-60,-60,700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    correct_position(leftSensor, &chassis, true, true);
    correct_position(rightSensor, &chassis, false, true);
    pros::delay(200);
    chassis.moveToPoint(-48,-48,400);
    chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,12,1000,{.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(-48,24,700,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);


    chassis.turnToPoint(-28,24,400);
    chassis.moveToPoint(-28,24,700);
    chassis.turnToPoint(48,58,500);
    chassis.moveToPoint(24,48,1000);
    correct_position(leftSensor, &chassis, false);
    pros::delay(800);
    hookTasks.raiseLBNextRing();
    chassis.moveToPoint(48,58,1200,{.maxSpeed = 50});
    chassis.moveToPoint(0,40,1000,{.forwards = false});
    chassis.turnToPoint(0,80,700);
    chassis.moveToPoint(0,80,1000,{.maxSpeed = 60});
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    pros::delay(300);
    intake.clearAllOverwrites();
    hookTasks.holdNextRing();
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    ladyBrown.waitUntilAtSetpoint(600);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint();
    intake.setSpeed(600);
    pros::delay(500);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    ladyBrown.waitUntilAtSetpoint(600);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(0,48,1000,{.forwards = false});
    hookTasks.clearCommand();
    chassis.turnToPoint(-65,48,700);
    intake.clearAllOverwrites();
    intake.setSpeed(600);
    chassis.moveToPoint(-36,48,1000,{.minSpeed = 70, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(-65,48,700,{.maxSpeed = 70});
    pros::delay(200);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(-48,40,700,{.forwards = false});
    chassis.turnToPoint(-45,65,700);
    chassis.moveToPoint(-45,65,700);
    chassis.moveToPoint(-48,48,700,{.forwards = false});
    chassis.turnToPoint(0,0,700);
    chassis.moveToPoint(-60,60,700,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);


    pros::delay(200);
    chassis.moveToPoint(0,48,1000);
    pros::delay(400);
    correct_position(leftSensor, &chassis, false, true);
    chassis.turnToPoint(24,24,400);
    chassis.moveToPoint(24,24,800);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    chassis.turnToPoint(48,0,600,{.forwards = false});
    chassis.moveToPoint(48,0,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    chassis.turnToPoint(70,0,600);
    chassis.moveToPoint(70,0,700,{.maxSpeed = 50});


    
    
    


    


}

#endif
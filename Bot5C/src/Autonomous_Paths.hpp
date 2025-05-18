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
void moveTo(double x, double y, int t1, int t2, bool b1, bool b2) {
	chassis.turnToPoint(x, y, t1, {.forwards=b1});
	chassis.moveToPoint(x, y, t2, {.forwards=b2});
}

void redPosA() {
    chassis.setPose(-57,-13,315);
    correct_position(leftSensor, &chassis, true);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint(400);
    intake.setSpeed(600);
    pros::delay(500);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(120);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(600);
    chassis.moveToPoint(-48,-22,400,{false});
    chassis.turnToPoint(-24,-22, 300,{false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(-24,-22,700, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(-24,-48, 500);
    chassis.moveToPoint(-24,-48, 900);

    pros::delay(200);
    correct_position(frontSensor, &chassis, false);
    chassis.turnToPoint(-52,-52, 500);
    chassis.moveToPoint(-52,-52, 700);
    pros::delay(200);
    correct_position(frontSensor, &chassis, true);
    chassis.turnToPoint(-75,-75,700);
    chassis.moveToPoint(-65,-65, 700, {.maxSpeed = 100});
    chassis.moveToPoint(-75,-75, 700);
    chassis.moveToPoint(-65,-65, 500, {.forwards = false});
    chassis.moveToPoint(-75,-75, 700);
    chassis.moveToPoint(-65,-65, 500, {.forwards = false});
    chassis.moveToPoint(-75,-75, 700);
    // chassis.moveToPoint(-44,-44,1000,{false});
    // chassis.moveToPoint(-65,-65,1000);
    // chassis.moveToPoint(-67,-48,1000,{false});
    // chassis.turnToHeading(220, 700);
    // chassis.waitUntilDone();
    // doinker.setState(true);
    // pros::delay(800);
    // chassis.arcade(50,0);
    // pros::delay(200);
    chassis.waitUntilDone();
    chassis.moveToPoint(48,48,700,{false});
    chassis.turnToPoint(0,0,700);
    chassis.moveToPoint(-27,-27,1000,{.maxSpeed = 40});
    mogoClamp.setState(false);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    chassis.waitUntilDone();
    

    // chassis.moveToPoint(-12,-12,1000,{false});
    
    // chassis.turnToHeading(135,700);
    // chassis.waitUntilDone();
    // mogoClamp.setState(false);
    // doinker.setState(false);
    // chassis.moveToPoint(-24,-55,1000,{false});
    // chassis.turnToPoint(0,-55, 700,{false});
    // chassis.moveToPoint(-12,-55, 1000, {.forwards = false, .maxSpeed = 50});
    // ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);

    


}

void redPos() {
    chassis.setPose(-55, -58, 90);
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	chassis.moveToPoint(-13, -58, 1000, {.maxSpeed = 100}); // orig -11
	pros::delay(500);
	intake.setSpeed(600);
	chassis.turnToPoint(0, -48, 600, {.maxSpeed = 60});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::MOGOTIP);
	pros::delay(700);
	chassis.turnToHeading(180, 600, {.direction = AngularDirection::CW_CLOCKWISE}); // this
	// chassis.turnToPoint(-23.5, -47.5, 1150, {.direction = AngularDirection::CW_CLOCKWISE});
	chassis.waitUntilDone();
	intake.setSpeed(150);
	ladyBrown.setSetPoint(0);
	
	moveTo(-37, -61, 500, 700, false, false); // this
	moveTo(-23.5, -47.5, 300, 700, true, true); // r1
	chassis.turnToPoint(-23.5, -22, 600, {.forwards = false});
	chassis.moveToPoint(-23.5, -22, 1000, {.forwards = false, .maxSpeed = 80}); // mg2
	chassis.waitUntilDone();
	intake.setSpeed(600);
	mogoClamp.setState(true);
	chassis.turnToPoint(-54, -36, 400);
	
	chassis.moveToPoint(-54, -36, 750, {.minSpeed = 60, .earlyExitRange = 2});
	pros::delay(400);
	mogoClamp.setState(false);
	chassis.turnToPoint(-66, -66, 350, {.minSpeed = 60, .earlyExitRange = 10});
	chassis.moveToPoint(-66, -66, 1750, {.maxSpeed = 90}); // r2
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	moveTo(-56, -56, 0, 750, false, false);
	chassis.waitUntilDone();
	moveTo(-56, -1, 500, 1400, false, false);
	moveTo(-70, -1, 600, 600, true, true);

	chassis.waitUntilDone();
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -6.5, 750, {.forwards = false});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
	pros::delay(600);
	chassis.moveToPoint(0, -100, 2000, {.forwards = false});



	// moveTo(-54, -0.5, 0, 750, false, false); // check this
	// chassis.waitUntilDone();
	// highStat = 4; // al
	// delay(600);
	// moveTo(-30, -0.5, 0, 1500, false, false);

   
   


}
void bluePosA() {
    team = false;
    chassis.setPose(57,-13,45);
    correct_position(rightSensor, &chassis, true);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint(400);
    intake.setSpeed(600);
    pros::delay(500);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(120);
    chassis.arcade(0,0);
    ladyBrown.waitUntilAtSetpoint(600);
    chassis.moveToPoint(48,-22,400,{false});
    chassis.turnToPoint(24,-22, 300,{false});
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(24,-22,700, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    intake.setSpeed(600);
    pros::delay(200);
    chassis.turnToPoint(26,-52, 500);
    chassis.moveToPoint(26,-52, 900);

    pros::delay(200);
    correct_position(frontSensor, &chassis, false);
    chassis.turnToPoint(52,-54, 500);
    chassis.moveToPoint(52,-54, 700);
    pros::delay(200);
    correct_position(frontSensor, &chassis, true);
    chassis.turnToPoint(75,-75,700);
    chassis.moveToPoint(65,-65, 700);
    chassis.moveToPoint(75,-75, 700);
    chassis.moveToPoint(60,-60, 500, {.forwards = false});
    chassis.moveToPoint(75,-75, 700);
    chassis.moveToPoint(60,-60, 500, {.forwards = false});
    chassis.moveToPoint(75,-75, 700);
    chassis.moveToPoint(44,-44,1000,{false});
    // // chassis.moveToPoint(-65,-65,1000);
    // // chassis.moveToPoint(75,-48,1000,{false});
    // // chassis.turnToHeading(120, 700);
    // // chassis.waitUntilDone();
    // // doinker.setState(true);
    // // pros::delay(800);
    // // chassis.arcade(50,0);
    // // pros::delay(200);

    // // chassis.moveToPoint(-12,-12,1000,{false});
    
    // // chassis.turnToHeading(45,700);
    chassis.waitUntilDone();
    chassis.turnToPoint(0,0,700);
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    doinker.setState(false);
    // pros::delay(200);
    // chassis.turnToPoint(30,-30,700);
    chassis.moveToPoint(30,-30,700);
    // chassis.turnToPoint(0,-48, 700,{false});
    // chassis.moveToPoint(12,-48, 1000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);

    


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
    chassis.setPose(55, -58, 270);
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	chassis.moveToPoint(13, -58, 1000, {.maxSpeed = 100}); // orig -11
	pros::delay(500);
	intake.setSpeed(600);
	chassis.turnToPoint(0, -48, 600, {.maxSpeed = 60});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::MOGOTIP);
	pros::delay(700);
	chassis.turnToHeading(180, 600, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}); // this
	// chassis.turnToPoint(-23.5, -47.5, 1150, {.direction = AngularDirection::CW_CLOCKWISE});
	chassis.waitUntilDone();
	intake.setSpeed(150);
    ladyBrown.setSetPoint(0);
	moveTo(37, -61, 500, 700, false, false); // this
	moveTo(23.5, -47.5, 300, 700, true, true); // r1
	chassis.turnToPoint(23.5, -22, 600, {.forwards = false});
	chassis.moveToPoint(23.5, -22, 1000, {.forwards = false, .maxSpeed = 80}); // mg2
	chassis.waitUntilDone();
	intake.setSpeed(600);
	mogoClamp.setState(true);
	chassis.turnToPoint(54, -36, 400);
	
	chassis.moveToPoint(54, -36, 750, {.minSpeed = 60, .earlyExitRange = 2});
	pros::delay(400);
	mogoClamp.setState(false);
	chassis.turnToPoint(66, -66, 350, {.minSpeed = 60, .earlyExitRange = 10});
	chassis.moveToPoint(66, -66, 1750, {.maxSpeed = 90}); // r2
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	moveTo(56, -56, 0, 750, false, false);
	chassis.waitUntilDone();
	moveTo(56, -1, 500, 1400, false, false);
	moveTo(70, -1, 600, 600, true, true);

	chassis.waitUntilDone();
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -6.5, 750, {.forwards = false});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
	pros::delay(600);
	chassis.moveToPoint(0, -100, 2000, {.forwards = false});
}
void redSAWP() {
    chassis.setPose(-57,13,225);
    correct_position(rightSensor, &chassis, true);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    pros::delay(400);
    intake.setSpeed(600);
    pros::delay(500);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(120);
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
    chassis.turnToPoint(-13,33, 300);
    chassis.moveToPoint(-13,33, 700, {.minSpeed = 30, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-9.5,58, 700);
    correct_position(leftSensor, &chassis, true);
    chassis.moveToPoint(-10,30, 700, {false});
    chassis.swingToPoint(-24,48, lemlib::DriveSide::LEFT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(-24,48, 600,{.minSpeed = 50, .earlyExitRange = 2});
    chassis.turnToPoint(-45,14, 300);
    chassis.waitUntilDone();
    correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(-45,14,1000,{.minSpeed = 50, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(-46,-32, 400);
    chassis.moveToPoint(-46,-32,2200, {.maxSpeed = 70});
    chassis.turnToPoint(-24,-48,300);
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    chassis.moveToPoint(-24,-52,1000);
    correct_position(rightSensor, &chassis, false);  
    hookTasks.holdNextRing(true);
    chassis.turnToPoint(-24,-24,400,{false});
    chassis.moveToPoint(-24,-24,1000,{.forwards = false, .maxSpeed = 70});
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
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    pros::delay(600);
    intake.setSpeed(600);
    pros::delay(500);
    chassis.arcade(50,0);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    pros::delay(120);
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
    chassis.turnToPoint(12,33, 300);
    chassis.moveToPoint(12,33, 700, {.minSpeed = 30, .earlyExitRange = 3});
    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 500, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(9,58, 700);
    correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(10,30, 700, {false});
    chassis.swingToPoint(24,48, lemlib::DriveSide::RIGHT, 1000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPoint(24,48, 600,{.minSpeed = 50, .earlyExitRange = 2});
    chassis.turnToPoint(43,14, 300);
    chassis.moveToPoint(43,14,1000,{.minSpeed = 50, .earlyExitRange = 3});
    correct_position(leftSensor, &chassis, true);
    chassis.turnToPoint(45,-48, 400);
    chassis.moveToPoint(45,-48,2200, {.maxSpeed = 70});
    chassis.turnToPoint(24,-52,300);
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    chassis.moveToPoint(20,-52,1000);
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
    intake.setSpeed(600);
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-26,22,1000,{.forwards = false, .maxSpeed = 70});
    pros::delay(300);
    intake.setSpeed(0);

    chassis.waitUntilDone();
    chassis.setBrakeMode(MotorConfigs::COAST);
    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.moveToPoint(-24,52,1000);
    chassis.turnToPoint(-9,55,700);
    chassis.moveToPoint(-9,55,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-24,48,500,{false});
    chassis.turnToPoint(-46,48,500);
    chassis.moveToPoint(-46,48,700);
    chassis.waitUntilDone();
    hookTasks.raiseLBNextRing();
    chassis.turnToPoint(-80,80,1000,{.maxSpeed = 70});
    
    // chassis.moveToPoint(-80,80,1000);
    chassis.moveToPoint(-80,80,1000,{.maxSpeed = 50});
    chassis.moveToPoint(-52,52,700,{false});
    chassis.moveToPoint(-80,80,700,{.maxSpeed = 50});
    chassis.moveToPoint(-52,52,700,{false});
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-80,80,700,{.maxSpeed = 50});
    chassis.moveToPoint(-48,-2,1100,{false});
    chassis.turnToPoint(-70,-2,700);
    chassis.moveToPoint(-70,-2,700);
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
    chassis.swingToPoint(0,0,lemlib::DriveSide::LEFT,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    
}

void RedRingRush() {
    chassis.setBrakeMode(MotorConfigs::BRAKE);  
    chassis.setPose(-55,36,90);
    // correct_position(leftSensor, &chassis, false);
    intake.setSpeed(600);
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{.forwards = false, .maxSpeed = 70});
    pros::delay(200);
    intake.setSpeed(0);

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
    chassis.turnToPoint(-45,48,500);
    chassis.moveToPoint(-45,48,700);
    chassis.waitUntilDone();
    chassis.turnToPoint(-80,80,1000);
    ladyBrown.setSetPoint(200);
    
    chassis.moveToPoint(-80,80,1000,{.maxSpeed = 50});
    chassis.moveToPoint(-52,52,700,{false});
    chassis.moveToPoint(-80,80,700,{.maxSpeed = 50});
    chassis.moveToPoint(-52,52,700,{false});
    chassis.moveToPoint(-80,80,700,{.maxSpeed = 50});

    chassis.moveToPoint(-10,10,1000,{.forwards = false, .minSpeed = 70});
    pros::delay(500);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    // intake.setSpeed(0);
    chassis.waitUntilDone();
    // ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    
}

void fastBlueNegA() {
    team = false;
    chassis.setPose(51.5, 38, 270);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(28,37,500,{.minSpeed = 70, .earlyExitRange = 5}); 
    intake.setSpeed(600);
    doinker.setState(true);
    chassis.moveToPoint(10, 43.5, 500);
    pros::delay(800);
    intake.setSpeed(0);
    // chassis.moveToPoint(9.5,41,200,{.forwards = false, .minSpeed = 70, .earlyExitRange = 1});
    chassis.moveToPoint(26,22,1000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.turnToHeading(350, 500);
    pros::delay(100);
    doinker.setState(false);

    // intake.stop();
    // pros::delay(200);
    // chassis.turnToPoint(10,14.5,700);
    // chassis.moveToPoint(10,14.5,800,{.maxSpeed = 100});
    // doinker.setState(true);
    // chassis.moveToPoint(38,19,700,{.forwards = false});
    // chassis.turnToHeading(320,1000);
    // pros::delay(500);
    // doinker.setState(false);
    chassis.turnToPoint(24,48,200);
    intake.setSpeed(600);
    chassis.moveToPoint(24,48,1350,{.maxSpeed = 45});
    chassis.turnToPoint(45,48,400);
    chassis.moveToPoint(45,48,800);
    correct_position(leftSensor, &chassis, false);
    chassis.turnToPoint(80,80,300);
    chassis.moveToPoint(80,80,800,{.maxSpeed = 75});
    correct_position(rightSensor, &chassis, true);
    pros::delay(500);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);

    chassis.waitUntilDone();
    pros::delay(600);
    // chassis.moveToPoint(44,44,700,{false});
    // chassis.moveToPoint(56,56,800);
    chassis.moveToPoint(55,3,1200,{false});

    pros::delay(200);
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(70,0,700);
    chassis.moveToPoint(70,0,700,{.maxSpeed = 75});
    chassis.waitUntilDone();
    lemlib::Pose pose = chassis.getPose();
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0,-7,700, {false});
    chassis.waitUntilDone();
    lemlib::Pose newPose = chassis.getPose();
    chassis.setPose(pose.x+newPose.x, pose.y+newPose.y, pose.theta+newPose.theta);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(700);
    chassis.moveToPoint(22,28,1000,{false});
    pros::delay(200);
    ladyBrown.setSetPoint(100);
    chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING-10);

}
void fastBlueNeg() {
    team = false;
    chassis.setPose(51.5, 38, 270);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(28,37,500,{.minSpeed = 70, .earlyExitRange = 5}); 
    intake.setSpeed(600);
    doinker.setState(true);
    chassis.moveToPoint(8.5, 44.5, 1000);

    // chassis.moveToPoint(9.5,41,200,{.forwards = false, .minSpeed = 70, .earlyExitRange = 1});
    chassis.moveToPoint(26,22,1000,{.forwards = false, .maxSpeed = 70});
    intake.setSpeed(0);
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    doinker.setState(false);
    chassis.turnToHeading(350, 500);
    // intake.stop();
    // pros::delay(200);
    // chassis.turnToPoint(10,14.5,700);
    // chassis.moveToPoint(10,14.5,800,{.maxSpeed = 100});
    // doinker.setState(true);
    // chassis.moveToPoint(38,19,700,{.forwards = false});
    // chassis.turnToHeading(320,1000);
    // pros::delay(500);
    // doinker.setState(false);
    chassis.turnToPoint(24,48,200);
    intake.setSpeed(600);
    chassis.moveToPoint(24,48,1350,{.maxSpeed = 45});
    chassis.turnToPoint(45,48,400);
    chassis.moveToPoint(45,48,800);
    correct_position(leftSensor, &chassis, false);
    chassis.turnToPoint(80,80,300);
    ladyBrown.setSetPoint(200);
    chassis.moveToPoint(80,80,800,{.maxSpeed = 100});
    correct_position(rightSensor, &chassis, true);
    chassis.waitUntilDone();
    pros::delay(600);
    chassis.moveToPoint(44,44,700,{false});
    chassis.moveToPoint(56,56,800);
    // chassis.moveToPoint(55,5,1200,{false});

    pros::delay(200);
    
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(24,24,700);
    chassis.moveToPoint(24,24,700,{.forwards = false, .maxSpeed = 100});

}
void autonSkills() {
    chassis.setPose(-57.8,-10.5,315);
    correct_position(leftSensor, &chassis, true);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint(300);
    intake.setSpeed(600);
    pros::delay(400);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(700);
    chassis.moveToPoint(-48,-24,700,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(0);

    mogoClamp.setState(true);
    pros::delay(200);
    intake.setSpeed(600);
    chassis.turnToPoint(-28,-24,400);
    chassis.moveToPoint(-28,-24,900);
    chassis.turnToPoint(48,-62,500);
    chassis.moveToPoint(24,-48,1000);
    correct_position(rightSensor, &chassis, false);
    pros::delay(800);
    hookTasks.raiseLBNextRing();
    chassis.moveToPoint(48,-62,1200,{.maxSpeed = 50});
    chassis.moveToPoint(-2,-43,1200,{.forwards = false});
    chassis.turnToPoint(-2,-80,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    chassis.moveToPoint(-2,-80,1000,{.maxSpeed = 70});
    intake.setSpeed(600);
    pros::delay(700);
    intake.setSpeed(0);

    intake.clearAllOverwrites();
    chassis.waitUntilDone();
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    pros::delay(700);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint(700);
    intake.setSpeed(600);
    pros::delay(900);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    pros::delay(900);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(2,-48,600,{.forwards = false});
    hookTasks.clearCommand();
    chassis.turnToPoint(-65,-48,700);
    intake.clearAllOverwrites();
    intake.setSpeed(600);
    chassis.moveToPoint(-36,-48,1000,{.minSpeed = 70, .earlyExitRange = 3});
    correct_position(leftSensor, &chassis, false);
    chassis.moveToPoint(-65,-48,900,{.maxSpeed = 70});
    pros::delay(200);
    correct_position(leftSensor, &chassis, false);
    chassis.moveToPoint(-48,-40,700,{.forwards = false});
    chassis.turnToPoint(-45,-65,400);
    chassis.moveToPoint(-45,-65,700);
    chassis.moveToPoint(-48,-48,700,{.forwards = false});
    chassis.turnToPoint(0,0,600);
    chassis.moveToPoint(-60,-60,600,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    // correct_position(leftSensor, &chassis, true, true);
    // correct_position(rightSensor, &chassis, false, true);
    pros::delay(200);
    chassis.moveToPoint(-48,-48,400);
    chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,12,1000,{.forwards = false, .minSpeed = 70, .earlyExitRange = 3});
    pros::delay(200);
    correct_position(rightSensor, &chassis, true);
    chassis.moveToPoint(-48,22,700,{.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);


    chassis.turnToPoint(-28,24,500);
    chassis.moveToPoint(-28,24,700);
    chassis.turnToPoint(48,63,500);
    chassis.moveToPoint(25,50,1000);
    correct_position(leftSensor, &chassis, false);
    // pros::delay(900);
    chassis.moveToPoint(48,65,1200,{.maxSpeed = 50});
    hookTasks.raiseLBNextRing();
    chassis.moveToPoint(-2,42,1200,{.forwards = false});
    chassis.turnToPoint(-2,80,700);
    chassis.moveToPoint(-2,80,1000,{.maxSpeed = 70});
    ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
    pros::delay(300);
    intake.clearAllOverwrites();
    intake.setSpeed(0);
    chassis.waitUntilDone();

    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    pros::delay(700);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    ladyBrown.waitUntilAtSetpoint(700);
    intake.setSpeed(600);
    pros::delay(1000);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    pros::delay(900);
    ladyBrown.setSetPoint(0);
    chassis.moveToPoint(0,48,600,{.forwards = false});
    hookTasks.clearCommand();
    chassis.turnToPoint(-65,48,700);
    intake.clearAllOverwrites();
    intake.setSpeed(600);
    chassis.moveToPoint(-36,48,1000,{.minSpeed = 90, .earlyExitRange = 3});
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(-65,48,900,{.maxSpeed = 50});
    pros::delay(200);
    correct_position(rightSensor, &chassis, false);
    chassis.moveToPoint(-48,40,600,{.forwards = false});
    chassis.turnToPoint(-45,65,400);
    chassis.moveToPoint(-45,65,600);
    chassis.moveToPoint(-48,48,500,{.forwards = false});
    chassis.turnToPoint(0,0,600);
    chassis.moveToPoint(-60,60,600,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);


    pros::delay(200);
    chassis.moveToPoint(0,48,1000);
    pros::delay(200);
    correct_position(leftSensor, &chassis, false);
    chassis.waitUntilDone();
    // correct_position(frontSensor, &chassis, true);
    chassis.turnToPoint(24,14,400);
    chassis.moveToPoint(24,14,1000);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
    chassis.turnToPoint(42,-3,600,{.forwards = false});
    chassis.moveToPoint(42,-3,900,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    // chassis.moveToPoint(40,0,400);
    chassis.turnToPoint(70,-3,600);
    chassis.moveToPoint(70,-3,700,{.maxSpeed = 50});
    correct_position(frontSensor, &chassis, true);
    chassis.moveToPoint(47,-2, 700,{false});
    pros::delay(400);
    ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
    ladyBrown.waitUntilAtSetpoint(600);
    chassis.moveToPoint(40,0,500,{false});
    pros::delay(200);
    intake.setSpeed(-600);
    ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);

    chassis.turnToPoint(44,46,600);
    ladyBrown.setSetPoint(0);
    intake.setSpeed(200);
    chassis.moveToPoint(44,46,1000);
    pros::delay(200);
    correct_position(rightSensor, &chassis, true);
    chassis.turnToPoint(60,46,600);
    chassis.moveToPoint(60,46,700);
    chassis.moveToPoint(24,24,700,{false});
    chassis.turnToPoint(3,3,700);
    chassis.moveToPoint(3,3,1000);
    intake.setSpeed(300);
    chassis.turnToPoint(24,-24,700);
    chassis.moveToPoint(24,-24,700,{.minSpeed = 50, .earlyExitRange = 3});
    doinker.setState(true);
    chassis.moveToPoint(48,-48,700,{.maxSpeed = 60});
    intake.setSpeed(600);
    chassis.turnToPoint(60,-48,400);
    chassis.moveToPoint(60,-48,700);
    chassis.turnToHeading(340, 700);
    chassis.moveToPoint(70,-70,700,{.forwards = false});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    doinker.setState(false);
    pros::delay(200);
    chassis.moveToPoint(20,-48,700);
    chassis.turnToPoint(90,70,700);
    chassis.moveToPoint(90,70,700,{.minSpeed = 127, .earlyExitRange = 6});
    chassis.moveToPoint(70,70,700,{.minSpeed = 127});



    
    
    


    


}

#endif
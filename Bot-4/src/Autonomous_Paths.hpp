#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP


void Feb9Auton() {
    BOOL_colourSorter = true;
    chassis.setPose(-53.385, 15, 0);
    chassis.moveToPoint(-53.385, 0, 700, {.forwards = false, .maxSpeed = 90});
    chassis.turnToHeading(270,700);
    chassis.moveToPoint(-70,0,1000);
    pros::delay(300);
    chassis.waitUntilDone();
    LadyBrownState = 3;
    pros::delay(500);
    chassis.moveToPoint(-48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});
    chassis.turnToPoint(-28,28,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(-24,24,1000,{false});
    LadyBrownState = 0;
    chassis.waitUntilDone();
    intakeSpeed = 127;
    hookSpeed = 127;
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(-24,50,700);
    chassis.moveToPoint(-24,50,1000);
    chassis.turnToPoint(-5,43,700);
    chassis.moveToPoint(-5,43,1000);
    chassis.moveToPoint(-24,48,1000,{false});
    chassis.turnToPoint(-3,56,700);
    chassis.moveToPoint(-3,56,1000);
    chassis.moveToPoint(-24,48,1000,{false});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(-10,10,1000);
    pros::delay(200);
    // LadyBrownState = 3;

}

void RedSoloAWP() {
    BOOL_colourSorter = true;
    chassis.setPose(-53.385, -15, 180);
    chassis.moveToPoint(-53.385, 0, 500, {.forwards = false});
    chassis.turnToHeading(270,500);
    chassis.moveToPoint(-70,0,500);
    pros::delay(200);
    LadyBrownState = 3;
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});


    chassis.turnToPoint(-24,-24,700,{.forwards = false, .earlyExitRange = 5});
    LadyBrownState = 0;
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(-24,-24,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(-24,-52,700);
    chassis.moveToPoint(-24,-54,1000);
    chassis.turnToHeading(315,700);
    intakeSpeed = -127;
    chassis.follow(Red_Solo_AWP_txt,15,1600);
    chassis.waitUntil(20);
    BOOL_mogo_clamp = false;
    chassis.waitUntilDone();
    chassis.turnToPoint(-20,20,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(-20,20,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    intakeSpeed = 127;
    hookSpeed = 127;
    pros::delay(200);
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-5,48,700);
    chassis.moveToPoint(-5,48,1000);
    chassis.moveToPoint(-24,48,1000,{.forwards = false});

    chassis.moveToPoint(-12,12,1000);

    
}

void BlueSoloAWP() {
    BOOL_colourSorter = true;
    chassis.setPose(53.385, -15, 180);
    chassis.moveToPoint(53.385, 0, 500, {.forwards = false});
    chassis.turnToHeading(90,500);
    chassis.moveToPoint(70,0,500);
    pros::delay(200);
    LadyBrownState = 3;
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});


    chassis.turnToPoint(24,-24,700,{.forwards = false, .earlyExitRange = 5});
    LadyBrownState = 0;
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(24,-24,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(24,-52,700);
    chassis.moveToPoint(24,-54,1000);
    chassis.turnToHeading(45,700);
    intakeSpeed = -127;
    chassis.follow(Blue_Solo_AWP_txt,15,1600);
    chassis.waitUntil(20);
    BOOL_mogo_clamp = false;
    chassis.waitUntilDone();
    chassis.turnToPoint(20,20,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(20,20,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    intakeSpeed = 127;
    hookSpeed = 127;
    pros::delay(200);
    chassis.turnToPoint(24,48,700);
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(5,48,700);
    chassis.moveToPoint(5,48,1000);
    chassis.moveToPoint(24,48,1000,{.forwards = false});

    chassis.moveToPoint(12,12,1000);

    
}

void TechMechBlue() {
    BOOL_colourSorter = true;
    chassis.setPose(52,60,270);
    chassis.moveToPoint(15,60,1000);
    chassis.turnToHeading(280,700);
    LadyBrownState = 3;
    chassis.waitUntilDone();
    pros::delay(700);

    chassis.swingToHeading(180,lemlib::DriveSide::LEFT, 700);
    chassis.moveToPoint(10,40,1000);
    chassis.swingToHeading(315,lemlib::DriveSide::LEFT, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

}

void BlueMogoRush() {
    
    BOOL_colourSorter = true;
    chassis.setPose(50,-30,90);
    chassis.follow(Blue_Mogo_Rush_txt,15,1900,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(30,-55,800);
    chassis.waitUntilDone();
    hookSpeed = 0;
    chassis.moveToPoint(24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(270,700);
    pros::delay(700);
    BOOL_mogo_clamp = false;
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(12,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.turnToHeading(90,1000);
    chassis.moveToPose(48,16,0,3000,{.lead = 0.7,.minSpeed = 70});
    pros::delay(500);
    BOOL_mogo_clamp = false;
    while (!(ring[0] == 2)) {
        pros::delay(10);
    }
    hookSpeed = 0;
    chassis.moveToPoint(54,4,1000,{false});
    chassis.turnToHeading(270,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();
    while (true) {
        chassis.arcade((93-distance)*0.5,0,false,0.5);
        if (abs(93-distance) < 3) {
            break;
        }
    }

    // pros::delay(500);
    hookSpeed = 127;
}

void FinalsBlueMogoRush() {
    BOOL_colourSorter = true;
    chassis.setPose(50,-30,90);
    chassis.follow(Blue_Mogo_Rush_txt,15,2000,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(48,-48,2000);
    chassis.turnToPoint(66,-66,700);
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(80,-80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(90,-90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        if (i == 0) {
            chassis.moveToPoint(50,-50,700,{.forwards = false,.maxSpeed = 100});
        } else {
            chassis.moveToPoint(48,-36,1000,{false});
        }
    }
    chassis.turnToPoint(48,24,700);
    chassis.moveToPoint(48,24,2000,{.maxSpeed = 70});
    chassis.moveToPoint(20,-60,1000,{false});
}

void RedMogoRush() {
    BOOL_colourSorter = true;
    chassis.setPose(-50,-30,270);
    chassis.follow(Red_Mogo_Rush_txt,15,1700,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(-30,-55,800);
    chassis.waitUntilDone();
    hookSpeed = 0;
    chassis.moveToPoint(-24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(90,700);
    pros::delay(700);
    BOOL_mogo_clamp = false;
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(-18,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.turnToHeading(270,1000);
    chassis.moveToPose(-45,16,0,3000,{.lead = 0.7,.minSpeed = 70});
    pros::delay(500);
    BOOL_mogo_clamp = false;
    while (!(ring[0] == 1)) {
        pros::delay(10);
    }
    hookSpeed = 0;
    chassis.moveToPoint(-54,4,1000,{false});
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();
    while (true) {
        chassis.arcade((93-distance)*0.5,0,false,0.5);
        if (abs(93-distance) < 3) {
            break;
        }
    }

    // pros::delay(500);
    hookSpeed = 127;
    
}




void FinalsRedMogoRush() {
    BOOL_colourSorter = true;
    chassis.setPose(-50,-30,270);
    chassis.follow(Red_Mogo_Rush_txt,15,2000,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(-48,-48,2000);
    chassis.turnToPoint(-66,-66,700);
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(-80,-80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(-90,-90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        if (i == 0) {
            chassis.moveToPoint(-50,-50,700,{.forwards = false,.maxSpeed = 100});
        } else  {
            chassis.moveToPoint(-48,-36,1000,{false});
        }
    }
    chassis.turnToPoint(-48,24,700);
    chassis.moveToPoint(-48,24,2000,{.maxSpeed = 70});
    chassis.moveToPoint(-20,-60,1000,{false});
}

void RedRingRush() {
    chassis.setBrakeMode(BRAKE);
    BOOL_colourSorter = false;
    chassis.setPose(-58,36,90);
    intakeSpeed = 127;
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{false});
    BOOL_colourSorter = true;

    chassis.waitUntilDone();
    chassis.setBrakeMode(COAST);
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-7,55,700);
    chassis.moveToPoint(-7,55,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-46,50,1000,{.forwards = false,.earlyExitRange = 5});
    chassis.turnToPoint(-80,80,1000,{.maxSpeed = 70});
    
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(-80,80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(-0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(-90,90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        chassis.moveToPoint(-50,50,700,{.forwards = false,.maxSpeed = 100});
    }
    chassis.moveToPoint(-48,0,1000,{false});
    
}
void BlueRingRush() {
    chassis.setBrakeMode(BRAKE);
    BOOL_colourSorter = false;
    chassis.setPose(58,36,270);
    intakeSpeed = 127;
    chassis.follow(Blue_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(28,20,1000,{false});
    BOOL_colourSorter = true;

    chassis.waitUntilDone();
    chassis.setBrakeMode(COAST);
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(5,55,700);
    chassis.moveToPoint(5,51,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(46,50,1000,{.forwards = false,.earlyExitRange = 5});
    chassis.turnToPoint(80,80,1000,{.maxSpeed = 70});
    
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(80,80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(90,90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        chassis.moveToPoint(50,50,700,{.forwards = false,.maxSpeed = 100});
    }
    chassis.moveToPoint(20,20,1000,{.forwards = false, .minSpeed = 127,.earlyExitRange = 5});
    
}


#endif
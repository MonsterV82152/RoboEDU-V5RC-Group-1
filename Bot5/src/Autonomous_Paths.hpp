#include "globals.hpp"
#include "classes.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void BlueDriveBySoloAwp() {
    colourSorter.setSorting(true);
    chassis.setPose(60,-11.5,0);
    chassis.moveToPoint(60,11.5,700);
    chassis.moveToPoint(24,24,1300,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.turnToPoint(24,48,400);
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(7,52,400);
    chassis.moveToPoint(7,52,1000);
    chassis.moveToPoint(24,48,1000,{.forwards = false});
    chassis.moveToPoint(35,0,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(48,-32,1000);
    chassis.turnToPoint(24,-48,700);
    pros::delay(1300);
    mogoClamp.setState(false);
    hook.stop();
    chassis.moveToPoint(24,-48,1000);
    chassis.turnToPoint(24,-24,700,{false});
    chassis.moveToPoint(24,-24,1000,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    pros::delay(800);
    ladyBrown.setSetPoint(20);
    chassis.moveToPoint(10,-10,1000,{false});
}

void BlueDriveByFinals() {
    colourSorter.setSorting(true);
    chassis.setPose(60,-11.5,0);
    chassis.moveToPoint(60,11.5,700);
    chassis.moveToPoint(24,24,1300,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.turnToPoint(7,46.5,200);
    chassis.moveToPoint(7,46.5,1300);
    chassis.moveToPoint(24,24,1000,{.forwards = false});
    chassis.turnToPoint(24,48,200);
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(7,52,200);
    chassis.moveToPoint(7,52,1000);
    chassis.moveToPoint(48,48,1300,{.forwards = false});
    chassis.turnToPoint(80,80,600);
    chassis.moveToPoint(80,80,1000);
    for (int i = 0; i < 2; i++) {
        chassis.waitUntilDone();
        for (int j = 0; j < 2; j++) {
            chassis.moveToPoint(0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(90,90,200,{.minSpeed = 127});
        }
        pros::delay(500);
        chassis.moveToPoint(50,50,700,{.forwards = false,.maxSpeed = 100});
        if (i == 0) {
            chassis.moveToPoint(80,80,700,{.maxSpeed = 70}); 
        }
    }
    chassis.moveToPoint(12,12,1000,{.forwards = false, .minSpeed = 120});
    pros::delay(200);
    ladyBrown.setSetPoint(20);
}

void RedDriveByFinals() {
    colourSorter.setSorting(true);
    chassis.setPose(-60,11.5,180);
    chassis.moveToPoint(-60,-11.5,700);
    chassis.moveToPoint(-24,24,1300,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.turnToPoint(-6,46.5,200);
    chassis.moveToPoint(-6,46.5,1300);
    chassis.moveToPoint(-24,24,1000,{.forwards = false});
    chassis.turnToPoint(-24,48,200);
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-6,52,200);
    chassis.moveToPoint(-6,52,1000);
    chassis.moveToPoint(-44,48,1300,{.forwards = false});
    chassis.turnToPoint(-80,80,600);
    chassis.moveToPoint(-80,80,1000);
    for (int i = 0; i < 2; i++) {
        chassis.waitUntilDone();
        for (int j = 0; j < 2; j++) {
            chassis.moveToPoint(-0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(-90,90,200,{.minSpeed = 127});
        }
        pros::delay(500);
        chassis.moveToPoint(-50,50,700,{.forwards = false,.maxSpeed = 100});
        if (i == 0) {
            chassis.moveToPoint(-80,80,700,{.maxSpeed = 70}); 
        }
    }
    chassis.moveToPoint(-12,12,1000,{.forwards = false, .minSpeed = 120});
    pros::delay(200);
    ladyBrown.setSetPoint(20);

}

void DEPRedDriveByFinals() {
    colourSorter.setSorting(true);
    chassis.setPose(-60,11.5,180);
    chassis.moveToPoint(-60,-11.5,700);
    chassis.moveToPoint(-24,24,1300,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.turnToHeading(70,700);
    chassis.follow(Red_DriveBy_Finals_txt,15,7000);
    
    chassis.waitUntilDone();
    chassis.moveToPoint(-14,40,1000,{false});
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,700,{.minSpeed = 70,.earlyExitRange = 4});
    chassis.moveToPoint(-48,48,1000,{.minSpeed = 70,.earlyExitRange = 4});
    chassis.moveToPoint(-70,70,1000);
    for (int i = 0; i < 2; i++) {
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(-0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(-90,90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        chassis.moveToPoint(-50,50,700,{.forwards = false,.maxSpeed = 100});
        if (i == 0) {
            chassis.moveToPoint(-80,80,1000,{.maxSpeed = 70}); 
        }
    }
    hook.stop();
    intake.stop();
    chassis.moveToPoint(-12,-12,2000);
    ladyBrown.setSetPoint(20);
    
    
    
}

void RedDriveBySoloAwp() {
    colourSorter.setSorting(true);
    chassis.setPose(-60,11.5,180);
    chassis.moveToPoint(-60,-11.5,700);
    chassis.moveToPoint(-24,24,1300,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.turnToPoint(-24,48,400);
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-6,52,400);
    chassis.moveToPoint(-6,52,1000);
    chassis.moveToPoint(-24,48,1000,{.forwards = false});
    chassis.moveToPoint(-48,0,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(-48,-32,1000);
    chassis.turnToPoint(-18,-48,700);
    pros::delay(1300);
    mogoClamp.setState(false);
    hook.stop();
    chassis.moveToPoint(-18,-48,1000);
    chassis.turnToPoint(-18,-18,700,{false});
    chassis.moveToPoint(-18,-18,1000,{false});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    pros::delay(800);
    ladyBrown.setSetPoint(20);
    chassis.moveToPoint(-10,-10,1000,{false});


}


// TODO: FINISH THIS

// void RedDriveBySoloAwp() {
//     colourSorter.setSorting(true);
//     chassis.setPose(-60,11.5,180);
//     chassis.moveToPoint(-60,-11.5,700);
//     chassis.moveToPoint(-24,24,1300,{false});
//     chassis.waitUntilDone();
//     mogoClamp.setState(true);
//     pros::delay(200);
//     hook.setSpeed(127);
//     intake.setSpeed(127);
//     chassis.turnToHeading(70,700);
//     chassis.follow(Red_DriveBy_AWP_txt,15,7000);
//     chassis.waitUntilDone();
//     chassis.moveToPoint(-14,40,1000,{false});
//     chassis.turnToPoint(-24,48,700);
//     chassis.moveToPoint(-24,48,700,{.minSpeed = 70,.earlyExitRange = 4});
//     chassis.moveToPoint(-48,48,1000,{.minSpeed = 70,.earlyExitRange = 4});
    
//     chassis.moveToPoint(-90,-80,1000); 
//     chassis.waitUntilDone();
//     pros::delay(500);
//     chassis.moveToPoint(-50,-50,700,{.forwards = false,.maxSpeed = 100});
//     chassis.turnToPoint(0,0,1000);
//     chassis.waitUntilDone();
//     mogoClamp.setState(false);
//     chassis.moveToPoint(-40,-35,700);
//     chassis.turnToPoint(-30,-24,400,{false});
//     chassis.moveToPoint(-24,-24,1000,{false});
//     chassis.waitUntilDone();
//     mogoClamp.setState(true);
//     chassis.moveToPoint(-32,-60,1000);
//     chassis.moveToPoint(-12,-12,1000);
//     ladyBrown.setSetPoint(40);


// } 

void Feb9Auton() {
    chassis.setPose(-54.5, 14, 0);
    chassis.moveToPoint(-54.5, 0, 700, {.forwards = false, .maxSpeed = 90});
    chassis.turnToHeading(270,700);
    chassis.moveToPoint(-70,0,1000);
    pros::delay(300);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});
    chassis.turnToPoint(-28,28,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(-24,24,1000,{false});
    ladyBrown.setSetPoint(0);
    chassis.waitUntilDone();
    intake.setSpeed(127);
    hook.setSpeed(127);
    mogoClampP.setState(true);
    pros::delay(200);
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,700);
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
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);

}

void DEPRedSoloAWP() {
    chassis.setPose(-53.385, -15, 180);
    chassis.moveToPoint(-53.385, 0, 500, {.forwards = false});
    chassis.turnToHeading(270,500);
    chassis.moveToPoint(-70,0,500);
    pros::delay(200);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});


    chassis.turnToPoint(-24,-24,700,{.forwards = false, .earlyExitRange = 5});
    ladyBrown.setSetPoint(0);
    intake.setSpeed(127);
    hook.setSpeed(127);
    chassis.moveToPoint(-24,-24,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    chassis.turnToPoint(-24,-52,700);
    chassis.moveToPoint(-24,-54,1000);
    chassis.turnToHeading(315,700);
    intake.setSpeed(-127);
    chassis.follow(Red_Solo_AWP_txt,15,1600);
    chassis.waitUntil(20);
    mogoClampP.setState(false);
    chassis.waitUntilDone();
    chassis.turnToPoint(-20,20,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(-20,20,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    intake.setSpeed(127);
    hook.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-5,48,700);
    chassis.moveToPoint(-5,48,1000);
    chassis.moveToPoint(-24,48,1000,{.forwards = false});

    chassis.moveToPoint(-12,12,1000);

    
}

void DEPBlueSoloAWP() {
    colourSorter.setSorting(true);
    chassis.setPose(53.385, -15, 180);
    chassis.moveToPoint(53.385, 0, 500, {.forwards = false});
    chassis.turnToHeading(90,500);
    chassis.moveToPoint(70,0,500);
    pros::delay(200);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(48,0,1000,{.forwards = false, .minSpeed = 50, .earlyExitRange = 5});


    chassis.turnToPoint(24,-24,700,{.forwards = false, .earlyExitRange = 5});
    ladyBrown.setSetPoint(0);
    intake.setSpeed(127);
    chassis.moveToPoint(24,-24,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    mogoClamp.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    chassis.turnToPoint(24,-52,700);
    chassis.moveToPoint(24,-54,1000);
    chassis.turnToHeading(45,700);
    intake.setSpeed(-127);
    chassis.follow(Blue_Solo_AWP_txt,15,1600);
    chassis.waitUntil(20);
    mogoClamp.setState(false);
    chassis.waitUntilDone();
    chassis.turnToPoint(20,20,700,{.forwards = false, .earlyExitRange = 5});
    chassis.moveToPoint(20,20,1000,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    mogoClamp.setState(false);
    intake.setSpeed(127);
    hook.setSpeed(127);
    pros::delay(200);
    chassis.turnToPoint(24,48,700);
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(5,48,700);
    chassis.moveToPoint(5,48,1000);
    chassis.moveToPoint(24,48,1000,{.forwards = false});

    chassis.moveToPoint(12,12,1000,{.minSpeed = 90});

    
}

void TechMechBlue() {
    chassis.setPose(52,60,270);
    chassis.moveToPoint(15,60,1000);
    chassis.turnToHeading(280,700);
    ladyBrown.setSetPoint(LadyBrownConfigs::SCORING);
    chassis.waitUntilDone();
    pros::delay(700);

    chassis.swingToHeading(180,lemlib::DriveSide::LEFT, 700);
    chassis.moveToPoint(10,40,1000);
    chassis.swingToHeading(315,lemlib::DriveSide::LEFT, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});

}

void BlueMogoRush() {
    chassis.setPose(50,-30,90);
    chassis.follow(Blue_Mogo_Rush_txt,15,1900,false);
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.moveToPoint(30,-55,800);
    chassis.waitUntilDone();
    hook.setSpeed(0);
    chassis.moveToPoint(24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(270,700);
    pros::delay(700);
    mogoClampP.setState(false);
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(12,-24,1000,{false});
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    chassis.turnToHeading(90,1000);
    chassis.moveToPose(48,16,0,3000,{.lead = 0.7,.minSpeed = 70});
    pros::delay(500);
    mogoClampP.setState(false);
    while (!(colourSorter.getRing(0) == 2)) {
        pros::delay(10);
    }
    hook.setSpeed(0);
    chassis.moveToPoint(54,4,1000,{false});
    chassis.turnToHeading(270,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();

    // pros::delay(500);
    hook.setSpeed(127);
}

void FinalsBlueMogoRush() {
    chassis.setPose(50,-30,90);
    chassis.follow(Blue_Mogo_Rush_txt,15,2000,false);
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
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
    chassis.setPose(-50,-30,270);
    chassis.follow(Red_Mogo_Rush_txt,15,1700,false);
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
    chassis.moveToPoint(-30,-55,800);
    chassis.waitUntilDone();
    hook.setSpeed(0);
    chassis.moveToPoint(-24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(90,700);
    pros::delay(700);
    mogoClampP.setState(false);
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(-18,-24,1000,{false});
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    chassis.turnToHeading(270,1000);
    chassis.moveToPose(-45,16,0,3000,{.lead = 0.7,.minSpeed = 70});
    pros::delay(500);
    mogoClampP.setState(false);
    while (!(colourSorter.getRing(0) == 1)) {
        pros::delay(10);
    }
    hook.setSpeed(0);
    chassis.moveToPoint(-54,4,1000,{false});
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();

    // pros::delay(500);
    hook.setSpeed(127);
    
}




void FinalsRedMogoRush() {
    chassis.setPose(-50,-30,270);
    chassis.follow(Red_Mogo_Rush_txt,15,2000,false);
    chassis.waitUntilDone();
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    intake.setSpeed(127);
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
    chassis.setBrakeMode(MotorConfigs::BRAKE);

    colourSorter.stop();    
    chassis.setPose(-58,36,90);
    intake.setSpeed(127);
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{false});
    colourSorter.start();

    chassis.waitUntilDone();
    chassis.setBrakeMode(MotorConfigs::COAST);
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    chassis.moveToPoint(-24,52,1000);
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
    chassis.setBrakeMode(MotorConfigs::BRAKE);
    colourSorter.stop();    
    chassis.setPose(58,36,270);
    intake.setSpeed(127);
    chassis.follow(Blue_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(28,20,1000,{false});
    colourSorter.start();

    chassis.waitUntilDone();
    chassis.setBrakeMode(MotorConfigs::COAST);
    mogoClampP.setState(true);
    pros::delay(200);
    hook.setSpeed(127);
    chassis.moveToPoint(24,52,1000);
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
    chassis.moveToPoint(48,0,1000,{false});
    
}


#endif
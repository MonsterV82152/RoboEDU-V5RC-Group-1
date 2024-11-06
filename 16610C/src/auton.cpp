#include "main.h"

using namespace pros;
using namespace lemlib;

void moveTo(double x, double y, int t1, int t2, bool b1, bool b2) {
	chassis.turnToPoint(x, y, t1, {.forwards=b1});
	chassis.moveToPoint(x, y, t2, {.forwards=b2});
}
void move(int speed) {
	l_mg.move(speed);
	r_mg.move(speed);
}

void testCode () {
    chassis.turnToPoint(100, 0, 3000);
	chassis.turnToPoint(0, -100, 3000);
	chassis.turnToPoint(-100, 0, 3000);
	chassis.turnToPoint(0, 100, 3000);
	
	chassis.moveToPose(0, 0, 90, 3000);
	chassis.moveToPose(0, 0, 180, 3000);
	chassis.moveToPose(0, 0, 270, 3000);
	chassis.moveToPose(0, 0, 0, 3000);
}

void redPos(){
	liftState = 2;
	moveTo(0, 12.5, 0, 750, true, true);
	moveTo(-8, 12.3, 750, 750, true, true); // should be 12.5 but it dosnt rotate enough for some reason
	delay(750);
	liftState = 4;
	delay(500);
	

	moveTo(4, 12.5, 0, 1000, false, false);
	moveTo(28, -10, 500, 1500, false, false);
	delay(1500);
	intake.move_velocity(-600);
	clampStat = true;
	moveTo(28, -34.5, 1000, 2000, true, true);
	chassis.turnToPoint(42, -34.5, 750);
	delay(750);
	clamp.set_value(false);
	moveTo(42, -34.5, 750, 1000, false, false);
	delay(1000);
	intake.move_velocity(0);
	clamp.set_value(true);
	// delay(500);
	// moveTo(36, -34.5, 0, 500, false, false);
	// moveTo(40, -12, 750, 5000, false, false);
}

void redNeg() {
	// moveTo(-19, -28, 750, 1000, false, false);
	// delay(1750);
	// intake.move(-600);
	// clampStat = true;
	// moveTo(0, -35, 1000, 1000, true, true);
	// moveTo(13, -40.5, 750, 750, true, true);
	// moveTo(8, -47.5, 750, 1000, true, true);
	// moveTo(13, -40.5, 200, 750, false, false);
	// moveTo(-3, -40.5, 750, 750, true, true);
	// moveTo(-3, -48.5, 750, 1000, true, true);
	// moveTo(-3, -40.5, 200, 500, false, false);
	// moveTo(-39, -36.5, 750, 5000, true, true);


	liftState = 2;
	moveTo(0, 13.5, 0, 750, true, true);
	moveTo(8, 13.5, 750, 500, true, true);
	delay(500);
	liftState = 4;
	delay(500);
	moveTo(-4, 13.5, 0, 750, false, false);
	moveTo(-23.5, -8.5, 500, 1250, false, false);
	delay(1250);
	intake.move_velocity(-600);
	clampStat = true;
	delay(500);

	moveTo(-40, -26, 1000, 1000, true, true);
	moveTo(-30, -21, 500, 750, false, false);
	moveTo(-41, -33, 500, 1000, true, true);
	moveTo(-28, -11, 500, 1000, false, false);
	moveTo(-28, -38, 750, 1500, true, true);
	liftState = 3;
	moveTo(-36, 4, 500, 5000, false, false);
}

void bluePos() {
	liftState = 2;
	moveTo(0, 12.5, 0, 750, true, true);
	moveTo(8, 12.5, 750, 750, true, true);
	delay(750);
	liftState = 4;
	delay(500);
	
	moveTo(-4, 12.5, 0, 1000, false, false);

	moveTo(-28, -10, 500, 1500, false, false);
	delay(1500);
	intake.move_velocity(-600);
	clampStat = true;
	moveTo(-28, -34.5, 1000, 2000, true, true);
	chassis.turnToPoint(-42, -34.5, 750);
	delay(750);
	clamp.set_value(false);
	moveTo(-44, -34.5, 750, 1000, false, false);
	delay(1000);
	intake.move_velocity(0);
	clamp.set_value(true);
	// delay(500);
	// moveTo(-36, -34.5, 0, 500, false, false); 
	// moveTo(-40, -12, 750, 5000, false, false);
}

void blueNeg() {
	liftState = 2;
	moveTo(0, 12.5, 0, 750, true, true);
	moveTo(-8, 12.5, 750, 750, true, true);
	delay(750);
	liftState = 4;
	delay(500);
	moveTo(4, 12.5, 0, 750, false, false);
	moveTo(23.5, -8.5, 500, 1250, false, false);
	delay(1250);
	intake.move_velocity(-600);
	clampStat = true;
	delay(500);

	moveTo(40, -26, 1000, 1000, true, true);
	moveTo(30, -21, 500, 750, false, false);
	moveTo(41, -33, 500, 750, true, true);
	moveTo(28, -11, 500, 1000, false, false);
	moveTo(28, -38, 750, 1250, true, true);
	liftState = 3;
	moveTo(36, 4, 500, 5000, false, false);
}

void skills() {
	clampTask.suspend();
	chassis.setPose(-53, 0, 270);
	pto.set_value(false);
	liftState = 2;
	pros::delay(500);
	chassis.moveToPoint(-60,0,1000);
	chassis.waitUntilDone();
	liftState = 1;
	pros::delay(500);
	chassis.moveToPoint(-53,0,500,{false});
	
	chassis.moveToPoint(-48,-24,1500,{false});
	chassis.waitUntilDone();
	clamp.set_value(true);
	pros::delay(200);
	
	intake.move_velocity(-600);

	chassis.turnToHeading(90,1000);

	// chassis.moveToPoint(-24,-24,1000,{.minSpeed = });
	chassis.turnToHeading(180,1000);
	chassis.moveToPoint(-24,-48,1000);
	chassis.moveToPoint(0,-58,1000);
	chassis.moveToPoint(24,24,1000);
	chassis.turnToPoint(24,-48,1000);
	chassis.moveToPoint(20,-48,1000);
	// chassis.follow(bottomstart_txt,15,7000);
	// pros::delay(4000);
	// highIntakeTask.resume();
	// pros::delay(3000);
	// liftState = 3;
	// chassis.waitUntilDone();
	// liftState = 2;


	
    

    // pros::delay(500);
    // chassis.moveToPoint(-23.607, -23.442, 1500);
    // bot.stopHook();
    // chassis.waitUntilDone();
    
    // chassis.moveToPoint(-48, -24, 1500,{false});
    // //Clamp
    // chassis.waitUntilDone();
    // bot.clampOn();
    // pros::delay(100);
    // // chassis.moveToPoint(-23.607, -47.215, 2000);

    // // pros::delay(500);
    // bot.runHook(127);
    // // chassis.moveToPoint(0, -59, 2000);
    // // chassis.moveToPoint(23.607, -23.442, 2000);
    // // pros::delay(500);

    // chassis.follow(first_txt,15,6000);
    // chassis.waitUntil(100);
    // slow = true;
    // chassis.turnToPoint(24,-48,1000); 
    // chassis.moveToPoint(24, -48, 1000);
    
    // chassis.moveToPoint(0, -62, 1000);

	// // ----------------------------------------- WALL STAKE ------------------------------------------------

    // chassis.moveToPoint(-50, -60, 2000);
    // chassis.moveToPoint(-24,-48,1000,{false});
    // chassis.turnToHeading(270, 1000);
    // chassis.moveToPoint(-65,-48,1000);


    // // chassis.moveToPoint(-58.771, -47.215, 1000);
    // // chassis.moveToPoint(-58.771, -57.615, 1000,{false});
    // // chassis.moveToPoint(-40.215, -40.38, 1000);
    // chassis.turnToPoint(0,0,1000);
    // chassis.moveToPoint(-70, -70, 1000,{false});
    // chassis.waitUntilDone();
    // pros::delay(500);
    // bot.clampOff();
    // //Unclamp
    // // chassis.moveToPoint(0, 0, 3000);
    // bot.stopHook();
    // // chassis.moveToPoint(-24, 24, 2000);
    // chassis.moveToPoint(-48, 0, 1000);
    // chassis.turnToHeading(180,1000);
    // chassis.moveToPoint(-48,24,2000,{false});
    // chassis.waitUntilDone();
    // bot.clampOn();
    // //Clamp
    // pros::delay(200);
    // bot.runHook(127);
    // chassis.moveToPoint(-24,24,2000);
    // chassis.moveToPoint(-23, 49, 2000);
    // chassis.moveToPoint(0,57,1000);
    // chassis.turnToPoint(-60,47,1000);
    // chassis.moveToPoint(-59.183, 47.132, 2000);
    // chassis.moveToPoint(-47.297, 58.853, 2000);
    // chassis.moveToPoint(-60.504, 60.339, 2000, {false});
    // chassis.waitUntilDone();
    // bot.clampOff();
    // //Unclamp
    // chassis.moveToPoint(0, 48, 2000);
    // bot.stopHook();
    // chassis.waitUntilDone();    
    // chassis.moveToPoint(24,24,1000);
    // slow = true;

    // chassis.moveToPoint(0,66,1000,{false});
    // chassis.turnToHeading(90,1000);
    // chassis.moveToPoint(-5,chassis.getPose().y,1000,{false});
    // int time = 0;
    // while (time < 200) {
    //     if (distance.get_distance() < 100) {
    //         chassis.cancelAllMotions();
    //         break;
    //     }
    //     time = time + 1;
        
    //     pros::delay(10);
    // }
    // chassis.moveToPoint(chassis.getPose().x+2,chassis.getPose().y,1000);
    // chassis.waitUntilDone();
    // pros::delay(127);
    // swallMotor.move(127);
    // pros::delay(1000);
    // swallMotor.move(-127);
    // pros::delay(1000);
    // swallMotor.brake();

    // chassis.turnToHeading(315,1000);
    // chassis.moveToPoint(48,-8,2000,{false});
    // chassis.waitUntilDone();
    // bot.clampOn();

    // pros::delay(200);
    // bot.runHook(127);
    // chassis.moveToPoint(48,58,2000,{true, 80});
    // chassis.moveToPoint(48,48,1000,{false});
    // chassis.turnToPoint(0,0,1000);
    // chassis.moveToPoint(70,70,1000,{false});

    // bot.clampOff();
    // bot.runHook(-127);
    // pros::delay(200);
    // bot.stopHook();
    // // chassis.turnToHeading(180,1000);
    // // chassis.moveToPoint(48,-58,3000);
    // // chassis.moveToPoint(66,-66,1000);
    // // chassis.waitUntilDone();
    // // bot.clampOff();
    // chassis.moveToPoint(48,0,1000);
    // chassis.moveToPoint(60,-66,2000);
    // chassis.moveToPoint(-24,24,3000,{false,90,90});
    // chassis.waitUntilDone();
    // left_dr.move(60);
    // right_dr.move(60);
    // pros::delay(1000);
    // left_dr.brake();
    // right_dr.brake();

 // ========================================================================================================================================

	// liftState = 2;
	// delay(750);
	// chassis.moveToPoint(0, 8, 750);
	// delay(750);
	// liftState = 1;
	// delay(500);
	// chassis.moveToPoint(0, -4.5, 1000, {.forwards=false});
	// moveTo(-23.5, -4.5, 750, 750, false, false);
	// delay(1500);
	// clampStat = true;
	// delay(500);
	// intake.move_velocity(-600);
	// highIntakeTask.resume();
	// // gets the first goal

	// moveTo(-23.5, -28, 750, 1000, true, true);
	// // moveTo(-42, -51.5, 750, 1000, true, true);
	// // moveTo(-23.5, -75, 750, 1000, true, true);
	// chassis.moveToPose(-23.5, 75, 40, 1500, {.lead = 0.8});
	// moveTo(-47, -75, 750, 1000, true, true);
	// delay(1750);
	// highIntakeTask.suspend();
	// moveTo(-57, -51.5, 750, 1000, true, true);

	// liftState = 3;
	// moveTo(-59.5, -51.5, 750, 750, true, true);
	// delay(1500);
	// liftState = 2;
	// moveTo(-47, -51.5, 0, 1000, false, false);
	// delay(500);
	// liftState = 1;
	// // high stake

	// moveTo(-47, -28, 750, 1000, true, true);
	// moveTo(-47, -4.5, 750, 1000, true, true);
	// moveTo(-47, 5.5, 200, 1000, true, true);
	// chassis.swingToPoint(-58, -3.5, DriveSide::RIGHT, 1000);
	// moveTo(-58, -3.5, 200, 1000, true, true);
	// moveTo(-60, 4.5, 750, 750, false, false);

	// // moveTo(-47， 7.5, 200, 1000, true, true);
	// // moveTo(-47, -4.5, 200, 1000, false, false);
	// // moveTo(-58， 4.5, 750, 1000, true, true);
	// // moveTo(-60, 3.5, 750, 1000, false, false);

	// delay(1500);
	// clampStat = false;
	// delay(500);
	// moveTo(-47, -4.5, 500, 1000, true, true);
	// // lets go of the first goal

	// moveTo(23.5, -4.5, 750, 1500, false, false);
	// delay(2250);
	// clamp.set_value(true); // grabs the second goal
	// delay(500);
	
	// moveTo(23.5, -28, 750, 1000, true, true);
	// moveTo(0, -51.5, 750, 1000, true, true);
	// moveTo(23.5, -75, 750, 1000, true, true);
	// moveTo(47, -75, 750, 1000, true, true);
	// moveTo(57, -51.5, 750, 1000, true, true);
	// moveTo(47, -28, 750, 1000, true, true);
	// moveTo(47, -4.5, 750, 1000, true, true);
	// moveTo(47, 5.5, 200, 1000, true, true);
	// chassis.swingToPoint(58, -3.5, DriveSide::LEFT, 1000);
	// moveTo(58, -3.5, 200, 1000, true, true);
	// moveTo(60, 4.5, 750, 750, false, false);

	// delay(1500);
	// clamp.set_value(false);
	// delay(500);
	// moveTo(47, -4.5, 500, 1000, true, true);



	// lets go of the second goal
	
	// moveTo(60, 10, 750, 1000, false, false);
	// delay(1750);
	// clamp.set_value(false);
	// delay(500);
	// moveTo(47, -4.5, 750, 1000, true, true);
	// // drops the second goal

	// moveTo(36, -58, 750, 1500, true, true);
	// moveTo(0, -98.5, 1000, 1000, false, false);
	// delay(2000);
	// clamp.set_value(true); // gets the third goal
	// delay(500);

	// moveTo(47, -98.5, 750, 1000, true, true);
	// moveTo(60, -98.5, 200, 1000, true, true);
	// moveTo(47, -98.5, 200, 750, false, false);
	// moveTo(-47, -98.5, 1000, 2000, true, true);
	// moveTo(-60, -98.5, 200, 1000, true, true);
	// moveTo(-47, -98.5, 200, 750, false, false);
	// moveTo(-59, -112, 750, 1000, false, false);


}
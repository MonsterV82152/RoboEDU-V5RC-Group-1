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

void skills() {
	chassis.setPose(-53, 0, 270);
	pto.set_value(true);
	liftState = 2;
	pros::delay(500);
	chassis.moveToPoint(-60,0,1000);
	chassis.waitUntilDone();
	liftState = 1;
	pros::delay(500);
	liftState = 3;
	pros::delay(100);
	chassis.moveToPoint(-48,0,1000,{.forwards = false});
	chassis.turnToHeading(0,1000);
	
	chassis.moveToPoint(-48,-24,1000,{.forwards = false});
	chassis.waitUntilDone();
	
	clamp.set_value(true);
	liftState = 1;
	pros::delay(200);
	
	intake.move_velocity(-600);
	// chassis.waitUntilDone();
	// chassis.setPose(chassis.getPose().x+3,chassis.getPose().y+5,chassis.getPose().theta);
	chassis.turnToHeading(90,1000);

	chassis.moveToPoint(-24,-24,1000);
	chassis.turnToHeading(180,1000);

	chassis.follow(bottomstart_txt,15,6000);
	// chassis.moveToPoint(-24,-48,1000);
	// liftState = 3;
	// chassis.moveToPoint(0,-58,2000);
	// chassis.turnToPoint(24,-24,1000);
	// liftState = 1;
	// chassis.moveToPoint(26,-26,2000);
	// chassis.turnToPoint(24,-48,1000);
	// chassis.moveToPoint(24,-48,1000);
	chassis.moveToPoint(-48,-58,3000);
	chassis.moveToPoint(-24,-48,1000,{false});
	liftState = 3;
	chassis.turnToPoint(-58,-47,500);
	chassis.moveToPoint(-58,-47,3000,{.maxSpeed = 70});
	chassis.moveToPoint(-48,-48,1000,{false});
	chassis.turnToPoint(0,0,1000);
	intake.move_velocity(600);
	chassis.moveToPoint(-60,-60,1000,{false});
	chassis.waitUntilDone();
	clamp.set_value(false);
	delay(200);
	chassis.moveToPoint(-48,0,1000);
	liftState = 1;
	chassis.turnToHeading(180,1000);
	// chassis.waitUntilDone();
	// chassis.setPose(chassis.getPose().x,chassis.getPose().y,chassis.getPose().theta);
	chassis.moveToPoint(-48,24,1800,{false});
	chassis.waitUntilDone();
	clamp.set_value(true);
	intake.move_velocity(-600);
	delay(300);
	chassis.turnToPoint(-24,20,1000);
	chassis.moveToPoint(-24,20,2000);
	chassis.turnToHeading(0,1000);
	chassis.moveToPoint(-24,48,1000);
	chassis.turnToPoint(0,54,1000);
	chassis.moveToPoint(0,54,2000);
	chassis.moveToPoint(-24,48,1000,{false});
	liftState = 3;
	chassis.turnToPoint(-59,44,1000);
	chassis.moveToPoint(-59,44,2000,{.minSpeed = 60});
	chassis.moveToPoint(-48,48,1000,{false});
	chassis.turnToPoint(0,0,1000);
	liftState = 1;
	chassis.waitUntilDone();
	clamp.set_value(false);
	chassis.moveToPoint(-66,66,1000,{false});
	// intake.move_velocity(600);
	chassis.waitUntilDone();
	


	chassis.moveToPoint(0,48,2000);
	chassis.moveToPoint(30,30,2000);
	chassis.turnToHeading(315,1000);
	intake.brake();
	chassis.moveToPoint(56,-8,2000,{false});
	chassis.waitUntilDone();
	clamp.set_value(true);
	pros::delay(300);
	intake.move(-600);
	chassis.turnToHeading(0,1000);
	chassis.moveToPoint(48,56,1500,{.maxSpeed = 100});
	chassis.moveToPoint(48,48,1000,{false});
	chassis.turnToPoint(0,0,1000);
	chassis.moveToPoint(70,70,1000,{false});
	intake.move(600);
	clamp.set_value(false);
	chassis.follow(abcdefg_txt,15,5000);


}
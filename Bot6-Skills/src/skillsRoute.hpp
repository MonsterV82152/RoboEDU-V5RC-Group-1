#ifndef SKILLSROUTE_HPP
#define SKILLSROUTE_HPP
#include "globals.hpp"
#include "classes.hpp"

void moveTo(double x, double y, int t1, int t2, bool b1, bool b2) {
	chassis.turnToPoint(x, y, t1, {.forwards=b1});
	chassis.moveToPoint(x, y, t2, {.forwards=b2});
}
void move(int speed) {
	chassis.arcade(speed, 0);
}

void autonSkills() {

	// -56
	chassis.setPose(-53, 0, 270);
	ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE); // al1
	pros::delay(600);
	chassis.moveToPoint(-47.5, 0, 500, {.forwards = false});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(0);
	intake.setSpeed(600);
	chassis.turnToPoint(-47.5, -22, 650, {.forwards = false});
	chassis.moveToPoint(-47.5, -22, 800, {.forwards = false, .maxSpeed = 70}); // mg1
	chassis.waitUntilDone();
	intake.setSpeed(600);
	mogoClamp.setState(true);
	pros::delay(250);
	moveTo(-28, -23.5, 600, 750, true, true); // mg1 r1
	chassis.turnToPoint(26, -49, 500);
	chassis.moveToPoint(26, -49, 1800, {.maxSpeed = 90}); // mg1 r2
	moveTo(1, -40, 0, 800, false, false); // watch this y val
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	chassis.turnToPoint(2, -80, 600);
	chassis.moveToPoint(2, -80, 1750, {.maxSpeed = 60}); // ws1 r1
	pros::delay(1500);
	ladyBrown.setSetPoint(LadyBrownConfigs::SCORING); // ws1 r1 score
	pros::delay(600);
	chassis.moveToPoint(2, -47.5, 500, {.forwards = false});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(0);
	intake.setSpeed(600);
	moveTo(-47.5, -47.5, 600, 1250, true, true); // mg1 r3 r4
	intake.setSpeed(600); // don't need
	chassis.moveToPoint(-60, -47.5, 1250, {.maxSpeed = 80}); // mg1 r5
	intake.setSpeed(600); // don't need
	chassis.swingToPoint(-47.5, -59, DriveSide::RIGHT, 750);
	intake.setSpeed(600); // don't need
	chassis.moveToPoint(-47.5, -59, 750); // mg1 r6
	intake.setSpeed(600); // don't need
	moveTo(-59, -60.5, 600, 500, false, false);
	chassis.waitUntilDone();
	mogoClamp.setState(false);
	pros::delay(300);
	moveTo(-47.5, -59, 0, 600, true, true);

	chassis.turnToPoint(-49.5, 0, 750, {.forwards = false});
	chassis.moveToPoint(-49.5, 0, 1000, {.forwards = false, .maxSpeed = 100, .minSpeed = 40, .earlyExitRange = 6});
	chassis.moveToPoint(-49.5, 23.5, 1000, {.forwards = false, .maxSpeed = 60}); // mg2
	chassis.waitUntilDone();

	int currT = chassis.getPose().theta;
	chassis.setPose(-47.5, 23.5, currT);
	intake.setSpeed(600);
	mogoClamp.setState(true);
	pros::delay(250);
	moveTo(-28, 25, 600, 750, true, true); // mg2 r1 // -------------
	intake.setSpeed(600); // don't need
	chassis.turnToPoint(26, 51, 500);
	chassis.moveToPoint(26, 51, 1500, {.maxSpeed = 90}); // mg2 r2
	intake.setSpeed(600); // don't need
	chassis.moveToPoint(47.5, 61.5, 1250); // mg2 r3
	intake.setSpeed(600); // don't need
	moveTo(0, 45.5, 0, 1250, false, false); // watch this y value
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	chassis.turnToPoint(0, 80, 600);
	chassis.moveToPoint(0, 80, 1750, {.maxSpeed = 60}); // ws2 r1
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::SCORING); // ws2 r1 score
	pros::delay(600);
	chassis.moveToPoint(0, 47.5, 500, {.forwards = false});
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(0);
	intake.setSpeed(600);
	moveTo(-23.5, 47.5, 600, 750, true, true); // mg2 r4
	intake.setSpeed(600); // don't need
	chassis.moveToPoint(-60, 47.5, 1250, {.maxSpeed = 90}); // mg2 r5 r6
	intake.setSpeed(600); // don't need
	moveTo(-59, 60.5, 600, 600, false, false);
	chassis.waitUntilDone();
	mogoClamp.setState(false);
	pros::delay(300);

	moveTo(0, 47.5, 500, 1250, true, true);
	intake.setSpeed(600); // don't need
	chassis.waitUntilDone();
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	moveTo(23.5, 23.5, 500, 750, true, true);
	// -- 5 instead of 0
	chassis.turnToPoint(46, 0, 750, {.forwards = false});
	chassis.moveToPoint(46, 0, 1000, {.forwards = false, .maxSpeed = 70}); // mg3
	chassis.waitUntilDone();
	mogoClamp.setState(true);
	pros::delay(200);
	moveTo(60, 0, 750, 1000, true, true);

	chassis.waitUntilDone();
	int currT2 = chassis.getPose().theta;
	chassis.setPose(59.5, 0, currT2);
	chassis.moveToPoint(52.5, 0, 750, {.forwards = false}); // ------------
	chassis.waitUntilDone();

	// chassis.moveToPoint(47.5, 3, 1000, {.forwards = false}); // ------------
	// chassis.waitUntilDone();

	ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
	int currT1 = chassis.getPose().theta;
	chassis.setPose(53, 0, currT1);
	pros::delay(800);
	chassis.moveToPoint(47.5, 0, 500, {.forwards = false}); // mg3
	moveTo(23.5, 23.5, 500, 1000, false, false);
	ladyBrown.setSetPoint(0);
	intake.setSpeed(600);
	moveTo(0, 0, 600, 900, true, true); // mg3 r1
	// while (true) {
	// 	lcd::print(0, "X: %.3f, %.3f, %.3f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	// 	delay(20);
	// }
	intake.setSpeed(600); // don't need
	moveTo(23.5, -25, 750, 750, true, true); // mg3 r2
	intake.setSpeed(600); // don't need
	moveTo(46, -47.5, 600, 750, true, true); // mg3 r3
	intake.setSpeed(600); // don't need
	moveTo(47.5, -59, 400, 750, true, true); // mg3 r4
	chassis.waitUntilDone();
	intake.setSpeed(600); // don't need
	moveTo(59, -47.5, 750, 750, true, true); // mg3 r5
	moveTo(62, -60, 600, 750, false, false);
	// chassis.waitUntilDone();
	mogoClamp.setState(false);
	pros::delay(300);

	// ------- changed x--------------
	moveTo(40, -23.5, 300, 750, true, true);
	intake.setSpeed(0);
	ladyBrown.setSetPoint(LadyBrownConfigs::HOLD);
	moveTo(65, 24, 500, 1000, false, false);
	moveTo(68, 59, 0, 1000, false, false);
	moveTo(30, 15, 600, 750, true, true);
	chassis.waitUntilDone();
	chassis.turnToHeading(45, 750);
	
	chassis.waitUntilDone();
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -30, 1000, {.forwards = false, .maxSpeed = 110, .minSpeed = 100});
	chassis.moveToPoint(0, -40, 500, {.forwards = false, .minSpeed = 120});
	chassis.moveToPoint(0, 30, 1000, {.minSpeed = 120});
}

#endif
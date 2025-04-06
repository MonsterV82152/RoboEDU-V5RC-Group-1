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

	// -56
	chassis.setPose(-53, 0, 270);
	highStat = 1;
	delay(500);
	intake.move_velocity(-550);
	delay(600);
	highStat = 4; // al1
	delay(600);
	chassis.moveToPoint(-47.5, 0, 500, {.forwards = false});
	chassis.waitUntilDone();
	highStat = 0;
	intake.move_velocity(-550);
	chassis.turnToPoint(-47.5, -22, 650, {.forwards = false});
	chassis.moveToPoint(-47.5, -22, 800, {.forwards = false, .maxSpeed = 70}); // mg1
	chassis.waitUntilDone();
	intake.move_velocity(-550);
	clampStat = true;
	delay(250);
	moveTo(-28, -23.5, 600, 750, true, true); // mg1 r1
	chassis.turnToPoint(26, -49, 500);
	chassis.moveToPoint(26, -49, 1800, {.maxSpeed = 90}); // mg1 r2
	moveTo(1, -40, 0, 800, false, false); // watch this y val
	chassis.waitUntilDone();
	highStat = 1;
	chassis.turnToPoint(2, -80, 600);
	chassis.moveToPoint(2, -80, 1750, {.maxSpeed = 60}); // ws1 r1
	delay(1500);
	highStat = 3; // ws1 r1 score
	unjamLB = true;
	delay(600);
	chassis.moveToPoint(2, -47.5, 500, {.forwards = false});
	chassis.waitUntilDone();
	highStat = 0;
	intake.move_velocity(-550);
	moveTo(-47.5, -47.5, 600, 1250, true, true); // mg1 r3 r4
	intake.move_velocity(-550); // don't need
	chassis.moveToPoint(-60, -47.5, 1250, {.maxSpeed = 80}); // mg1 r5
	intake.move_velocity(-550); // don't need
	chassis.swingToPoint(-47.5, -59, DriveSide::RIGHT, 750);
	intake.move_velocity(-550); // don't need
	chassis.moveToPoint(-47.5, -59, 750); // mg1 r6
	intake.move_velocity(-550); // don't need
	moveTo(-59, -60.5, 600, 500, false, false);
	chassis.waitUntilDone();
	clampStat = false;
	delay(300);
	moveTo(-47.5, -59, 0, 600, true, true);

	chassis.turnToPoint(-49.5, 0, 750, {.forwards = false});
	chassis.moveToPoint(-49.5, 0, 1000, {.forwards = false, .maxSpeed = 100, .minSpeed = 40, .earlyExitRange = 6});
	chassis.moveToPoint(-49.5, 23.5, 1000, {.forwards = false, .maxSpeed = 60}); // mg2
	chassis.waitUntilDone();

	int currT = chassis.getPose().theta;
	chassis.setPose(-47.5, 23.5, currT);
	intake.move_velocity(-550);
	clampStat = true;
	delay(250);
	moveTo(-28, 25, 600, 750, true, true); // mg2 r1 // -------------
	intake.move_velocity(-550); // don't need
	chassis.turnToPoint(26, 51, 500);
	chassis.moveToPoint(26, 51, 1500, {.maxSpeed = 90}); // mg2 r2
	intake.move_velocity(-550); // don't need
	chassis.moveToPoint(47.5, 61.5, 1250); // mg2 r3
	intake.move_velocity(-550); // don't need
	moveTo(0, 45.5, 0, 1250, false, false); // watch this y value
	chassis.waitUntilDone();
	highStat = 1;
	chassis.turnToPoint(0, 80, 600);
	chassis.moveToPoint(0, 80, 1750, {.maxSpeed = 60}); // ws2 r1
	chassis.waitUntilDone();
	highStat = 3; // ws2 r1 score
	unjamLB = true;
	delay(600);
	chassis.moveToPoint(0, 47.5, 500, {.forwards = false});
	chassis.waitUntilDone();
	highStat = 0;
	intake.move_velocity(-550);
	moveTo(-23.5, 47.5, 600, 750, true, true); // mg2 r4
	intake.move_velocity(-550); // don't need
	chassis.moveToPoint(-60, 47.5, 1250, {.maxSpeed = 90}); // mg2 r5 r6
	intake.move_velocity(-550); // don't need
	moveTo(-59, 60.5, 600, 600, false, false);
	chassis.waitUntilDone();
	clampStat = false;
	delay(300);

	moveTo(0, 47.5, 500, 1250, true, true);
	intake.move_velocity(-550); // don't need
	chassis.waitUntilDone();
	highStat = 1;
	moveTo(23.5, 23.5, 500, 750, true, true);
	// -- 5 instead of 0
	chassis.turnToPoint(46, 0, 750, {.forwards = false});
	chassis.moveToPoint(46, 0, 1000, {.forwards = false, .maxSpeed = 70}); // mg3
	chassis.waitUntilDone();
	clampStat = true;
	delay(200);
	moveTo(60, 0, 750, 1000, true, true);

	chassis.waitUntilDone();
	int currT2 = chassis.getPose().theta;
	chassis.setPose(59.5, 0, currT2);
	chassis.moveToPoint(52.5, 0, 750, {.forwards = false}); // ------------
	chassis.waitUntilDone();

	// chassis.moveToPoint(47.5, 3, 1000, {.forwards = false}); // ------------
	// chassis.waitUntilDone();

	highStat = 4;
	unjamLB = true;
	int currT1 = chassis.getPose().theta;
	chassis.setPose(53, 0, currT1);
	delay(800);
	chassis.moveToPoint(47.5, 0, 500, {.forwards = false}); // mg3
	moveTo(23.5, 23.5, 500, 1000, false, false);
	highStat = 0;
	intake.move_velocity(-550);
	moveTo(0, 0, 600, 900, true, true); // mg3 r1
	// while (true) {
	// 	lcd::print(0, "X: %.3f, %.3f, %.3f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	// 	delay(20);
	// }
	intake.move_velocity(-550); // don't need
	moveTo(23.5, -25, 750, 750, true, true); // mg3 r2
	intake.move_velocity(-550); // don't need
	moveTo(46, -47.5, 600, 750, true, true); // mg3 r3
	intake.move_velocity(-550); // don't need
	moveTo(47.5, -59, 400, 750, true, true); // mg3 r4
	chassis.waitUntilDone();
	wing.set_value(true);
	intake.move_velocity(-550); // don't need
	moveTo(59, -47.5, 750, 750, true, true); // mg3 r5
	moveTo(62, -60, 600, 750, false, false);
	// chassis.waitUntilDone();
	clampStat = false;
	delay(300);

	// ------- changed x--------------
	moveTo(40, -23.5, 300, 750, true, true);
	intake.move_velocity(0);
	wing.set_value(false);
	highStat = 2;
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

// -60.19, 12.26, 222.63
// -59.79, 12.65, 222.4
void redNeg() {
	// chassis.setPose(-58, 15.5, 223);
	// highStat = 1;
	// chassis.moveToPose(-60.5, 12.75, 223, 500);
	// chassis.waitUntilDone();
	// intake.move_velocity(-550);
	// delay(600);
	// highStat = 4; // al1
	// delay(650);
	// chassis.moveToPoint(-23.5, 23.5, 1500, {.forwards = false, .maxSpeed = 80});
	// chassis.waitUntilDone();
	// highStat = 0;
	// clampStat = true;

	// delay(250);
	// intake.move_velocity(-550);
	// moveTo(-12.5, 38.5, 750, 750, true, true);
	// moveTo(-11.5, 58, 500, 1000, true, true);
	// // chassis.swingToPoint(-23.5, 23.5, DriveSide::LEFT, 750, {.forwards = false});
	// moveTo(-12.5, 38.5, 200, 500, false, false); // this does it hit cone
	// moveTo(-13.5, 30, 0, 600, false, false); // this
	// moveTo(-23.5, 23.5, 400, 750, false, false); // this
	// moveTo(-25, 47.5, 500, 1250, true, true);
	// chassis.turnToPoint(-68, 66, 500);
	// chassis.moveToPoint(-68, 66, 2750, {.maxSpeed = 85}); // this ------------
	// moveTo(-34, 51.5, 0, 750, false, false);

	// // chassis.turnToPoint(-32, 7, 750, {.forwards = false});
	// // chassis.moveToPoint(-32, 7, 2000, {.forwards = false, .maxSpeed = 70});


	chassis.setPose(-55, 23.5, 270);
	chassis.moveToPoint(-23.5, 23.5, 1100, {.forwards = false, .maxSpeed = 70});
	chassis.waitUntilDone();
	clampStat = true;
	delay(250);
	intake.move_velocity(-550);
	moveTo(-12.5, 38.5, 750, 750, true, true);
	moveTo(-11.5, 58, 500, 1000, true, true);
	// chassis.swingToPoint(-23.5, 23.5, DriveSide::LEFT, 750, {.forwards = false});
	// moveTo(-12.5, 38.5, 0, 500, false, false);
	moveTo(-13.5, 30, 200, 800, false, false); // this
	moveTo(-23.5, 23.5, 500, 750, false, false);
	moveTo(-23.5, 47.5, 500, 1250, true, true);
	chassis.turnToPoint(-66, 64, 500);
	chassis.moveToPoint(-66, 64, 2250, {.maxSpeed = 70});
	delay(750);
	highStat = 4;
	moveTo(-34, 51.5, 0, 750, false, false);
	chassis.turnToPoint(-47.5, 0, 500);
	highStat = 0;
	chassis.moveToPoint(-47.5, 0, 2250, {.minSpeed = 65, .earlyExitRange = 4});
	chassis.moveToPoint(-70, -64, 2250, {.maxSpeed = 70});
	// chassis.turnToPoint(-32, 7, 750, {.forwards = false});
	// chassis.moveToPoint(-32, 7, 2000, {.forwards = false, .maxSpeed = 70});
	
}


void redPos() {
	chassis.setPose(-55, -58, 90);
	highStat = 1;
	chassis.moveToPoint(-13, -58, 1000, {.maxSpeed = 100}); // orig -11
	delay(500);
	intake.move_velocity(-550);
	chassis.turnToPoint(0, -48, 600, {.maxSpeed = 60});
	chassis.waitUntilDone();
	highStat = 5; // mg1 rush
	delay(700);
	chassis.turnToHeading(180, 600, {.direction = AngularDirection::CW_CLOCKWISE}); // this
	// chassis.turnToPoint(-23.5, -47.5, 1150, {.direction = AngularDirection::CW_CLOCKWISE});
	chassis.waitUntilDone();
	intake.move_velocity(-150);
	highStat = 0;
	
	moveTo(-37, -61, 500, 700, false, false); // this
	moveTo(-23.5, -47.5, 300, 700, true, true); // r1
	chassis.turnToPoint(-23.5, -22, 600, {.forwards = false});
	chassis.moveToPoint(-23.5, -22, 1000, {.forwards = false, .maxSpeed = 80}); // mg2
	chassis.waitUntilDone();
	intake.move_velocity(-550);
	clampStat = true;
	chassis.turnToPoint(-54, -36, 400);
	
	chassis.moveToPoint(-54, -36, 750, {.minSpeed = 60, .earlyExitRange = 2});
	delay(400);
	clampStat = false;
	chassis.turnToPoint(-66, -66, 350, {.minSpeed = 60, .earlyExitRange = 10});
	chassis.moveToPoint(-66, -66, 1750, {.maxSpeed = 90}); // r2
	highStat = 1;
	moveTo(-56, -56, 0, 750, false, false);
	chassis.waitUntilDone();
	moveTo(-56, -1, 500, 1400, false, false);
	moveTo(-70, -1, 600, 600, true, true);

	chassis.waitUntilDone();
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -6.5, 750, {.forwards = false});
	chassis.waitUntilDone();
	highStat = 4; // al
	delay(600);
	chassis.moveToPoint(0, -100, 2000, {.forwards = false});



	// moveTo(-54, -0.5, 0, 750, false, false); // check this
	// chassis.waitUntilDone();
	// highStat = 4; // al
	// delay(600);
	// moveTo(-30, -0.5, 0, 1500, false, false);

   
   


}
// -57.84 31.51
// 58.16 15.44 137
// 60,64 12.88 137
void blueNeg() {
	// chassis.setPose(58, 15.5, 137);
	// highStat = 1;
	// chassis.moveToPose(60.5, 12.75, 137, 500);
	// chassis.waitUntilDone();
	// intake.move_velocity(-550);
	// delay(600);
	// highStat = 4; // al1
	// delay(650);
	// chassis.moveToPoint(23.5, 23.5, 1500, {.forwards = false, .maxSpeed = 80});
	// chassis.waitUntilDone();
	// highStat = 0;
	// clampStat = true;

	// delay(250);
	// intake.move_velocity(-550);
	// moveTo(12.5, 38.5, 750, 750, true, true);
	// moveTo(11.5, 58, 500, 1000, true, true);
	// // chassis.swingToPoint(-23.5, 23.5, DriveSide::LEFT, 750, {.forwards = false});
	// moveTo(12.5, 38.5, 200, 500, false, false); // this does it hit cone
	// moveTo(13.5, 30, 0, 600, false, false); // this
	// moveTo(23.5, 23.5, 400, 750, false, false); // this
	// moveTo(25, 47.5, 500, 1250, true, true);
	// chassis.turnToPoint(68, 66, 500);
	// chassis.moveToPoint(68, 66, 2750, {.maxSpeed = 85}); // this ------------
	// moveTo(34, 51.5, 0, 750, false, false);

	// // chassis.turnToPoint(32, 7, 750, {.forwards = false});
	// // chassis.moveToPoint(32, 7, 2000, {.forwards = false, .maxSpeed = 70});






	chassis.setPose(55, 23.5, 90);
	chassis.moveToPoint(23.5, 23.5, 1100, {.forwards = false, .maxSpeed = 70});
	chassis.waitUntilDone();
	clampStat = true;
	delay(250);
	intake.move_velocity(-550);
	moveTo(12.5, 38.5, 750, 750, true, true);
	moveTo(11.5, 58, 500, 1000, true, true);
	// chassis.swingToPoint(-23.5, 23.5, DriveSide::LEFT, 750, {.forwards = false});
	// moveTo(-12.5, 38.5, 0, 500, false, false);
	moveTo(13.5, 30, 200, 800, false, false); // this
	moveTo(23.5, 23.5, 500, 750, false, false);
	moveTo(23.5, 47.5, 500, 1250, true, true);
	chassis.turnToPoint(66, 64, 500);
	chassis.moveToPoint(66, 64, 2250, {.maxSpeed = 70});
	delay(750);
	highStat = 4;
	moveTo(34, 51.5, 0, 750, false, false);
	chassis.turnToPoint(47.5, 0, 500);
	highStat = 0;
	chassis.moveToPoint(47.5, 0, 2250, {.minSpeed = 65, .earlyExitRange = 4});
	chassis.moveToPoint(70, -64, 2250, {.maxSpeed = 70});
	// chassis.turnToPoint(32, 7, 750, {.forwards = false});
	// chassis.moveToPoint(32, 7, 2000, {.forwards = false, .maxSpeed = 70});
}

void bluePos() {
	chassis.setPose(55, -58, 270);
	highStat = 1;
	chassis.moveToPoint(13, -58, 1000, {.maxSpeed = 100}); // orig -11
	delay(500);
	intake.move_velocity(-550);
	chassis.turnToPoint(0, -48, 600, {.maxSpeed = 60});
	chassis.waitUntilDone();
	highStat = 5; // mg1 rush
	delay(700);
	chassis.turnToHeading(180, 600, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}); // this
	// chassis.turnToPoint(-23.5, -47.5, 1150, {.direction = AngularDirection::CW_CLOCKWISE});
	chassis.waitUntilDone();
	intake.move_velocity(-150);
	highStat = 0;
	
	moveTo(37, -61, 500, 700, false, false); // this
	moveTo(23.5, -47.5, 300, 700, true, true); // r1
	chassis.turnToPoint(23.5, -22, 600, {.forwards = false});
	chassis.moveToPoint(23.5, -22, 1000, {.forwards = false, .maxSpeed = 80}); // mg2
	chassis.waitUntilDone();
	intake.move_velocity(-550);
	clampStat = true;
	chassis.turnToPoint(54, -36, 400);
	
	chassis.moveToPoint(54, -36, 750, {.minSpeed = 60, .earlyExitRange = 2});
	delay(400);
	clampStat = false;
	chassis.turnToPoint(66, -66, 350, {.minSpeed = 60, .earlyExitRange = 10});
	chassis.moveToPoint(66, -66, 1750, {.maxSpeed = 90}); // r2
	highStat = 1;
	moveTo(56, -56, 0, 750, false, false);
	chassis.waitUntilDone();
	moveTo(56, -1, 500, 1400, false, false);
	moveTo(70, -1, 600, 600, true, true);

	chassis.waitUntilDone();
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, -6.5, 750, {.forwards = false});
	chassis.waitUntilDone();
	highStat = 4; // al
	delay(600);
	chassis.moveToPoint(0, -100, 2000, {.forwards = false});










	// highStat = 2;
	// chassis.setPose(55, -58, 270);
	// chassis.moveToPoint(13, -58, 1000); // changed orig 11
	// chassis.turnToPoint(0, -48, 600, {.maxSpeed = 60});
	// chassis.waitUntilDone();
	// highStat = 5; // mg1 rush
	// delay(500);
	// chassis.turnToPoint(23.5, -47.5, 1150, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE});
	// chassis.waitUntilDone();
	// holdTop = true;
	// intake.move_velocity(-300);
	// highStat = 0;
	// chassis.moveToPoint(23.5, -47.5, 800); // r1

	// chassis.turnToPoint(23.5, -21, 750, {.forwards = false});
	// chassis.moveToPoint(23.5, -21, 1000, {.forwards = false, .maxSpeed = 80}); // mg2
	// chassis.waitUntilDone();
	// intake.move_velocity(-550);
	// clampStat = true;
	// delay(500);
	// clampStat = false;
	
	// chassis.turnToPoint(54, -36, 400);
	// chassis.moveToPoint(54, -36, 750, {.minSpeed = 60, .earlyExitRange = 2});
	// chassis.turnToPoint(66, -66, 350, {.minSpeed = 60, .earlyExitRange = 10});
	// chassis.moveToPoint(66, -66, 1750, {.maxSpeed = 90}); // r2
	// highStat = 1;
	// moveTo(54, -54, 0, 750, false, false);

	// // chassis.turnToPoint(10, -24.5, 750);
	// // chassis.moveToPoint(10, -24, 4000, {.maxSpeed = 60});

	// chassis.waitUntilDone();
	// moveTo(54, -0.5, 500, 1000, false, false);
	// moveTo(64, -0.5, 600, 750, true, true);
	// chassis.waitUntilDone();

	// chassis.setPose(0, 0, 0);
	// chassis.moveToPoint(0, -6.5, 750, {.forwards = false});
	// chassis.waitUntilDone();
	// highStat = 4; // al
	// delay(600);
	// chassis.moveToPoint(0, -100, 2000, {.forwards = false});

}
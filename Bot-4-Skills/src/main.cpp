#include "globals.hpp"
#include "MovFunc.hpp"
#include "Autonomous_Paths.hpp"

void on_center_button() {
	
}	

void initialize() {
	pros::lcd::initialize();
	pros::screen::erase();
	// Initializes
	MotorInit();
	SensorInit();

	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to sadve resources
            pros::delay(20);
        }
    });
	pros::Task(ColourSorter, nullptr, "ColourSorter");
	pros::Task(mainWhileLoop, nullptr, "mainWhileLoop");
	
	chassis.calibrate();
	
	}

void disabled() {
}

void competition_initialize() {}

void autonomous() {
	autonomousPeriod = true;
	driverControl = false;
	// lemlib::PID PIDdistance = lemlib::PID(0.5,0.01,3);
    // // Use distance sensors to back up
	// BOOL_mogo_clamp = true;
    // while (true) {
    //     double distance2 = BackDistance2.get_distance();
    //     double distance = BackDistance.get_distance();
    //     double pidvalue = PIDdistance.update((100-((distance+distance2)/2)));
    //     chassis.arcade(pidvalue,(distance2-distance)*0.5,false,0.5); //97 works the best but we send it for 96
    //     if (abs(100-distance) < 2) {
	// 		chassis.arcade(0,0);
    //         break;
    //     }
    //     pros::delay(10);
    // }
	// hookSpeed = 127;
	Skills();
	// Chassis Calibration

	// master.clear();
	// chassis.setPose(0,0,0);
	// chassis.turnToHeading(90,100000);
	// chassis.turnToHeading(90,3000);
	// chassis.waitUntilDone();
	// double ndiff = chassis.getPose().theta-90;
	// chassis.setPose(0,0,0);
	// chassis.turnToHeading(179.9,3000);
	// chassis.waitUntilDone();
	// double odiff = chassis.getPose().theta-179.9;
	// double p;
	// double d = angularKd;
	// if (ndiff > 0) {
	// 	if (odiff > 0) {
	// 		p = angularKp-(fabs(ndiff)*0.1);
	// 	} else {
	// 		p = angularKp-(fabs(ndiff)*0.1);
	// 		d = angularKd-fabs(odiff);
	// 	}
	// } else {
	// 	if (odiff > 0) {
	// 		p = angularKp+(fabs(ndiff)*0.1);
	// 		d = angularKd+fabs(odiff);
	// 	} else {
	// 		p = angularKp+(fabs(ndiff)*0.1);
	// 	}
			
	// }
		
	// master.print(0,1,"%.5f",p);
	// pros::delay(1000);
	// master.print(1,1,"%.5f",d);
	// double tot = 0;
	// for (double i = 9.99; i<180; i += 10) {
	// 	double target = chassis.getPose().theta+i;
	// 	master.print(0,0,"%d",i);
	// 	chassis.turnToHeading(target,1500);
	// 	pros::delay(3000);
	// 	tot += target - chassis.getPose().theta;
	// }
	// master.print(0,0,"%.5f", tot);
	// pros::delay(10000);


	// chassis.turnToHeading(90,5000);
	// chassis.waitUntilDone();
	// master.print(0,0,"%f",chassis.getPose().theta-90);
	
	// pros::delay(10000);
	
	
}

void opcontrol() {
	autonomousPeriod = false;
	driverControl = true;
	while (true) {
		// Main While Loop
		
		// Run for 20 ms then update
		pros::delay(100);
		
	}
}
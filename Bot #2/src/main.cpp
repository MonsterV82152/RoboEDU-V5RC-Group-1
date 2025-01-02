#include "globals.hpp"
#include "MovFunc.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"

void on_center_button() {
	
}	

void initialize() {
	
	// pros::screen::erase();
	// Initializes
	MotorInit();
	SensorInit();

	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
    });
	pros::Task(mainWhileLoop, nullptr, "mainWhileLoop");
	// pros::Task(AutonomousSelector, nullptr, "AutonSelector");
	// pros::Task(ColourSorter, nullptr, "Colour");
	
	chassis.calibrate();
	
	}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	// Chassis Calibration

	// master.clear();
	// chassis.setPose(0,0,0);
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
	

	if (SelectedTeam) {
		if (SelectedAuton == 1) {
			RedRingRush();
		} else if (SelectedAuton == 2) {
			RedMogoRush();
		}
	} else {
		if (SelectedAuton == 1) {
			BlueRingRush();
		} else if (SelectedAuton == 2) {
			BlueMogoRush();
		}
	}
}

void opcontrol() {
	driverControl = true;
	while (true) {
		// Main While Loop
		
		// Run for 20 ms then update
		pros::delay(100);
		
	}
}
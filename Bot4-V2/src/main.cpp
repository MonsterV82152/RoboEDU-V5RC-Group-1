#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "classes.hpp"


void on_center_button() {}	

void initialize() {
	
	ladyBrown.setSetPoint(LadyBrownConfigs::LOADING);
	// pros::lcd::initialize();
	pros::screen::erase();


	// pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // delay to sadve resources
    //         pros::delay(20);
    //     }
    // });

	pros::Task(AutonomousSelector, nullptr, "AutonSelector");
	
	chassis.calibrate();
	chassis.setPose(0,0,90);
	pros::delay(500);
	master.rumble(".");
	hook.init();
	intake.init();
	ladyBrown.init();
	mogoClampP.init();
	pros::delay(500);
	master.rumble(".");
	mogoClamp.init();
	colourSorter.init();
	controls.init();
	pros::delay(500);
	master.rumble(".");
	mogoClamp.start();
	controls.start();
	}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	colourSorter.start();

	autonomousPeriod = true;
	driverControl = false;	
}

void opcontrol() {
	autonomousPeriod = false;
	driverControl = true;
	
	while (true) {
		controls.driverControls();
		pros::delay(20);
		
	}
}
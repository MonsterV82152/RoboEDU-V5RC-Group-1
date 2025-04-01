#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "classes.hpp"


void on_center_button() {}	

void initialize() {
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
	hook.init();
	intake.init();
	ladyBrown.init();
	mogoClampP.init();
	colourSorter.init();
	controls.init();
	pros::delay(500);
	master.rumble(".");
	colourSorter.setDelay(70);
	colourSorter.start();
	controls.start();

}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	autonomousPeriod = true;
	driverControl = false;
	colourSorter.setSorting(true);
	if (team) {
		if (auton == 1) {
			RedRingRush();
		} else if (auton == 2) {
			FinalsRedMogoRush();
		// } else if (auton == 3) {
		// 	RedSoloAWP();
		}
	} else {
		if (auton == 1) {
			BlueRingRush();
		} else if (auton == 2) {
			FinalsBlueMogoRush();
		// } else if (auton == 3) {
		// 	BlueSoloAWP();
		}
	}
	// RedDriveBySoloAwp();
	// RedDriveByFinals();
	// team = false; BlueDriveBySoloAwp();
	// team = false; BlueDriveByFinals();

	if (DriveTrain::backDistanceL.get_distance() > 30 || DriveTrain::backDistanceR.get_distance() > 30) {
		mogoClamp.setState(false);
	}
}

void opcontrol() {
	autonomousPeriod = false;
	driverControl = true;
	
	while (true) {
		controls.driverControls();
		pros::delay(20);
		
	}
}
#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "classes.hpp"


void on_center_button() {}	

void initialize() {
	pros::lcd::initialize();
	// pros::screen::erase();


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

	// pros::Task(gui_task, nullptr, "AutonSelector");
	
	chassis.calibrate();
	intake.init();
	ladyBrown.init();
	mogoClampP.init();
	hookTasks.init();
	controls.init();
	pros::delay(500);
	master.rumble(".");
	hookTasks.setDelay(70);
	controls.start();
	hookTasks.setSorting(true);
}

void disabled() {}
   
void competition_initialize() {}

void autonomous() {

	autonomousPeriod = true;
	driverControl = false;
	// chassis.setPose(0,0,0);
	// chassis.turnToHeading(90,10000);
	blueSAWP();
}
 
void opcontrol() {
	chassis.setPose(0,0,90);

	autonomousPeriod = false;
	driverControl = true;
	
	while (true) {
		controls.climbControlsNOMACROS();
		pros::delay(20);
		
	}
}
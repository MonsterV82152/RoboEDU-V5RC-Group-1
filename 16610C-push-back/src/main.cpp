#include "globals.hpp"
#include "Autonomous_Paths.hpp"


void on_center_button() {}	

void initialize() {
	pros::lcd::initialize();


	// pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // delay to save resources
    //         pros::delay(20);
    //     }
    // });
	
	// chassis.calibrate();
	// chassis.setPose(0,0,0);
}

void disabled() {}
   
void competition_initialize() {}

void autonomous() {
    exampleAuton();
}
 
void opcontrol() {
	while (true) {
        double rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        double leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        double leftX = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        pros::lcd::print(0, "Right X: %f", rightX);
        pros::lcd::print(1, "Left Y: %f", leftY);
        pros::lcd::print(2, "Left X: %f", leftX);
        frontLeft.move(leftY + leftX + rightX);
        middleLeft.move(leftY + rightX);
        backLeft.move(leftY - leftX + rightX);
        frontRight.move(leftY - leftX - rightX);
        middleRight.move(leftY - rightX);
        backRight.move(leftY + leftX - rightX);
        
		pros::delay(20);
		
	}
}
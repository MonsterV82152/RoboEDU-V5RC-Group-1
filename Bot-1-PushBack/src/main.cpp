#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "movements.cpp"

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
        chassis.arcade(leftY, rightX);
        if (master.get_digital_new_press(buttons::R1)) {
            if (rollers::state == "intake") {
                rollers::stop();
            } else {
                rollers::intake();
            }
        }
        if (master.get_digital_new_press(buttons::R2)) {
            if (rollers::state == "outtake") {
                rollers::stop();
            } else {
                rollers::outtake();
            }
        }
        if (master.get_digital_new_press(buttons::L2)) {
            if (rollers::state == "scoreTop") {
                rollers::stop();
            } else {
                rollers::scoreTop();
            }
        }
        if (master.get_digital_new_press(buttons::L2)) {
            if (rollers::state == "scoreMiddle") {
                rollers::stop();
            } else {
                rollers::scoreMiddle();
            }
        }

        // chassis.arcade(leftY, rightX);
        
		pros::delay(20);
		
	}
}
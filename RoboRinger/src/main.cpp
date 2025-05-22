#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mg(6); 
	pros::Motor right_mg(-1); 
	pros::Motor intake(-2);
	pros::Motor arm(-7);
	pros::ADILightSensor right_light('A');
	pros::ADILightSensor left_light('B');
	pros::ADIUltrasonic distance('C', 'D');

	arm.set_zero_position(0);

	while (true) {
		while (right_light.get_value() > 100 && left_light.get_value() > 100) {
			left_mg.move(100);
			right_mg.move(-100);
		}
		while (distance.get_value() > 50) {
			left_mg.move(right_light.get_value()-left_light.get_value());
			right_mg.move(left_light.get_value()-right_light.get_value());
		}
		intake.move(100);
		while (distance.get_value() > 25) {
			left_mg.move(right_light.get_value()-left_light.get_value());
			right_mg.move(left_light.get_value()-right_light.get_value());
		}
		left_mg.brake();
		right_mg.brake();
		pros::delay(500);
		arm.move_absolute(30,100);
		pros::delay(500);
		intake.brake();
		right_mg.move(-100);
		left_mg.move(-100);
		pros::delay(3000);
		right_mg.brake();
		left_mg.brake();
		



		pros::delay(20);                               // Run for 20 ms then update
	}
}
#include "main.h"
#include "globals.hpp"
#include "odometry.hpp"
#include "threading.cpp"
#include "MovFunc.hpp"
#include "bob.cpp"
#include <string>
#include <stdlib.h>

odometry thisbot(10, 18, 180, 0, 0, 1, 0, 1);
MasterControl bot(false, true, 0);


void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	
	swallMotor.set_zero_position(0);
	swallMotor.get_encoder_units(MOTOR_ENCODER_DEGREES);
	swallMotor.set_brake_mode(HOLD);

	left_mg.set_gearing_all(pros::E_MOTOR_GEAR_600);
	right_mg.set_gearing_all(pros::E_MOTOR_GEAR_600);
	left_mg.set_encoder_units_all(MOTOR_ENCODER_DEGREES);
	right_mg.set_encoder_units_all(MOTOR_ENCODER_DEGREES);
	thisbot.reset(10, 18, 180, 0, 0, 1, 0, 1);
	clawp.set_value(false);
	verticaltracking.reset();
	horizontaltracking.reset();
	verticaltracking.set_position(0);
	horizontaltracking.set_position(0);
	imu_sensor.reset();


	pros::screen::set_pen(0x000000FF);
	pros::screen::fill_rect(0,0,240,240);
	pros::screen::set_pen(0x00FF0000);
	pros::screen::fill_rect(240,0,480,240);
	pros::screen::set_pen(0x00000000);
	pros::screen::fill_rect(10,10,230,230);
	pros::screen::fill_rect(250,10,470,230);


	pros::screen_touch_status_s_t status = pros::screen::touch_status();
	while (true) {
		status = pros::screen::touch_status();
		if (status.x < 240 && status.press_count == 1) {
			team = false;
			pros::screen::set_pen(0x000000FF);
			break;
		} else if (status.x > 240 && status.press_count == 1){
			team = true;
			pros::screen::set_pen(0x00FF0000);
			break;
		}
		pros::delay(100);
	}

	pros::screen::fill_rect(0,0,240,120);
	pros::screen::fill_rect(240,0,480,120);
	pros::screen::fill_rect(0,120,240,240);
	pros::screen::fill_rect(240,120,480,240);
	pros::screen::set_pen(0x00000000);
	pros::screen::fill_rect(10,10,230,110);
	pros::screen::fill_rect(250,10,470,110);
	pros::screen::fill_rect(10,130,230,230);
	pros::screen::fill_rect(250,130,470,230);

	while (true) {
		status = pros::screen::touch_status();
		if (status.x < 240 && status.y < 120 && status.press_count == 2) {
			autonselector = 1;
			break;
		} else if (status.x > 240 && status.y < 120 && status.press_count == 2){
			autonselector = 3;
			break;
		} else if (status.x < 240 && status.y > 120 && status.press_count == 2){
			autonselector = 2;
			break;
		} else if (status.x > 240 && status.y > 120 && status.press_count == 2){
			autonselector = 4;
			break;
		}
		pros::delay(100);
	}
	pros::screen::erase();
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
void autonomous()
{
	// Resets Odometry
	thisbot.reset(10, 18, 180, 0, 0, 1, 0, 1);

	//Motor & Sensor Settings
	left_mg.set_brake_mode(BRAKE);
	right_mg.set_brake_mode(BRAKE);
	verticaltracking.reset();
	horizontaltracking.reset();
	verticaltracking.set_position(0);
	horizontaltracking.set_position(0);


	//Autonomous

	if (autonselector == 1 && !team) {
		thisbot.move_to(12, 50);
		thisbot.move_to(24, 54);
		thisbot.move_to(24, 62);
		clawp.set_value(true);
		pros::delay(500);
		bot.runIntake(127);
		bot.runHook(127);
		thisbot.move_to(38, 40);
		bot.stopHook();
		bot.stopIntake();
	}
	if (autonselector == 1 && !team) {
	}
	if (autonselector == 1 && !team) {
	}
	if (autonselector == 1 && !team) {
	}
	
	
}

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
void opcontrol()
{
	//Motor & Sensor Settings
	intakeMotor.set_brake_mode(COAST);
	left_mg.set_brake_mode(COAST);
	right_mg.set_brake_mode(COAST);

	/* -------------------------------------------------------------------- */

	// Variable Definition
	bool boolintake = false;
	bool boolhook = false;
	bool boolwing = true;
	bool boolclaw = true;
	bool detect = true;
	int counter = 10;
	int opcolourcounter = 0;
	bool opcolour = false;
	int alcolourcounter = 0;
	bool alcolour = false;
	bool redteam = false;

	optical_sensor.set_led_pwm(100);
	pros::Task wallscore(wallstake, nullptr, "Wallstake Task");

	/* -------------------------------------------------------------------- */
	// While True Loop
	while (true)
	{
		auto state = wallscore.get_state();

		/* Drivetrain Code */

		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_X);
		left_mg.move(left + (right * 1.05));
		right_mg.move(left - (right * 1.05));

		// Team Toggle - B
		if (master.get_digital_new_press(button_B)) // If B is Pressed
		{
			redteam = !redteam;
			if (redteam)
			{
				master.print(1, 1, "Red Team ");
			}
			else
			{
				master.print(1, 1, "Blue Team ");
			}
		}

		// Intake Toggle - R1
		if (master.get_digital_new_press(button_R1)) // If R1 is Pressed
		{
			boolintake = !boolintake;
		}

		// Claw Piston Toggle - X
		if (master.get_digital_new_press(button_X)) // If X is Pressed
		{

			boolclaw = !boolclaw;
		}

		// Hook Toggle - R2
		if (master.get_digital_new_press(button_R2)) // If R2 is Pressed
		{

			boolhook = !boolhook;
		}

		// Wing Piston Toggle - Y
		if (master.get_digital_new_press(button_Y)) // If Y is Pressed
		{
			boolwing = !boolwing;
		}

		// Toggle Activation
		if (master.get_digital(button_L1)) // If L1 is Pressed
		{
			bot.runHook(-127);
			
		}
		else if (master.get_digital(button_UP)) // If UP is pressed
		{
			bot.runHook(50);
			bot.runIntake(50);
		} else if (master.get_digital(button_L2)) { // If L2 is Pressed
			bot.runIntake(-127);
		}
		else
		{
			//Toggle Hook On/Off
			if (boolhook) {
				bot.runHook(127);
			} else {
				bot.stopHook();
			}
			if (boolintake)
			{
				bot.runIntake(127);
			}
			else
			{

				bot.stopIntake();
			}
		}
		//Toggle Claw On/Off
		if (!boolclaw)
		{
			bot.clampOn();
		}
		else
		{
			bot.clampOff();
		}
		//Toggle Wing On/Off
		if (!boolwing)
		{
			wing.set_value(true);
		}
		else
		{
			wing.set_value(false);
		}

		// Odometry Update Code
		int vertical_position = verticaltracking.get_position() / 100;
		int horizontal_position = horizontaltracking.get_position() / 100;
		int heading = imu_sensor.get_heading();
		thisbot.change(heading, vertical_position, 0);
		std::cout << "[";
		std::cout << thisbot.odeg;
		std::cout << ", ";
		std::cout << thisbot.xpos;
		std::cout << ", ";
		std::cout << thisbot.ypos;
		std::cout << "]   ";
		pros::delay(20);
	}
}
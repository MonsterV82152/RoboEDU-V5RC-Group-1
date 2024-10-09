#include "main.h"
#include "globals.hpp"
#include "odometry.hpp"
#include "threading.cpp"
#include "MovFunc.hpp"
#include "funcs.cpp"

#include <string>
#include <stdlib.h>

// Master Control for All Bot Functions
MasterControl bot(false, true, 0);



// Lemlib Initialization
lemlib::Drivetrain drivetrain(&left_dr, &right_dr, 13, lemlib::Omniwheel::NEW_325, 360, 2);
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracking, lemlib::Omniwheel::NEW_2, -1);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracking, lemlib::Omniwheel::NEW_2, 1);
lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu_sensor);
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
											0, // integral gain (kI)
											3, // derivative gain (kD)
											3, // anti windup
											1, // small error range, in inches
											100, // small error range timeout, in milliseconds
											3, // large error range, in inches
											500, // large error range timeout, in milliseconds
											20 // maximum acceleration (slew)
);
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
											0, // integral gain (kI)
											10, // derivative gain (kD)
											3, // anti windup
											1, // small error range, in degrees
											100, // small error range timeout, in milliseconds
											3, // large error range, in degrees
											500, // large error range timeout, in milliseconds
											0 // maximum acceleration (slew)
);
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);



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

void initialize()
{
	chassis.calibrate();

	left_dr.set_gearing_all(pros::E_MOTOR_GEAR_BLUE);
	right_dr.set_gearing_all(pros::E_MOTOR_GEAR_BLUE);

	swallMotor.set_zero_position(0);
	swallMotor.get_encoder_units(MOTOR_ENCODER_DEGREES);
	swallMotor.set_brake_mode(HOLD);



	clawp.set_value(false);
	imu_sensor.reset();

	// Autonomous Selection
	autonSelector();

	// Position Update
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
}

void disabled() {}
//Runs when the robot is disabled

void competition_initialize() {}
//Runs when the match starts

void autonomous()
{

	//Motor & Sensor Settings
	vertical_tracking.reset();
	horizontal_tracking.reset();
	vertical_tracking.set_position(0);
	horizontal_tracking.set_position(0);


	//Autonomous
	if (autonselector == 1 && !team) {
	}
	if (autonselector == 1 && !team) {
	}
	if (autonselector == 1 && !team) {
	}
	if (autonselector == 1 && !team) {
	}
	
	
}

void opcontrol()
{
	//Motor & Sensor Settings
	intakeMotor.set_brake_mode(COAST);
	right_dr.set_brake_mode(COAST);
	left_dr.set_brake_mode(COAST);


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
		right_dr.move(left + (right * 1.05));
		left_dr.move(left - (right * 1.05));

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
	}
}
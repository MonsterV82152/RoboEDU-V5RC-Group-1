#include "main.h"
#include "globals.hpp"

inline void coloursorter(void *param) {
	pros::delay(3000);

	int speed = hookMotor.get_voltage();
	hookMotor.set_encoder_units(MOTOR_ENCODER_DEGREES);
    optical_sensor.set_led_pwm(100);
    while (true) {
		// if (master.get_digital_new_press(button_DOWN)) {
		// 	slow = !slow;
		// }
		// if (HookSpeed > 100 && hookMotor.get_actual_velocity() < 10) {
		// 	hookMotor.move(127);
		// 	pros::delay(100);
		// 	hookMotor.move(HookSpeed);
		// }
		if (slow) {
			hookMotor.move_velocity(60);
		} else {
			hookMotor.move(HookSpeed);
		}
		// } else {
		// 	int speed = hookMotor.get_voltage();
		// }
       

		// std::cout << speed;
        int mult = 2-(127/speed); // Calculate Delay Multiplier
        double a = optical_sensor.get_hue();
        // pros::screen::set_pen(0x00DC143C);
        // pros::screen::erase();
        // pros::screen::draw_circle(speed,speed,10);
		// pros::screen::draw_circle(127,127,10);
    
            if (a >= 0 && a <= 30)
            {
                if (!team) {
                    pros::delay(30);
                    hookMotor.move(-127);
					
                    pros::delay(200);
                    hookMotor.move(HookSpeed);
					pros::delay(200);
                } else if (slow) {
					a = hookMotor.get_position();
					while (abs(hookMotor.get_position()-a) < 72) {
						pros::delay(5);
					}
					hookMotor.brake();
					pros::delay(200);
					hookMotor.move(-70);
					pros::delay(2000);
					hookMotor.move(HookSpeed);
					pros::delay(200);
					slow = false;

				}
            }
            if (a >= 200 && a <= 220)
            {
                if (team) {
                    pros::delay(30);
                    hookMotor.move(-127);
                    pros::delay(200);
                    hookMotor.move(HookSpeed); 
					pros::delay(200);
                } else if (slow) {
					a = hookMotor.get_position();
					while (abs(hookMotor.get_position()-a) < 72) {
						pros::delay(5);
					}
					hookMotor.brake();
					pros::delay(200);
					hookMotor.move(-70);
					pros::delay(2000);
					hookMotor.move(HookSpeed);
					pros::delay(200);
					slow = false;
				}
            }

        pros::delay(50);
					
    }
}



inline void logs(void *param) {

	float angle = imu_sensor.get_heading();
    optical_sensor.set_led_pwm(100);
    while (true) {
		float angle = imu_sensor.get_heading();
		
        pros::delay(50);
					
    }
}
#include "globals.hpp"

extern void InitalizeSetup() {
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
	pros::delay(500);

	while (true) {
		status = pros::screen::touch_status();
		if (status.x < 240 && status.y < 120 && status.press_count > 1) {
			autonselector = 1;
			break;
		} else if (status.x > 240 && status.y < 120 && status.press_count > 1){
			autonselector = 2;
			break;
		} else if (status.x < 240 && status.y > 120 && status.press_count > 1){
			autonselector = 3;
			break;
		} else if (status.x > 240 && status.y > 120 && status.press_count > 1){
			autonselector = 4;
			break;
		}
		pros::delay(100);
	}
	pros::screen::erase();
}


inline void coloursorter(void *param) {
	pros::delay(3000);

	int speed = hookMotor.get_voltage();
	hookMotor.set_encoder_units(MOTOR_ENCODER_DEGREES);
    optical_sensor.set_led_pwm(100);
    while (true) {
		if (master.get_digital_new_press(button_DOWN)) {
			slow = !slow;
		}

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
					while (abs(hookMotor.get_position()-a) < 85) {
						pros::delay(10);
					}
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
					while (abs(hookMotor.get_position()-a) < 85) {
						pros::delay(10);
					}
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

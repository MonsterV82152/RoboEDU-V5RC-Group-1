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
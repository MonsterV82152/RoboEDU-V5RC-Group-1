#include "main.h"
#include "globals.hpp"

void wallstake(void *param)
{
	bool scoring = false;
	while (true)
	{
		if (master.get_digital_new_press(button_A))
		{
			scoring = true;
			swall.move(127);
			pros::delay(100);
		}

		if (scoring && swall.get_position() < 520) {
			if (swall.get_actual_velocity() < 10) {
				scoring = false;
				swall.move(-127);
			}
		} else if (scoring) {
			scoring = false;
			swall.move(-127);
		}

		if (!scoring && swall.get_position() < 10 && swall.get_target_velocity() < 10) {
			swall.brake();

		}


		pros::delay(100);
	}
}
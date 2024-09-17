#include "main.h"
#include "globals.hpp"

inline void wallstake(void *param)
{
	std::cout << "while loop";
	swall.set_brake_mode(COAST);
	while (true)
	{
		if (master.get_digital(button_A)) {
			swall.move(-127);
		} else {
			swall.brake();
		}
		pros::delay(100);
	}
}
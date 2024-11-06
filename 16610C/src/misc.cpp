#include "main.h"

using namespace pros;
using namespace lemlib;

void misc_() {
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) { 
        master.clear();
        master.print(1, 0, "neutral");
        if (highIntakeTask.get_state() == 3) {
            intakeTask.resume();
        }
        colorMin = 0;
        colorMax = 0;
    }

    else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
        master.clear();
        master.print(1, 0, "blue team");
        if (highIntakeTask.get_state() == 3) {
            intakeTask.resume();
        }
        colorMin = redMin;
        colorMax = redMax;
    }

    else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
        master.clear();
        master.print(1, 0, "red team");
        if (highIntakeTask.get_state() == 3) {
            intakeTask.resume();
        }
        colorMin = blueMin;
        colorMax = blueMax;
    }
}

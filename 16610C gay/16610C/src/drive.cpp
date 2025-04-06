#include "main.h"

using namespace pros;
using namespace lemlib;

void drive_() {
    leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
    rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

    // chassis.curvature(leftY, rightX, true);

    chassis.arcade(leftY, rightX, false, 0.5);
}

#include "main.h"

using namespace pros;
using namespace lemlib;


void drive_() {
    leftY = master.get_analog(ANALOG_LEFT_Y);
    rightX = master.get_analog(ANALOG_RIGHT_X);

    chassis.arcade(leftY, rightX, true, 0.5);
}

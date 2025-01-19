#include "main.h"

void basics() {
    pros::Motor test(4);
    test.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    test.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    test.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    test.brake();

    test.move(127); // forwards
    test.move(-127); // reverse

    test.set_reversed(true);
    test.set_gearing(pros::E_MOTOR_GEAR_BLUE);
    int x = test.get_position();

    


}




#include "globals.hpp"
#include "main.h"

class odometry {
    public:
        double xpos;
        double ypos;
        double orad;
        double xrad;
        double yrad;
        double wheelr;

        odometry(int x, int y, int irad, int xirad, int yirad, int iwheelr);
        void change(double imu, double xtrack, double ytrack);
        void move_to(double targetx, double targety);


};
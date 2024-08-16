#include "global.hpp"
#include "main.h"

class odom {
    public:
        double xpos;
        double ypos;
        double orad;
        double xrad;
        double yrad;
        double wheelr;

        odom(int x, int y, int irad, int xirad, int yirad, int iwheelr);
        void change(int imu, int xtrack, int ytrack);
        void move_to(double targetx, double targety);


};
#include "globals.hpp"
#include "pidcontrol.hpp"
#include "main.h"

#ifndef ODOMETRY_HPP
#define ODOMETRY_HPP

class odometry {
    public:
        double xpos = 0;
        double ypos = 0;
        double orientationradian = 0;
        double odeg = 0;
        double horizontalradian = 0;
        double verticalradian = 0;
        double wheelradius = 0;
        double hdif = 0;
        double vdif = 0;
        pid distanceodomPID;
        pid turnPID;

        odometry(double x, double y, double irad, double xirad, double yirad, double iwheelr, double hdis, double vdis);
        void reset(double x, double y, double irad, double xirad, double yirad, double iwheelr, double hdis, double vdis);
        void change(double imu, double ytrack, double xtrack);
        void move_to(double targetx, double targety);
        void move_to_backward(double targetx, double targety);
        void spin_to(double angle);


};

#endif 
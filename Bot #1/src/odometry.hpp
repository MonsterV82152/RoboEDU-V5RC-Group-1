#include "globals.hpp"
#include "pidcontrol.hpp"
#include "main.h"

class odometry {
    public:
        double xpos;
        double ypos;
        double orad;
        double odeg;
        double xrad;
        double yrad;
        double wheelr;
        double hdif;
        double vdif;
        pid odomPID;
        pid turnPID;

        odometry(double x, double y, double irad, double xirad, double yirad, double iwheelr, double hdis, double vdis);
        void reset(double x, double y, double irad, double xirad, double yirad, double iwheelr);
        void change(double imu, double ytrack);
        void move_to(double targetx, double targety);
        void spin_to(double angle);


};
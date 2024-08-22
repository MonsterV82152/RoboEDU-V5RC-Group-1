
#include "odometry.hpp"


/**
 * Moves the Robot to a target location
 * 
 * \param x Starting X pos
 * \param y Starting Y pos
 * \param irad Starting Heading
 * \param xirad Horizontal Tracking Wheel position
 * \param yirad Vertical Tracking Wheel position
 * \param iwheelr Tracking wheel Radius
 */
odometry::odometry(int x, int y, int irad, int xirad, int yirad, int iwheelr) {
    xpos = x;
    ypos = y;
    orad = irad*PI/180;
    odeg = irad;
    xrad = xirad*PI/180;
    yrad = yirad*PI/180;
    wheelr = iwheelr;
}
void odometry::reset(int x, int y, int irad, int xirad, int yirad, int iwheelr) {
    xpos = x;
    ypos = y;
    orad = irad*PI/180;
    odeg = irad;
    xrad = xirad*PI/180;
    yrad = yirad*PI/180;
    wheelr = iwheelr;
}

/**
 * Updates the Bot Position
 * 
 * \param imu Current IMU Heading
 * \param xtrack Current Horizontal Tracking Wheel Position
 * \param ytrack Current Vertical Tracking Wheel Position
 */
void odometry::change(double imu, double xtrack, double ytrack) {
    xtrack = xtrack*PI/180;
    ytrack = ytrack*PI/180;
    double xdif = xtrack-xrad;
    double ydif = ytrack-yrad;
    double xdis = xdif*wheelr;
    double ydis = ydif*wheelr;
    orad = imu*PI/180;
    odeg = imu;
    double ychange = ydis * cos(orad);// - xdis * sin(orad);
    double xchange = ydis * sin(orad);// + xdis * cos(orad);
    xrad = xtrack;
    yrad = ytrack;
    xpos = xpos + xchange;
    ypos = ypos + ychange;

}

/**
 *  Moves the Robot to a target location
 * 
 * \param targetx x component of target location
 * \param targety y component of target location
 */
void odometry::move_to(double targetx, double targety) {
    double xdif = targetx-xpos;
    double ydif = targety-ypos;
    double totaldis = sqrt(pow(xdif,2)+pow(ydif,2));
    double angle = asin(xdif/totaldis);
    angle = angle*180/PI;
    std::cout << angle << '\n';
    double angledif = angle-odeg;
    double mult = angledif/90;
    while (abs(xdif) >= 0.2 || abs(ydif) >= 0.2) {
        change(imu_sensor.get_heading(),horizontaltracking.get_position()/100,verticaltracking.get_position()/100);
        xdif = targetx-xpos;
        ydif = targety-ypos;
        totaldis = sqrt(pow(xdif,2)+pow(ydif,2));
        angle = asin(xdif/totaldis);
        angle = angle*180/PI;
        if (abs(odeg-angle) <= abs(odeg-(angle+360))) {
            angledif = angle-odeg;
        } else {
            angledif = (360-odeg)-angle;
        }
        std::cout << "[";
        std::cout << xpos;
        std::cout << ", ";
        std::cout << ypos;
        // std::cout << ", ";
        // angledif = angle-odeg;
        // std::cout << angledif;
        std::cout << "]";
        std::cout << "\n";
        mult = abs(angledif)/90;

        if (mult > 1) {mult=1;}
        if (angledif > 0) {

            left_mg.move(60);
            right_mg.move((-120*mult)+60);
        } else {
            left_mg.move((-120*mult)+60);
            right_mg.move(60);
        }
        pros::delay(20);
    }
    std::cout << 'done';
    left_mg.brake();
    right_mg.brake();

}

}


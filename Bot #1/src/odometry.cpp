
#include "odometry.hpp"
#ifndef Odomc
#define Odomc

/*
Constructor: Creates Odometry Environment for the Robot and sets up relevant parameters

Parameters:

int x: 


*/
odometry::odometry(int x, int y, int irad, int xirad, int yirad, int iwheelr) {
    xpos = x;
    ypos = y;
    orad = irad;
    xrad = xirad*PI/180;
    yrad = yirad*PI/180;
    wheelr = iwheelr;
}


void odometry::change(double imu, double xtrack, double ytrack) {
    xtrack = xtrack*PI/180;
    ytrack = ytrack*PI/180;
    double xdif = xtrack-xrad;
    double ydif = ytrack-yrad;
    double xdis = xdif*wheelr;
    double ydis = ydif*wheelr;
    orad = imu*3.1416/180;
    double ychange = ydis * cos(orad);// - xdis * sin(orad);
    double xchange = ydis * sin(orad);// + xdis * cos(orad);
    xrad = xtrack;
    yrad = ytrack;
    xpos = xpos + xchange;
    ypos = ypos + ychange;

}

void odometry::move_to(double targetx, double targety) {
    double xdif = targetx-xpos;
    double ydif = targety-ypos;
    double angle = asin(ydif/xdif);
    while (abs(xdif) <= 0.1 && abs(ydif) <= 0.1) {}

}




#endif
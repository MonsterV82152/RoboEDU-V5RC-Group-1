
#include "odometry.hpp"



/**
 * Moves the Robot to a target location
 * 
 * \param x Starting X pos
 * \param y Starting Y pos
 * \param irad Starting Heading
 * \param xirad Horizontal Tracking Wheel position
 * \param yirad Vertical Tracking Wheel position
 * \param iwheelradius Tracking wheel Radius
 */

// odometry::odometry(int x, int y, int irad, int xirad, int yirad, int iwheelradius) {
//     xpos = x;
//     ypos = y;
//     orientationradian = irad*PI/180;
//     odeg = irad;
//     xrad = xirad*PI/180;
//     horizontalradian = yirad*PI/180;
//     wheelradius = iwheelradius;
//     odomPID(odomKp,odomKi,odomKd,5,true);
    
// }

odometry::odometry(double x, double y, double irad, double xirad, double yirad, double iwheelradius, double hdis, double vdis)
    : xpos(x), ypos(y), orientationradian(irad), horizontalradian(xirad*PI/180), verticalradian(yirad*PI/180), wheelradius(iwheelradius),hdif(hdis),vdif(vdis),
      odomPID(odomKp, odomKi, odomKd, 5, true), turnPID(turnKp, turnKi, turnKd, 5, true) {}

void odometry::reset(double x, double y, double irad, double xirad, double yirad, double iwheelradius) {
    xpos = x;
    ypos = y;
    orientationradian = irad*PI/180;
    odeg = irad;
    horizontalradian = xirad*PI/180;
    verticalradian = yirad*PI/180;
    wheelradius = iwheelradius;
    odomPID.reset();
}

/**
 * Updates the Bot Position
 * 
 * \param imu Current IMU Heading
 * \param xtrack Current Horizontal Tracking Wheel Position
 * \param ytrack Current Vertical Tracking Wheel Position
 */
void odometry::change(double imu, double ytrack) {
    //void odometry::change(double imu, double xtrack, double ytrack) {
    // xtrack = xtrack*PI/180;
    double angledif = (imu-odeg)*PI/180;
    ytrack = ytrack*PI/180;
    double offset = 2*vdif*PI*(angledif/(PI*2));
    // double xdif = xtrack-xrad;
    double ydif = ytrack-horizontalradian+offset;

    // double xdis = xdif*wheelradius;
    double ydis = ydif*wheelradius;
    odeg = imu;
    orientationradian = imu*PI/180;

    
    double ychange = ydis * cos(orientationradian);// - xdis * sin(orientationradian);
    double xchange = ydis * sin(orientationradian);// + xdis * cos(orientationradian);
    // xrad = xtrack;
    horizontalradian = ytrack;
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
    // double totaldis = sqrt(pow(xdif,2)+pow(ydif,2));
    double angle = atan2(xdif, ydif);
    angle = angle * 180 / PI;
    if (angle < 0) {
        angle += 360;
    }
    std::cout << '[' << xpos << ',' << ypos << ',' << orientationradian << ',' << odeg << ',' << wheelradius << ',' << angle << "]" << "\n";
    std::cout << angle << '\n';
    double angledif = angle-odeg;
    double mult = angledif/90;
    while (abs(xdif) >= 0.3 || abs(ydif) >= 0.3) {
        std::cout << '[' << xpos << ',' << ypos << ',' << odeg << ',' << angle << "]" << "\n";
        change(imu_sensor.get_heading(),verticaltracking.get_position()/100);
        xdif = targetx-xpos;
        ydif = targety-ypos;
        // totaldis = sqrt(pow(xdif,2)+pow(ydif,2));
        double angle = atan2(xdif, ydif);
        angle = angle * 180 / PI;
        if (angle < 0) {
            angle += 360;
        }
        std::cout << '[' << xpos << ',' << ypos << ',' << odeg << ',' << angle << "]" << "\n";
        if (abs(odeg-angle) <= abs(odeg-(angle+360)) && abs(odeg-angle) <= abs((odeg+360)-angle)) {
            angledif = angle-odeg;
        } else if (abs(odeg-(angle+360)) <= abs((odeg+360)-angle)) {
            
            angledif = (360-odeg)+angle;
        } else {
            angledif = -((360-angle)+odeg);
        }
        // std::cout << "[" << xpos << "," << ypos << "]" << "\n";

        float pidresult = odomPID.update(angledif);

        mult = abs(angledif)/45;
        if (mult > 1) {mult=1;}
        // std::cout << angledif << "\n";
        if (angledif > 0) {

            left_mg.move(60+pidresult);
            right_mg.move(((-120*mult)+60)-pidresult);
        } else {
            left_mg.move(((-120*mult)+60)-pidresult);
            right_mg.move(60+pidresult);
        }
        pros::delay(20);
    }
    std::cout << "done \n";
    
    left_mg.brake();
    right_mg.brake();

}

void odometry::spin_to(double angle) {
    double angledif = odeg-angle;
    if (abs(odeg-angle) <= abs(odeg-(angle+360)) && abs(odeg-angle) <= abs((odeg+360)-angle)) {
            angledif = angle-odeg;
        } else if (abs(odeg-(angle+360)) <= abs((odeg+360)-angle)) {
            
            angledif = (360-odeg)+angle;
        } else {
            angledif = -((360-angle)+odeg);
        }
    while (abs(angledif) >= 1) {
        double angledif = odeg-angle;
        if (abs(odeg-angle) <= abs(odeg-(angle+360)) && abs(odeg-angle) <= abs((odeg+360)-angle)) {
            angledif = angle-odeg;
        } else if (abs(odeg-(angle+360)) <= abs((odeg+360)-angle)) {
            
            angledif = (360-odeg)+angle;
        } else {
            angledif = -((360-angle)+odeg);
        }
        double pidresult = turnPID.update(angledif);
        if (angledif > 0) {
            left_mg.move(pidresult);
        } else {
            right_mg.move(-pidresult);
        }
    }
}



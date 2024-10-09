
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

odometry::odometry(double x = 0, double y = 0, double irad = 0, double xirad = 0, double yirad = 0, double iwheelradius = 0, double hdis = 0, double vdis = 0)
    : xpos(x), ypos(y), orientationradian(irad*PI/180), horizontalradian(xirad*PI/180), verticalradian(yirad*PI/180), wheelradius(iwheelradius),hdif(hdis),vdif(vdis),
      distanceodomPID(odomKp, odomKi, odomKd, 5, true), turnPID(turnKp, turnKi, turnKd, 5, true) {
        imu_sensor.set_heading(irad);
      }

void odometry::reset(double x, double y, double irad = false, double xirad = false, double yirad = false, double iwheelradius = false, double hdis = false, double vdis = false) {
    xpos = x;
    ypos = y;
    if (irad) {orientationradian = irad*PI/180;odeg = irad;imu_sensor.set_heading(irad);}
    if (xirad) {horizontalradian = xirad*PI/180;}
    if (yirad) {verticalradian = yirad*PI/180;}
    if (iwheelradius) {wheelradius = iwheelradius;}
    if (hdis) {hdif = hdis;}
    if (vdis) {vdif = vdis;}
    distanceodomPID.reset();
    turnPID.reset();
}

/**
 * Updates the Bot Position
 * 
 * \param imu Current IMU Heading
 * \param xtrack Current Horizontal Tracking Wheel Position
 * \param ytrack Current Vertical Tracking Wheel Position
 */
void odometry::change(double imu, double ytrack, double xtrack) {
    //void odometry::change(double imu, double xtrack, double ytrack) {
    xtrack = xtrack*PI/180;
    double angledif = (imu-odeg)*PI/180;
    ytrack = ytrack*PI/180;
    double offset = 2*vdif*PI*(angledif/(PI*2));
    double xdif = xtrack-horizontalradian;
    double ydif = ytrack-verticalradian+offset;

    double xdis = xdif*wheelradius;
    double ydis = ydif*wheelradius;
    odeg = imu;
    orientationradian = imu*PI/180;

    
    double ychange = ydis * cos(orientationradian);// - xdis * sin(orientationradian);
    double xchange = ydis * sin(orientationradian);// + xdis * cos(orientationradian);
    // xrad = xtrack;
    verticalradian = ytrack;
    horizontalradian = xtrack;
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
    double totaldis;
    double angle = atan2(xdif, ydif) * 180 / PI;
    if (angle < 0) {
        angle += 360;
    }
    double angledif = angle-odeg;
    double mult;
    while (abs(xdif) >= 0.1 || abs(ydif) >= 0.1) {
        change(imu_sensor.get_heading(),-(verticaltracking.get_position()/100),0);
        xdif = targetx-xpos;
        ydif = targety-ypos;
        totaldis = sqrt(pow(xdif,2)+pow(ydif,2));
        double angle = atan2(xdif, ydif) * 180 / PI;
        if (angle < 0) {
            angle += 360;
        }
        if (abs(odeg-angle) <= abs(odeg-(angle+360)) && abs(odeg-angle) <= abs((odeg+360)-angle)) {
            angledif = angle-odeg;
        } else if (abs(odeg-(angle+360)) <= abs((odeg+360)-angle)) {
            angledif = (360-odeg)+angle;
        } else {
            angledif = -((360-angle)+odeg);
        }
        if (abs(angledif) > 90) {
            totaldis = -totaldis;
            if (angledif < 0) {
                angledif = 180+angledif;
            } else {
                angledif = -(180-angledif);
            }
        }

        float distancepidresult = distanceodomPID.update(totaldis);
        float anglepidresult = turnPID.update(angledif);

        left_mg.move((distancepidresult+anglepidresult));
        right_mg.move((distancepidresult-anglepidresult));
        
        pros::delay(20);
    }
    pros::screen::erase();
    pros::screen::print(pros::E_TEXT_SMALL,0,"done");

    
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



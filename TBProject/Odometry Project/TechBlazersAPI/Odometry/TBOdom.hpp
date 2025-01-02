#include "TBGlobals.hpp"




class TankDR {
    private:
    double xPos;
    double yPos;
    double HeadingDeg;
    double HeadingRad;
    bool exit;
    TBPid *angularController;
    TBPid *lateralController;
    TBTrackingWheel *verticalTW;
    TBTrackingWheel *horizontalTW;
    float vertTWOffset;
    float horiTWOffset;
    pros::IMU *TBImu;
    pros::MotorGroup *TBrightDr;
    pros::MotorGroup *TBleftDr;
    pros::Task movement;
    pros::Task timeoutTask;
    
    public:
    TankDR(pros::MotorGroup *rightDrI, 
           pros::MotorGroup *leftDrI, 
           TBPid *angularControllerI, 
           TBPid *lateralControllerI, 
           pros::IMU *imuI, 
           TBTrackingWheel *verticalTWI, 
           float vertTWOffsetI,
           TBTrackingWheel *horizontalTWI,
           float horiTWOffsetI);
    void update();
    void setPose(float x, float y, float theta);
    void moveToPoint(float x, float y, float timeout, bool forwards = true, float maxSpeed = 127, float minSpeed = 0);
    void turnToHeading(float theta, float timeout);
    void calibrate();

    
    

};
#include "TBOdom.hpp"

TankDR::TankDR(pros::MotorGroup *rightDrI,
               pros::MotorGroup *leftDrI,
               TBPid *angularControllerI,
               TBPid *lateralControllerI,
               pros::IMU *imuI,
               TBTrackingWheel *verticalTWI,
               float vertTWOffsetI,
               TBTrackingWheel *horizontalTWI,
               float horiTWOffsetI) : TBrightDr(rightDrI), TBleftDr(leftDrI), angularController(angularControllerI), lateralController(lateralControllerI), TBImu(imuI), verticalTW(verticalTWI), horizontalTW(horizontalTWI), movement(nullptr), timeoutTask(nullptr), exit(false), vertTWOffset(vertTWOffsetI), horiTWOffset(horiTWOffsetI)
{
    movement.suspend();
    timeoutTask.suspend();
}

void TankDR::calibrate()
{
    angularController->reset();
    lateralController->reset();
    verticalTW->calibrate();
    horizontalTW->calibrate();
    pros::Task IMU_calibrate([&]()
                             {
        TBImu->reset();
        pros::delay(2500); });
}

void TankDR::moveToPoint(float x, float y, float timeout, bool forwards = true, float maxSpeed = 127, float minSpeed = 0)
{

    while (movement.get_state() != pros::E_TASK_STATE_SUSPENDED)
    {
        pros::delay(20);
    }
    timeoutTask.resume();
    movement.resume();
    timeoutTask.create([&]()
                       {
        pros::delay(timeout);
        exit = true; });
    movement.create([&]()
                    {
                        double xdif = x - xPos;
                        double ydif = y - yPos;
                        double totaldis;
                        double angle = atan2(xdif, ydif) * 180 / PI;
                        if (angle < 0)
                        {
                            angle += 360;
                        }
                        double angledif = angle - HeadingDeg;
                        double mult;
                        while ((abs(xdif) >= 0.1 || abs(ydif) >= 0.1) && !exit)
                        {
                            update();
                            xdif = x - xPos;
                            ydif = y - yPos;
                            totaldis = sqrt(pow(xdif, 2) + pow(ydif, 2));
                            double angle = atan2(xdif, ydif) * 180 / PI;
                            if (angle < 0)
                            {
                                angle += 360;
                            }
                            if (abs(HeadingDeg - angle) <= abs(HeadingDeg - (angle + 360)) && abs(HeadingDeg - angle) <= abs((HeadingDeg + 360) - angle))
                            {
                                angledif = angle - HeadingDeg;
                            }
                            else if (abs(HeadingDeg - (angle + 360)) <= abs((HeadingDeg + 360) - angle))
                            {
                                angledif = (360 - HeadingDeg) + angle;
                            }
                            else
                            {
                                angledif = -((360 - angle) + HeadingDeg);
                            }
                            if (!forwards)
                            {
                                totaldis = -totaldis;
                                if (angledif < 0)
                                {
                                    angledif = 180 + angledif;
                                }
                                else
                                {
                                    angledif = -(180 - angledif);
                                }
                            }

                            float distancepidresult = lateralController->update(totaldis);
                            float anglepidresult = angularController->update(angledif);
                            float leftresult = distancepidresult + anglepidresult;
                            float rightresult = distancepidresult - anglepidresult;
                            if (leftresult > maxSpeed)
                            {
                                leftresult = maxSpeed;
                            }
                            else if (leftresult < minSpeed)
                            {
                                leftresult = minSpeed;
                            }
                            if (rightresult > maxSpeed)
                            {
                                rightresult = maxSpeed;
                            }
                            else if (rightresult < minSpeed)
                            {
                                rightresult = minSpeed;
                            }
                            TBleftDr->move(leftresult);
                            TBrightDr->move(rightresult);

                            pros::delay(20);
                        }
                        if (!exit)
                        {
                            TBleftDr->brake();
                            TBrightDr->brake();
                        }

                        exit = false;
                        timeoutTask.suspend();
                        movement.suspend();
                    });
}

void TankDR::setPose(float x, float y, float theta)
{
    while (movement.get_state() != pros::E_TASK_STATE_SUSPENDED)
    {
        pros::delay(20);
    }
    xPos = x;
    yPos = y;
    TBImu->set_heading(theta);
    update();
}

void TankDR::update()
{

    float currentHD = TBImu->get_heading();
    float difference = currentHD - HeadingDeg;

    HeadingDeg = currentHD;
    HeadingRad = HeadingDeg * PI / 180;

    float vert = verticalTW->getDifference();
    float hori = horizontalTW->getDifference();

    double Voffset = vertTWOffset * PI * difference / 360;
    vert = vert + Voffset;

    double ychange = vert * cos(HeadingRad) - hori * sin(HeadingRad);
    double xchange = vert * sin(HeadingRad) + hori * cos(HeadingRad);

    xPos = xPos + xchange;
    yPos = yPos + ychange;
}

void TankDR::turnToHeading(float theta, float timeout)
{
}

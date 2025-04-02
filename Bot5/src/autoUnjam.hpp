#include "globals.hpp"
#include "intake.cpp"

#ifndef AUTOUNJAM_CPP
#define AUTOUNJAM_CPP

class AutoUnjam {
    private:
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task *sorterTask;

};

#endif
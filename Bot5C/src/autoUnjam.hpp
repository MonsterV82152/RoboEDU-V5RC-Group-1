#ifndef AUTOUNJAM_CPP
#define AUTOUNJAM_CPP

#include "globals.hpp"
#include "intake.cpp"

class AutoUnjam {
    private:
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task *sorterTask;

};

#endif
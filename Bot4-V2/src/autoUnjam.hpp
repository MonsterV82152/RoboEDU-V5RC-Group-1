#include "globals.hpp"
#include "hook.cpp"
#include "intake.cpp"

#ifndef AUTOUNJAM_CPP
#define AUTOUNJAM_CPP

class AutoUnjam {
    protected:
        Hook *hook;
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task *sorterTask;
        int rings[3] = {0, 0, 0};

};

#endif
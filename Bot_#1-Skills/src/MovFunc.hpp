

#include "globals.hpp"
#include "main.h"

#ifndef MOVFUNC_HPP
#define MOVFUNC_HPP

class MasterControl {
    public:
        bool hook;
        bool colourcheck;
        int intakeSpeed;
        
        MasterControl(bool ahook, bool acolourcheck, int aintakeSpeed);
        void runIntake(int speed);
        void stopIntake();
        void runHook(int speed);
        void stopHook();
        void clampOn();
        void clampOff();
        
        
};

#endif
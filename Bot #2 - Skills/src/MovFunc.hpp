#include "globals.hpp"

// Main Movement Function File
#ifndef MOVFUNC_HPP
#define MOVFUNC_HPP

void ColourSorter(void* param) {
    while (true) {
        currentColour = colour.get_hue();
        if (colourSorterCountdown == 0 && colourSorterCooldown != 0) {
            hookOverwriteSpeed = -11;
            colourSorterCooldown--;
        } else if (colourSorterCooldown == 0) {
            if (hookOverwriteSpeed == -11) {
                hookOverwriteSpeed = 0;
            }
            colourSorterCooldown = 20;

            colourSorterCountdown = 8;
        }
        else if ((currentColour > 180 && currentColour < 240 && SelectedTeam) || ((currentColour < 30 || currentColour > 350) && !SelectedTeam) || colourSorterCountdown != 8) {
            colourSorterCountdown--;
        } else {
            colourSorterCountdown = 8;
        }
        if (((currentColour > 180 && currentColour < 240 && !SelectedTeam) || ((currentColour < 30 || currentColour > 350) && SelectedTeam)) && LadyBrownState == 1) {
            loadedRing = true;
        }
        pros::delay(10);
    }
    
}

void HookUnjam() {
    if (unjamCountdown == 0 && unjamCooldown != 0) {
        hookOverwriteSpeed = -127;
        intakeOverwriteSpeed = -127;
        unjamCooldown--;
    } else if (unjamCooldown == 10) {
        if (intakeOverwriteSpeed == -127) {
            intakeOverwriteSpeed = 127;
        }
        if (hookOverwriteSpeed == -127) {
            hookOverwriteSpeed = 0;
        }
        
    } else if (unjamCooldown == 0) {
        if (hookOverwriteSpeed == -127) {
            hookOverwriteSpeed = 0;
        }
        if (intakeOverwriteSpeed == 127 || intakeOverwriteSpeed == -127) {
            intakeOverwriteSpeed = 0;
        }
        unjamCooldown = 20;

        unjamCountdown = 10;
    }
    else if (hook.get_actual_velocity() < 10 && hookSpeed > 0 && !loadedRing) {
        unjamCountdown--;
    } else {
        unjamCountdown = 10;
    }
}

void mainMovement() {
    HookUnjam();
    if (intakeOverwriteSpeed == 0) {
        intake.move(intakeSpeed);
    } else {
        intake.move(intakeOverwriteSpeed);
    }
    if (hookOverwriteSpeed == 0) {
        hook.move(hookSpeed);
    } else {
        hook.move(hookOverwriteSpeed);
    }
    
    std::cout << hookSpeed << ", " << intakeSpeed;
}

void pnumatics() {
    if (BOOL_mogo_clamp) {
        mogo_clamp.set_value(true);
        mogoOverwriteCountdown = 20; 
        if (hookOverwriteSpeed == -50) {
            hookOverwriteSpeed = 0;
        }
    } else {
        mogo_clamp.set_value(false); 
        if (hookOverwriteSpeed == -50) {
            if (mogoOverwriteCountdown == 0) {
                hookOverwriteSpeed = 0; mogoOverwriteCountdown = 20;
            } else { 
                mogoOverwriteCountdown--;}}}
    if (BOOL_wing) {wing.set_value(true);} else {wing.set_value(false);}

}

void LadyBrown() {

    // Gets the Lady Brown position divided by the gear ratio and translate centidegrees to degrees
    LadyBrownPosition = lbRotation.get_position()/400;


    // Checks if the Lady Brown is at the requested angle and moves it if it isn't
    if (LadyBrownState == 0 && (LadyBrownPosition > 6 || LadyBrownPosition < -2)) {
        lbMech.move_velocity(-(LadyBrownPosition)*4);
        loadedRing = false;
        // ladyBrownCountdown--;
        // if (ladyBrownCountdown == 0) {
        //     lbRotation.set_position(-5);
        //     ladyBrownCountdown = 50;
        // }
    } else if (LadyBrownState == 1 && (LadyBrownPosition > lbfirst+2 || LadyBrownPosition < lbfirst-2)) {
        lbMech.move_velocity((lbfirst-(LadyBrownPosition))*4);
        
    } else if (LadyBrownState == 2 && (LadyBrownPosition > lbsecond+2 || LadyBrownPosition < lbsecond-2)) {
        lbMech.move_velocity((lbsecond-(LadyBrownPosition))*2);
        // Overwrites the speed to insure no jamming occurs
        hookOverwriteSpeed = -20;
    } else if (LadyBrownState == 3 && (LadyBrownPosition > lbthird+2 || LadyBrownPosition < lbthird-2)) {
        lbMech.move_velocity((lbthird-(LadyBrownPosition))*4);
        // Overwrites the speed to insure no jamming occurs
        hookOverwriteSpeed = -20;
    } else {
        // ladyBrownCountdown = 50;
        lbMech.brake();
        // Removes the overwrite
        if (hookOverwriteSpeed == -20) {
            hookOverwriteSpeed = 0;
        }
    }
    std::cout << LadyBrownPosition << std::endl;
}

void MotorInit() {
    // Sets gear cartriges to the correct ones
    hook.set_gearing(MOTOR_GEAR_BLUE);
    lbMech.set_gearing(MOTOR_GEAR_GREEN);
    right_dr.set_gearing(MOTOR_GEAR_BLUE);
    left_dr.set_gearing(MOTOR_GEAR_BLUE);
}

void SensorInit() {
    // Calibrate and reset sensors.
    lbRotation.set_position(0);
    colour.set_led_pwm(100);
    // lbRotation.set_reversed(true);
}

void mainWhileLoop(void* param) {
    while (true) {
        mainMovement();
        pnumatics();
        LadyBrown();
        pros::delay(20);
    }
}


#endif
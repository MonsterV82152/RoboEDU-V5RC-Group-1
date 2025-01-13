#include "globals.hpp"

// Main Movement Function File
#ifndef MOVFUNC_HPP
#define MOVFUNC_HPP

/*
The colourSorter is a multitask that runs throughout autonomous and driver that will change the 
hookOverwriteSpeed if detects that the bot has intaken a ring of the opposing team. It will
stop the hook and cause the ring to fly over the mobile goal due to momentum. This function will also
detect if we have loaded a ring into the LadyBrown and will prevent the autoUnjam from activating if 
we are loading the rings
*/

void ColourSorter(void* param) {
    pros::delay(1000);
    while (true) {
        if (BOOL_colourSorter) {
            int a = colour.get_hue();
        int dis = HookDistance.get_distance();
        if (colourSorterCooldown != 30) {
            if (colourSorterCooldown == 0) {
                if (hookOverwriteSpeed == -127 || hookOverwriteSpeed == -10) {
                    hookOverwriteSpeed = 0;
                    colourSorterCooldown = 30;
                }
            } else {
                colourSorterCooldown--;
            }
            
            
        } else if (ring[0] != 0) {
            if (dis < 50) {
                if (SelectedTeam && ring[0] == 2) {
                    colourSorterCooldown--;
                    if (LadyBrownState == 1) {
                    hookOverwriteSpeed = -127;
                    
                } else {
                    hookOverwriteSpeed = -10;
                }
                } else if (!SelectedTeam && ring[0] == 1) {
                    colourSorterCooldown--;
                    if (LadyBrownState == 1) {
                    hookOverwriteSpeed = -127;
                    
                } else {
                    hookOverwriteSpeed = -10;
                }
                }
                if (LadyBrownState == 1) {
                    loadedRing = true;
                }
                ring[0] = ring[1];
                ring[1] = 0;
            }
        }
        
        // std::cout << ring[0] << " " << ring[1] << " " << a << " " << HookDistance.get_distance() << std::endl;
        pros::delay(10);
        if (a < 20 || a > 340) {
            if (!detectingColour) {
                if (ring[0] == 0) {
                    ring[0] = 1;
                } else {
                    ring[1] = 1;
                }
            }
            detectingColour = true;
        } else if (a > 100 && a < 240) {
            if (!detectingColour) {
                if (ring[0] == 0) {
                    ring[0] = 2;    
                } else {
                    ring[1] = 2;
                }
            }
            detectingColour = true;
        } else {
            detectingColour = false;
            if (actualHookSpeed < 0 || actualIntakeSpeed < 0) {
                ring[0] = 0;
                ring[1] = 0;
            }
        }
        } else {
            ring[0] = 0;
            ring[1] = 0;
            colourSorterCooldown = 30;
        }
        
        pros::delay(10);
    }
}

/*
The HookUnjam is a function that gets called in the mainMovement to detect whether the hook has been
jammed and will reverse if does. This will prevent jamming that might lose us points. This also helps
the driver as they do not need to manually reverse the hook anymore
*/
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
    else if (hook.get_actual_velocity() < 10 && hookSpeed > 0 && !loadedRing && LadyBrownState == 0) {
        unjamCountdown--;
    } else {
        unjamCountdown = 10;
    }
}

/*
This is the core of our driver control and moving all the motors. We control the drivetrain in driverControl
period here and the intake/hook system.
*/
void mainMovement() {
    // Tank Drive
    if (driverControl) {
        left_controller_position_Y = master.get_analog(ANALOG_LEFT_Y);
        right_controller_position_X = master.get_analog(ANALOG_RIGHT_X);

        chassis.arcade(left_controller_position_Y,right_controller_position_X,false,0.5);

    }

    if (master.get_digital_new_press(button_RIGHT)) {
        BOOL_colourSorter = !BOOL_colourSorter;
    }
    
    if (master.get_digital_new_press(button_R2)) {
        if (hookSpeed == 0) { // Runs the hook if hook is stationary
            hookSpeed = hookDefaultSpeed;
        } else {
            hookSpeed = 0; // Stops the hook
        }
        if (intakeSpeed == 0) { // Runs the hook if hook is stationary
            intakeSpeed = intakeDefaultSpeed;
        }
    }
    if (master.get_digital_new_press(button_R1)) {
        if (intakeSpeed == 0) { // Runs the intake if the intake is stationary
            intakeSpeed = intakeDefaultSpeed;
        } else { // Stops the intake if hook is not running
            intakeSpeed = 0;
        }
    }
    HookUnjam();
    if ((master.get_digital(button_L1) && user == 0)||(master.get_digital(button_B) && user == 1)) {
        actualIntakeSpeed = -127;
        actualHookSpeed = -127;
        hook.move(-127);
        intake.move(-127);
    } else {
        if (intakeOverwriteSpeed == 0) {
            intake.move(intakeSpeed);
            actualIntakeSpeed = intakeSpeed;
        } else {
            intake.move(intakeOverwriteSpeed);
            actualIntakeSpeed = intakeOverwriteSpeed;
        }
        if (hookOverwriteSpeed == 0) {
            hook.move(hookSpeed);
            actualHookSpeed = hookSpeed;
        } else {
            hook.move(hookOverwriteSpeed);
            actualHookSpeed = hookOverwriteSpeed;
        }
    }
    
}

/*
We will activate all the pnumatics here with Driver Control and Autonomous periods. This includes the 
mobile goal clamp and the wings
*/
void pnumatics() {
    if (master.get_digital_new_press(button_X)) {BOOL_mogo_clamp = !BOOL_mogo_clamp; 
    if (!BOOL_mogo_clamp) {
        hookOverwriteSpeed = -50;
    }
    }
    if (master.get_digital_new_press(button_Y)) {if (master.get_digital(button_L2)) {BOOL_left_wing = !BOOL_left_wing;} else {BOOL_right_wing = !BOOL_right_wing;}}

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
    if (BOOL_right_wing) {right_wing.set_value(true);} else {right_wing.set_value(false);}
    if (BOOL_left_wing) {left_wing.set_value(true);} else {left_wing.set_value(false);}

}


/*
We control the LadyBrown through this system and raises or lowers it in relation to the 
LadyBrownState variable. 

LadyBrownStates:

0 - Down
1 - Loading
2 - Preparing to score
3 - Scoring Stage
*/
void LadyBrown() {

    // Gets the Lady Brown position divided by the gear ratio and translate centidegrees to degrees
    LadyBrownPosition = lbRotation.get_position()/100;
    // Sets the stages of the Lady Brown based on controls
    if ((master.get_digital_new_press(button_DOWN) && user == 0)||(master.get_digital_new_press(button_L1) && user == 1)) {
        if (LadyBrownState == 0) {
            LadyBrownState = 1;
            lbMech.set_brake_mode(HOLD);
        } else {
            LadyBrownState = 0;
            lbMech.set_brake_mode(COAST);
        }
    }

    // if (master.get_digital(button_RIGHT)) {
    //     lbfirst = lbfirst-0.2;
    // }
    // if (master.get_digital(button_UP)) {
    //     lbfirst = lbfirst+0.2;
    // }

    // Sets position to scoring position
    if ((master.get_digital_new_press(button_B) && user == 0)||(master.get_digital_new_press(button_L2) && user == 1)) {
        if (LadyBrownState != 3) {
            LadyBrownState = 3;
            lbMech.set_brake_mode(HOLD);
        } else {
            LadyBrownState = 0;
            lbMech.set_brake_mode(COAST);
        }
    }
    
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
}



// Initializes all the Motors
void MotorInit() {
    // Sets gear cartriges to the correct ones
    hook.set_gearing(MOTOR_GEAR_BLUE);
    lbMech.set_gearing(MOTOR_GEAR_GREEN);
    right_dr.set_gearing(MOTOR_GEAR_BLUE);
    left_dr.set_gearing(MOTOR_GEAR_BLUE);
    hook.get_temperature();
}

// Initializes all the sensors
void SensorInit() {
    // Calibrate and reset sensors.
    lbRotation.set_position(0);

    colour.set_led_pwm(100);
    lbRotation.set_reversed(true);
    lbMech.set_reversed(true);
    master.clear();
}

void ControllerDisplay() {
    if (cycleCounter % 50 == 0) {
        master.print(0,0,"%d %d",ring[0], ring[1]);
    }
    else if (cycleCounter % 50 == 10) {
        if (BOOL_colourSorter) {
            master.print(1,0,"Sorter: On ");
        } else {
            master.print(1,0,"Sorter: Off");
        }    
    }
    else if (cycleCounter % 50 == 30) {
        
        if (!BOOL_mogo_clamp) {
            master.print(2,0,"Clamp: Off");
        } else {
            master.print(2,0,"Clamp: On ");
        }
    }
    
}

void BrainDisplay() {
    if ((driverControl || autonomousPeriod) && cycleCounter % 50 == 43 && AutonSelected) {
        pros::screen::set_pen(pros::Color::white);
        pros::screen::erase_rect(46+(144*1.5),68,452,212);
        hookTemp = hook.get_temperature();
        driveTemp = (left_dr.get_temperature(0)+right_dr.get_temperature(0))/2;
        pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 80, "Hook Temperature:");
        pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 100, "%d", hookTemp);
        pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 130, "DriveTrain Temperature:");
        pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 150, "%d", driveTemp);
    }
}

// Main Multitasked Loop to run everything.
void mainWhileLoop(void* param) {
    while (true) {
        mainMovement();
        pnumatics();
        LadyBrown();
        ControllerDisplay();
        // BrainDisplay();
        cycleCounter++;
        pros::delay(20);
    }
}


#endif
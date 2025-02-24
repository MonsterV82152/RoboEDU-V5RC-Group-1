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


void AutoRaise() {
    
    if (loadedRing) {
        loadedRing = false;
        pros::delay(200);
        if (!BOOL_AutoRaise) {
            if (LadyBrownState == 1) {
                BOOL_AutoRaise = true;
                autoUnjam = true;
                LadyBrownState = 2;
            } else if (LadyBrownState == 2 && user == 2) {
                BOOL_AutoRaise = true;
                autoUnjam = true;
                LadyBrownState = 4;
            }
        }

    } else {
        BOOL_AutoRaise = false;
    }
    
}

/**
 * ColourSorter
 *
 * To be run in a seperate task
 */
void ColourSorter(void *param)
{
    pros::delay(1000); // Delay to prevent any initialization issues
    while (true)
    {
        if (BOOL_colourSorter) // Checks if colourSorter should be activated
        {
            int a = colour.get_hue();               // Gets the colour of the colour sensor in the intake
            int dis = HookDistance.get_distance();  // Gets the distance of the distance sensor on the book
            if (colourSorterCooldown != 30)         // Checks if the cooldown is changed
            {
                if (colourSorterCooldown == 0)      // Stops the hook if the cooldown reaches 0
                {
                    if (hookOverwriteSpeed == -127 || hookOverwriteSpeed == -30)
                    {
                        hookOverwriteSpeed = 0;
                        colourSorterCooldown = 30;
                    }
                }
                else                                // Continues counting down if it is changed.
                {
                    colourSorterCooldown--;
                }
            }
            else if (ring[0] != 0)                  // Checks if there is a ring in the system
            {
                if (dis < 50)                       // Checks if the distance sensor detects anything
                {
                    if (SelectedTeam && ring[0] == 2) // Checks if the ring is a ring of the opponents' colour
                    {
                        pros::delay(45);
                        colourSorterCooldown--;
                        if (LadyBrownState == 1 || ring[1] != 0)    // Redirects the ring if LB is up in loading position.
                        {
                            hookOverwriteSpeed = -127;
                        }
                        else
                        {
                            hookOverwriteSpeed = -30;
                        }
                    }
                    else if (!SelectedTeam && ring[0] == 1)
                    {
                        pros::delay(45);
                        colourSorterCooldown--;
                        if (LadyBrownState == 1 || ring[1] != 0)
                        {
                            hookOverwriteSpeed = -127;
                        }
                        else
                        {
                            hookOverwriteSpeed = -30;
                        }
                    }
                    else
                    {
                        if (LadyBrownState == 1)    // Changes loadedRing state if LB is up
                        {
                            loadedRing = true;
                        }
                        pros::delay(300);
                    }

                    ring[0] = ring[1];              // Moves the order of the rings in the array
                    ring[1] = 0;
                }
            }
            if (a < 20 || a > 340)                  // Checks the colour sensor to see if any rings are intaken
            {
                if (!detectingColour)
                {
                    if (ring[0] == 0)
                    {
                        ring[0] = 1;
                    }
                    else
                    {
                        ring[1] = 1;
                    }
                }
                detectingColour = true;
            }
            else if (a > 140 && a < 230)
            {
                if (!detectingColour)
                {
                    if (ring[0] == 0)
                    {
                        ring[0] = 2;
                    }
                    else
                    {
                        ring[1] = 2;
                    }
                }
                detectingColour = true;
            }
            else
            {
                detectingColour = false;
                if (actualHookSpeed < 0 || actualIntakeSpeed < 0)
                {
                    ring[0] = 0;
                    ring[1] = 0;
                }
            }
        }
        else
        {
            ring[0] = 0;
            ring[1] = 0;
            colourSorterCooldown = 30;
        }
        // AutoRaise();
        if ((LadyBrownState == 1 || LadyBrownState == 2) && HookDistance.get_distance() < 50)
        {
        loadedRing = true;
        autoUnjam = false;
        }  
        pros::delay(5);
    }
}

void AllianceStakeAllign()
{
    if (master.get_digital_new_press(button_UP))
    {
        Aallignment = !Aallignment;
    }
    if (Aallignment)
    {
        chassis.arcade(alliancePID.update((allianceDistance - (distance + distance2) / 2)), (distance2 - distance) * 0.5, false, 0.5);
        if (abs(left_controller_position_Y) > 10 || abs(right_controller_position_X) > 10) {
            Aallignment = !Aallignment;
        }
    }
}



/*
The HookUnjam is a function that gets called in the mainMovement to detect whether the hook has been
jammed and will reverse if does. This will prevent jamming that might lose us points. This also helps
the driver as they do not need to manually reverse the hook anymore
*/
void HookUnjam()
{
    
    if (autoUnjam && !LBMoving) {
        if (unjamCountdown == 0 && unjamCooldown != 0)
        {
            hookOverwriteSpeed = -127;
            master.rumble("-");
            // intakeOverwriteSpeed = -127;
            unjamCooldown--;
        }
        else if (unjamCooldown == 0)
        {
            if (hookOverwriteSpeed == -127)
            {
                hookOverwriteSpeed = 0;
            }
            // if (intakeOverwriteSpeed == 127 || intakeOverwriteSpeed == -127) {
            //     intakeOverwriteSpeed = 0;
            // }
            unjamCooldown = 20;

            unjamCountdown = 10;
        }
        else if (hook.get_actual_velocity() < 10 && actualHookSpeed > 0)
        {
            unjamCountdown--;
        }
        else
        {
            if (hookOverwriteSpeed == -127)
            {
                hookOverwriteSpeed = 0;
            }
            unjamCountdown = 10;
        }
    } else {
        unjamCooldown = 20;
        unjamCountdown = 10;
    }
    
}

/*
This is the core of our driver control and moving all the motors. We control the drivetrain in driverControl
period here and the intake/hook system.
*/
void mainMovement()
{
    // Tank Drive
    distance2 = BackDistance2.get_distance();
    distance = BackDistance.get_distance();
    heading = abs((int)(chassis.getPose().theta) % 360);
    if (driverControl)
    {
        if (master.get_digital(button_RIGHT)) {
            chassis.arcade(-70,0,false,0.5);
        } else {
            left_controller_position_Y = master.get_analog(ANALOG_LEFT_Y);
            right_controller_position_X = master.get_analog(ANALOG_RIGHT_X);

            chassis.arcade(left_controller_position_Y, right_controller_position_X, false, 0.54); 
        }
            
        
    }

    if (master.get_digital_new_press(ColourSorterToggle))
    {
        BOOL_colourSorter = !BOOL_colourSorter;
    }

    if (master.get_digital_new_press(HookToggle))
    {
        Aallignment = false;
        if (hookSpeed == 0)
        { // Runs the hook if hook is stationary
            hookSpeed = hookDefaultSpeed;
            Aallignment = false;
        }
        else
        {
            hookSpeed = 0; // Stops the hook
        }
        if (intakeSpeed == 0)
        { // Runs the hook if hook is stationary
            intakeSpeed = intakeDefaultSpeed;
        }
    }
    if (master.get_digital_new_press(IntakeToggle))
    {
        if (intakeSpeed == 0)
        { // Runs the intake if the intake is stationary
            intakeSpeed = intakeDefaultSpeed;
        }
        else
        { // Stops the intake if hook is not running
            intakeSpeed = 0;
        }
    }
    HookUnjam();
    AllianceStakeAllign();
    if (master.get_digital(ReverseRingSystem) && user == 0)
    {
        actualIntakeSpeed = -127;
        actualHookSpeed = -127;
        hook.move(-127);
        intake.move(-127);
    }
    else
    {
        if (intakeOverwriteSpeed == 0)
        {
            intake.move(intakeSpeed);
            actualIntakeSpeed = intakeSpeed;
        }
        else
        {
            intake.move(intakeOverwriteSpeed);
            actualIntakeSpeed = intakeOverwriteSpeed;
        }
        if (hookOverwriteSpeed != 0)
        {
            hook.move(hookOverwriteSpeed);
            actualHookSpeed = hookOverwriteSpeed;
        }
        else if (LadyBrownState == 3 || LBMoving)
        {
            hook.brake();
            actualHookSpeed = 0;
        }
        else
        {
            hook.move(hookSpeed);
            actualHookSpeed = hookSpeed;
        }
    }
}

/*
We will activate all the pnumatics here with Driver Control and Autonomous periods. This includes the
mobile goal clamp and the wings
*/
void pnumatics()
{
    if (master.get_digital_new_press(MogoClampToggle))
    {
        BOOL_mogo_clamp = !BOOL_mogo_clamp;
        if (!BOOL_mogo_clamp)
        {
            hookOverwriteSpeed = -50;
        } else {
            master.rumble("-");
        }
    }
    if (master.get_digital_new_press(WingToggle) && LadyBrownState != 3 && !LBMoving)
    {
        if (master.get_digital(button_L2))
        {
            BOOL_left_wing = !BOOL_left_wing;
        }
        else
        {
            BOOL_alliance_piston = !BOOL_alliance_piston;
        }
    }

    if (BOOL_mogo_clamp)
    {
        mogo_clamp.set_value(true);
        mogoOverwriteCountdown = 20;
        if (hookOverwriteSpeed == -50)
        {
            hookOverwriteSpeed = 0;
        }
    }
    else
    {
        mogo_clamp.set_value(false);
        if (hookOverwriteSpeed == -50)
        {
            if (mogoOverwriteCountdown == 0)
            {
                hookOverwriteSpeed = 0;
                mogoOverwriteCountdown = 20;
            }
            else
            {
                mogoOverwriteCountdown--;
            }
        }
    }
    if (BOOL_alliance_piston)
    {
        alliance_piston.set_value(true);
    }
    else
    {
        alliance_piston.set_value(false);
    }
    if (BOOL_left_wing)
    {
        left_wing.set_value(true);
    }
    else
    {
        left_wing.set_value(false);
    }
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
void LadyBrown()
{

    // Gets the Lady Brown position divided by the gear ratio and translate centidegrees to degrees
    LadyBrownPosition = lbRotation.get_position() / 300;
    // Sets the stages of the Lady Brown based on controls
    if (master2.get_digital(button_DOWN))
    {
        LBLoadingAngle = LBLoadingAngle - 0.5;
    }
    else if (master2.get_digital(button_UP))
    {
        LBLoadingAngle = LBLoadingAngle + 0.5;
    }
    if (master.get_digital_new_press(LadyBrownLoading))
    {
        if (LadyBrownState == 0)
        {
            LadyBrownState = 1;
            LadyBrownSetPointState = true;
            lbMech.set_brake_mode(HOLD);
        }
        else if (LadyBrownState == 1)
        {
            LadyBrownState = 2;
            LadyBrownSetPointState = true;
            lbMech.set_brake_mode(HOLD);
        }
        else
        {
            LadyBrownState = 0;
            LadyBrownSetPointState = true;
            lbMech.set_brake_mode(COAST);
        }
    }

    // Sets position to scoring position
    if (master.get_digital_new_press(LadyBrownScoring))
    {
        BOOL_alliance_piston = false;
        if (LadyBrownState != 3)
        {
            LadyBrownState = 3;
            LadyBrownSetPointState = true;
            lbMech.set_brake_mode(HOLD);
        }
        else
        {
            LadyBrownSetPointState = true;
            LadyBrownState = 0;
            lbMech.set_brake_mode(COAST);
        }
    }

    if (master.get_digital(LadyBrownUp))
    {
        LadyBrownSetPointState = false;
        LBMoving = false;
        if (LadyBrownPosition < 300)
        {
            if (LadyBrownPosition < LBNoContactZone)
            {
                hookOverwriteSpeed = -20;
            }
            else
            {
                if (hookOverwriteSpeed == -20)
                {
                    hookOverwriteSpeed = 0;
                }
            }
            lbMech.move_velocity(127);
        }
        else
        {
            lbMech.move_velocity(-127);
        }
    }
    else if (master.get_digital(LadyBrownDown))
    {
        LBMoving = false;
        LadyBrownSetPointState = false;
        if (LadyBrownPosition > -2)
        {
            lbMech.move_velocity(-127);
        }
        else
        {
            lbMech.move_velocity(127);
        }
    }
    else if (!LadyBrownSetPointState)
    {
        lbMech.set_brake_mode(HOLD);
        lbMech.brake();
    }

    // Checks if the Lady Brown is at the requested angle and moves it if it isn't
    if (LadyBrownSetPointState)
    {
        if (LadyBrownState == 0 && (LadyBrownPosition > 1 || LadyBrownPosition < -1))
        {
            lbMech.move_velocity(-(LadyBrownPosition) * 4);
            loadedRing = false;
            LBMoving = true;
        }
        else if (LadyBrownState == 1 && (LadyBrownPosition > LBLoadingAngle + 1 || LadyBrownPosition < LBLoadingAngle - 1))
        {
            lbMech.move_velocity((LBLoadingAngle - (LadyBrownPosition)) * 4);
        }
        // else if (LadyBrownState == 2 && (LadyBrownPosition > LBLoadingAngle2 + 1 || LadyBrownPosition < LBLoadingAngle2 - 1))
        else if (LadyBrownState == 2 && (LadyBrownPosition < LBLoadingAngle2 - 0.5 || LadyBrownPosition > LBLoadingAngle2 + 0.5))
        {
            lbMech.move_velocity((LBLoadingAngle2 - (LadyBrownPosition)) * 8);

            // Overwrites the speed to insure no jamming occurs
            if (LadyBrownPosition > 0 && LadyBrownPosition < LBNoContactZone)
            {
                hookOverwriteSpeed = -20;
            }
            else if (hookOverwriteSpeed == -20)
            {
                hookOverwriteSpeed = 0;
            }
            LBMoving = true;
        }
        else if (LadyBrownState == 3 && (LadyBrownPosition > LBScoringAngle + 2 || LadyBrownPosition < LBScoringAngle - 2))
        {
            loadedRing = false;
            lbMech.move_velocity((LBScoringAngle - (LadyBrownPosition)) * 4);
            // Overwrites the speed to insure no jamming occurs
            if (LadyBrownPosition > 0 && LadyBrownPosition < LBNoContactZone)
            {
                hookOverwriteSpeed = -20;
            }
            else if (hookOverwriteSpeed == -20)
            {
                hookOverwriteSpeed = 0;
            }
            LBMoving = true;
        }
        else if (LadyBrownState == 4 && (LadyBrownPosition > LBMacroAngle + 2 || LadyBrownPosition < LBMacroAngle - 2))
        {
            loadedRing = false;
            lbMech.move_velocity((LBMacroAngle - (LadyBrownPosition)) * 4);
            // Overwrites the speed to insure no jamming occurs
            if (LadyBrownPosition > 0 && LadyBrownPosition < LBNoContactZone)
            {
                hookOverwriteSpeed = -20;
            }
            else if (hookOverwriteSpeed == -20)
            {
                hookOverwriteSpeed = 0;
            }
            LBMoving = true;
        }
        else
        {
            lbMech.brake();
            // Removes the overwrite
            if (hookOverwriteSpeed == -20)
            {
                hookOverwriteSpeed = 0;
            }
            LBMoving = false;
        }
    }
    else
    {
        if (LadyBrownPosition > 0 && LadyBrownPosition < LBNoContactZone)
        {
            hookOverwriteSpeed = -20;
        }
        else if (hookOverwriteSpeed == -20)
        {
            hookOverwriteSpeed = 0;
        }
    }
}

// Initializes all the Motors
void MotorInit()
{
    // Sets gear cartriges to the correct ones
    hook.set_gearing(MOTOR_GEAR_BLUE);
    lbMech.set_gearing(MOTOR_GEAR_GREEN);
    right_dr.set_gearing(MOTOR_GEAR_BLUE);
    left_dr.set_gearing(MOTOR_GEAR_BLUE);
    hook.get_temperature();
}

// Initializes all the sensors
void SensorInit()
{
    // Calibrate and reset sensors.
    lbRotation.set_position(0);
    colour.set_led_pwm(100);
    // lbRotation.set_reversed(true);
    lbMech.set_reversed(true);
    master.clear();
}

void ControllerDisplay()
{
    if (cycleCounter % 50 == 0)
    {
        master.print(0, 0, "%d %d", ring[0], ring[1]);
    }
    else if (cycleCounter % 50 == 10)
    {
        if (BOOL_colourSorter)
        {
            master.print(1, 0, "Sorter: On ");
        }
        else
        {
            master.print(1, 0, "Sorter: Off");
        }
    }
    else if (cycleCounter % 50 == 30)
    {

        if (!BOOL_mogo_clamp)
        {
            master.print(2, 0, "Clamp: Off");
        }
        else
        {
            master.print(2, 0, "Clamp: On ");
        }
    }
}

void BrainDisplay()
{
    if ((driverControl || autonomousPeriod) && cycleCounter % 50 == 43 && AutonSelected)
    {
        pros::screen::set_pen(pros::Color::white);
        pros::screen::erase_rect(46 + (144 * 1.5), 68, 452, 212);
        hookTemp = hook.get_temperature();
        driveTemp = (left_dr.get_temperature(0) + right_dr.get_temperature(0)) / 2;
        pros::screen::print(TEXT_MEDIUM_CENTER, 28 + (144 * 1.5) + 20, 80, "Hook Temperature:");
        pros::screen::print(TEXT_MEDIUM_CENTER, 28 + (144 * 1.5) + 20, 100, "%d", hookTemp);
        pros::screen::print(TEXT_MEDIUM_CENTER, 28 + (144 * 1.5) + 20, 130, "DriveTrain Temperature:");
        pros::screen::print(TEXT_MEDIUM_CENTER, 28 + (144 * 1.5) + 20, 150, "%d", driveTemp);
    }
}

// Main Multitasked Loop to run everything.
void mainWhileLoop(void *param)
{
    while (true)
    {
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
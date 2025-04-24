#include "globals.hpp"
#include "intake.cpp"
#include "ladyBrown.cpp"

#ifndef COLOURSORTER_CPP
#define COLOURSORTER_CPP

class HookTasks {
    private:
        Intake *intake;
        LadyBrown *ladyBrown;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task sorterTask;
        bool shouldSort;
        bool shouldUnjam;
        int rings[3] = {0, 0, 0};
        int delayTime;
        int reverseCountdown;
        std::string nextCommand = "none";


        static constexpr int BLUE_HUE_MIN = 180;
        static constexpr int BLUE_HUE_MAX = 230;
        static constexpr int RED_HUE_MIN = 350;
        static constexpr int RED_HUE_MAX = 20;

        void multiThread() {
            double lastLoad = 0;
            while (true) {
                int hue = colourSensor->get_hue();
                if (hue > BLUE_HUE_MIN && hue < BLUE_HUE_MAX) {
                    ringPos = "blueColourSensor";
                    if (LBState == "loading" && team && shouldSort) {
                        lastLoad = ladyBrown->getSetPoint();
                        ladyBrown->setSetPoint(0);
                    }
                } else if ((hue > RED_HUE_MIN || hue < RED_HUE_MAX)) {
                    ringPos = "redColourSensor";
                    if (LBState == "loading" && !team && shouldSort) {
                        lastLoad = ladyBrown->getSetPoint();
                        ladyBrown->setSetPoint(0);
                    }
                }

                if (distanceSensor->get_distance() < 40) {
                    if (nextCommand == "hold" || (nextCommand == "holdAlliance" && ((ringPos == "redColourSensor"&& team) || (ringPos == "blueColourSensor" && !team)))) {
                        intake->setSpeed(0);
                        nextCommand = "none";
                    } else if (ringPos == "blueColourSensor") {
                        ringPos = "blueTop";
                        if (team && shouldSort) {
                            // pros::delay(delayTime);
                            intake->setOverwriteSpeed(-570, reverseCountdown);
                            ringPos = "none";
                            if (lastLoad != 0) {
                                ladyBrown->setSetPoint(lastLoad);
                                lastLoad = 0;
                            }
                        }
                    } else if (ringPos == "redColourSensor") {
                        ringPos = "redTop";
                        if (!team && shouldSort) {
                            // pros::delay(delayTime);
                            intake->setOverwriteSpeed(-570, reverseCountdown);
                            ringPos = "none";
                            if (lastLoad != 0) {
                                ladyBrown->setSetPoint(lastLoad);
                                lastLoad = 0;
                            }
                        }
                    } else {
                        ringPos = "Top";
                    }
                }

                if (!hookAtFullSpeed && intake->atTargetSpeed()) {
                    hookAtFullSpeed = true;
                }

                if ((intake->getTargetSpeed() > 50 && intake->getSpeed() < 10)) {
                    if (hookAtFullSpeed) {
                        if (LBState == "loading" && (ringPos == "blueTop" || ringPos == "redTop" || ringPos == "Top")) {intake->setOverwriteSpeed(0);}
                        else if (shouldUnjam) intake->setOverwriteSpeed(-590, 200);
                    } else {
                        pros::delay(500);
                        if ((intake->getTargetSpeed() > 50 && intake->getSpeed() < 10)) {
                            if (LBState == "loading" && (ringPos == "blueTop" || ringPos == "redTop" || ringPos == "Top")) {intake->setOverwriteSpeed(0);}
                            else if (shouldUnjam) intake->setOverwriteSpeed(-590, 200);
                        }
                    }
                }
                

            
                pros::delay(10); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
        HookTasks(Intake *intake, LadyBrown *ladyBrown, pros::Optical *colourSensor, pros::Distance *distanceSensor, int delay)
            : intake(intake), ladyBrown(ladyBrown), colourSensor(colourSensor), distanceSensor(distanceSensor), sorterTask([&](){}), shouldSort(false), shouldUnjam(true), delayTime(delay), reverseCountdown(100) {}

        void setDelay(int delay) {
            this->delayTime = delay;
        }

        void init() {
            colourSensor->set_led_pwm(100);
            sorterTask = pros::Task([&] { multiThread();}, 5, 8192, "colour");
        }

        void setSorting(bool state) {
            shouldSort = state;
        }

        void setUnjam(bool state) {
            shouldUnjam = state;
        }
        void holdNextRing(bool team) {
            if (team) {
                nextCommand = "holdAlliance";
            } else {
                nextCommand = "hold";
            }
            intake->setSpeed(400);
        }

        void holdNextRing() {
            intake->setSpeed(400);
            nextCommand = "hold";
        }



        bool isRunning() {
            return sorterTask.get_state() == pros::E_TASK_STATE_RUNNING;
        }
        bool isSorting() {
            return shouldSort;
        }
};

#endif
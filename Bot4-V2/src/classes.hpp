#include "ladyBrown.cpp"
#include "intake.cpp"
#include "hook.cpp"
#include "piston.cpp"
#include "colourSorter.cpp"
#include "mogoClamp.cpp"
#include "controls.cpp"

#ifndef CLASSES_HPP
#define CLASSES_HPP

inline Intake intake(&Manipulator::intakeMotor);
inline Hook hook(&Manipulator::hookMotor);
inline ColourSorter colourSorter(&hook, &intake, &Manipulator::colourSensor, &Manipulator::hookDistanceSensor, 5);
inline Piston mogoClampP(&Pneumatics::mogoClampPiston);
inline MogoClamp mogoClamp(&mogoClampP, &DriveTrain::backDistanceR, &DriveTrain::backDistanceL, &hook);
inline Piston leftWing(&Pneumatics::leftWingPiston);
inline LadyBrown ladyBrown(&LadyBrownConfigs::motor, &LadyBrownConfigs::rotationSensor, &LadyBrownConfigs::PID, &hook);
inline Controls controls(&intake, &hook, &ladyBrown, &colourSorter, &mogoClamp, &master);

#endif
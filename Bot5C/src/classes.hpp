#include "ladyBrown.cpp"
#include "intake.cpp"
#include "piston.cpp"
#include "colourSorter.cpp"
#include "controls.cpp"
#include "mogoClamp.cpp"

#ifndef CLASSES_HPP
#define CLASSES_HPP

inline Intake intake(&Manipulator::intakeMotor);
inline ColourSorter colourSorter(&intake, &Manipulator::colourSensor, 20);
inline Piston mogoClampP(&Pneumatics::mogoClampPiston);
inline MogoClamp mogoClamp(&mogoClampP, &intake);
inline Piston doinker(&Pneumatics::doinkerPiston);
inline Piston PTO(&Pneumatics::PTOPiston);
inline Piston tierThree(&Pneumatics::ladyBrownPiston);
inline LadyBrown ladyBrown(&LadyBrownConfigs::motor, &LadyBrownConfigs::potentiometer, &LadyBrownConfigs::PID, &intake, &colourSorter);
inline Controls controls(&intake, &ladyBrown, &colourSorter, &mogoClamp, &doinker, &master);

#endif
#ifndef CLASSES_HPP
#define CLASSES_HPP

#include "ladyBrown.cpp"
#include "intake.cpp"
#include "piston.cpp"
#include "hookTasks.cpp"
#include "controls.cpp"
#include "mogoClamp.cpp"

inline Intake intake(&Manipulator::intakeMotor);
inline HookTasks hookTasks(&intake, &Manipulator::colourSensor, &Manipulator::dist, 110);
inline Piston mogoClampP(&Pneumatics::mogoClampPiston);
inline MogoClamp mogoClamp(&mogoClampP, &intake);
inline Piston doinker(&Pneumatics::doinkerPiston);
inline Piston PTO(&Pneumatics::PTOPiston);
inline Piston tierThree(&Pneumatics::ladyBrownPiston);
inline LadyBrown ladyBrown(&LadyBrownConfigs::motor, &LadyBrownConfigs::potentiometer, &LadyBrownConfigs::PID, &intake, &hookTasks);
inline Controls controls(&intake, &ladyBrown, &hookTasks, &mogoClamp, &doinker, &tierThree, &master);

#endif
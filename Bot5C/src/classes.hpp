#include "ladyBrown.cpp"
#include "intake.cpp"
#include "piston.cpp"
#include "hookTasks.cpp"
#include "controls.cpp"
#include "mogoClamp.cpp"
#include "sensor_loc.cpp"

#ifndef CLASSES_HPP
#define CLASSES_HPP

inline Intake intake(&Manipulator::intakeMotor);
inline Piston mogoClampP(&Pneumatics::mogoClampPiston);
inline MogoClamp mogoClamp(&mogoClampP, &intake);
inline Piston doinker(&Pneumatics::doinkerPiston);
inline LadyBrown ladyBrown(&LadyBrownConfigs::motor, &LadyBrownConfigs::potentiometer, &LadyBrownConfigs::PID, &intake);
inline HookTasks hookTasks(&intake, &ladyBrown, &Manipulator::colourSensor, &Manipulator::dist, 0);
inline Controls controls(&intake, &ladyBrown, &hookTasks, &mogoClamp, &doinker, &master, &slave);

#endif
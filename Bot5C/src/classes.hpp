#include "ladyBrown.cpp"
#include "intake.cpp"
#include "piston.cpp"
#include "colourSorter.cpp"
#include "controls.cpp"
#include "mogoClamp.cpp"
#include "sensor_loc.hpp"

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
inline Controls controls(&intake, &ladyBrown, &colourSorter, &mogoClamp, &doinker, &tierThree, &master);
SensorLocalizer sensorLoc({
    {"front", {0, 6}},
    {"back", {0, -6}},
    {"left", {-6, 0}},
    {"right", {6, 0}}
  }, &chassis);
  
  std::map<std::string, pros::Distance*> sensors = {
    {"front", &DriveTrain::frontDS},
    {"back", &DriveTrain::backDS},
    {"left", &DriveTrain::leftDS},
    {"right", &DriveTrain::rightDS}
  };

#endif
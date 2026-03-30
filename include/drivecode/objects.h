#ifndef OBJECTS_H
#define OBJECTS_H

#include "main.h"

//define all drivetrain objects here

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::OdomSensors sensors;

extern lemlib::Chassis chassis;

extern pros::Controller controller;

#endif
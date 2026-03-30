#include "main.h"
#include "drivecode/objects.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motors({1,2,3});
pros::MotorGroup right_motors({4,5,6});

lemlib::Drivetrain drivetrain(
    &left_motors,
    &right_motors,
    0, 
    0, 
    0, 
    0 
);

lemlib::ControllerSettings angular_controller(
    0, //kp
    0, //kI
    0, //kD
    0, //antiwindup
    0, //small error range (in)
    0, //small error range timeout (milliseconds)
    0, //large error range (in)
    0, //large error range timeout (milliseconds)
    0 //slew
);

lemlib::ControllerSettings lateral_controller(
    0, //kp
    0, //kI
    0, //kD
    0, //antiwindup
    0, //small error range (in)
    0, //small error range timeout (milliseconds)
    0, //large error range (in)
    0, //large error range timeout (milliseconds)
    0 //slew
);

lemlib::OdomSensors sensors(
    nullptr, //vert. tracking wheel 1
    nullptr, //vert. tracking wheel 2
    nullptr, //horiz. tracking wheel 1
    nullptr, //horiz. tracking wheel 2
    nullptr //inertial sensor
);

lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);
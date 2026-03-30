#ifndef PISTONS_H
#define PISTONS_H

#include "main.h"
#include "pros/adi.hpp"

extern pros::adi::DigitalOut wing;
extern pros::adi::DigitalOut trapdoor;
extern pros::adi::DigitalOut matchloader;

void update_wing();
void update_trapdoor();
void update_matchloader();

#endif
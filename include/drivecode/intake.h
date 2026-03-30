#ifndef INTAKE_H
#define INTAKE_H

#include "main.h"

extern pros::Motor intake_motor;

void update_intakemotor();
void change_intake_state();

#endif
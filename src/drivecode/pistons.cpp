#include "main.h"
#include "drivecode/pistons.h"
#include "drivecode/objects.h"
#include "pros/misc.h"

std::int8_t wing_state = 0;
std::int8_t trapdoor_state = 0;
std::int8_t matchloader_state = 0;

pros::adi::DigitalOut wing({0},wing_state);
pros::adi::DigitalOut trapdoor({0},trapdoor_state);
pros::adi::DigitalOut matchloader({0},matchloader_state);

bool wing_pressed = false;
bool trapdoor_pressed = false;
bool matchloader_pressed = false;

void update_wing() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
        if (!wing_pressed) {
            wing_pressed = true;
            if (wing_state == 0) {
                wing.set_value(1);
            } else {
                wing.set_value(0);
            }
    } else {
        wing_pressed = false;
    }
}}

void update_trapdoor() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        if (!trapdoor_pressed) {
            trapdoor_pressed = true;
            if (trapdoor_state == 0) {
                trapdoor.set_value(1);
            } else {
                trapdoor.set_value(0);
            }
    } else {
        trapdoor_pressed = false;
    }
}}

void update_matchloader() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        if (!matchloader_pressed) {
            matchloader_pressed = true;
            if (matchloader_state == 0) {
                matchloader.set_value(1);
            } else {
                matchloader.set_value(0);
            }
    } else {
        matchloader_pressed = false;
    }
}}
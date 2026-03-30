#include "drivecode/intake.h"
#include "drivecode/objects.h"


pros::Motor intake_motor(0);

int intake_state = 0;
bool intake_pressed = false;

void update_intakemotor() {
    switch (intake_state) {
        case 1:
            intake_motor.move_voltage(12000);
            break;
        case -1:
            intake_motor.move_voltage(-12000);
            break;
        case 0:
            intake_motor.move_voltage(0);
            break;
    }
    pros::delay(10);
}

void change_intake_state() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        if (!intake_pressed) {

            intake_pressed = true;

            if (intake_state == 0 || intake_state == -1) {
                intake_state = 1;
            } else {
                intake_state = 0;
            }
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        if (!intake_pressed) {

            intake_pressed = true;

            if (intake_state == 0 || intake_state == 1) {
                intake_state = -1;
            } else {
                intake_state = 0;
            }

        }
    } else {
        intake_pressed = false;
    }
}
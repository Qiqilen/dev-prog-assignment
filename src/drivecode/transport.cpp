#include "main.h"
#include "pros/misc.h"
#include "transport.h"
#include "objects.h"

pros::Motor transport_motor(0);

int transport_state = 0;
bool transport_pressed = false;


void update_transport_state() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        if (!transport_pressed) {

            transport_pressed = true;

            if (transport_state == 0 || transport_state == -1) {
                transport_state = 1;
                transport_motor.move_velocity(12000);
            } else {
                transport_state = 0;
                transport_motor.move_velocity(0);
            }
        }
    } else {
        transport_pressed = false;
    }
}

void update_other_transport_state() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        if (!transport_pressed) {

            transport_pressed = true;

            if (transport_state == 0 || transport_state == 1) {
                transport_state = -1;
                transport_motor.move_velocity(-12000);
            } else {
                transport_state = 0;
                transport_motor.move_velocity(0);
            }
        }
    } else {
        transport_pressed = false;
    }
}
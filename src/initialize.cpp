#include "main.h"
#include "variables.h"
// Motors & Sensors
ADIAnalogIn sensor (1); // potentiometer port declaration
Motor left_f(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor left_b(19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor right_f(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor right_b(20, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor pivot(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor intake(4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor puncher(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor lift(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
// Math constants
const float PI = 3.14159265358979323846;


void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 4549E!");
	pros::c::adi_port_get_config(1); // potentiometer code?
	pros::c::adi_port_set_config(1, pros::E_ADI_ANALOG_IN); // potentiometer code?
}

void disabled() {}

void competition_initialize() {}

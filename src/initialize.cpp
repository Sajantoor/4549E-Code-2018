#include "main.h"
#include "variables.h"
ADIAnalogIn sensor (1); // potentiometer port declaration
Motor left_f(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor left_b(19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor right_f(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor right_b(20, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor pivot(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor intake(4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor puncher(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor lift(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
const float PI = 3.14159265358979323846;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "How dare you sir,I'll let you know that I, a V5 Brain have my rights and deserves better than this tyranny!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 4549E!");

	pros::lcd::register_btn1_cb(on_center_button);

	pros::c::adi_port_get_config(1); // potentiometer code?
	pros::c::adi_port_set_config(1, pros::E_ADI_ANALOG_IN); // potentiometer code?
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

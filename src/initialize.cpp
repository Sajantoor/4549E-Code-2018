#include "main.h"
#include "variables.h"
pros::ADIAnalogIn sensor (1); // potentiometer port declaration
pros::Motor left_mtr(19);
pros::Motor leftfront_mtr(8);
pros::Motor right_mtr(20);
pros::Motor rightfront_mtr(5);
pros::Motor pivot_mtr(7);
pros::Motor intake_mtr(4);
pros::Motor puncher_mtr(3);
pros::Motor lift_mtr(2);

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

#include "main.h"
#include "variables.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

 void opcontrol() {
 	while (true) {
    left_f = master.get_analog(ANALOG_LEFT_Y);
    left_b = master.get_analog(ANALOG_LEFT_Y);
    right_f = master.get_analog(ANALOG_RIGHT_Y);
    right_b = master.get_analog(ANALOG_RIGHT_Y);

    if (master.get_digital(DIGITAL_R1)) {
   			pivot = 127;
   		} else if (master.get_digital(DIGITAL_R2)) {
   			pivot = -127;
   		} else {
   		  pivot = 0;
   		}

     if (master.get_digital(DIGITAL_L1)) {
        intake.move(-127);
        delay(20);
     }  else if (master.get_digital(DIGITAL_L2)) {
        intake.move(127);
        delay(20);
     }

      if (master.get_digital_new_press(DIGITAL_A)) {
        shoot();
        delay(20);
      }

      if (master.get_digital_new_press(DIGITAL_X)) {
        liftFunc(up);
        delay(20);
      }

      if (master.get_digital(DIGITAL_UP)) {
        autonomous();
      }

      // reset motors to 0 position when button is not pressed
      intake.move(0);
      // sensor stuff
      sensorReading();

      pros::delay(20);
 	  }
 }

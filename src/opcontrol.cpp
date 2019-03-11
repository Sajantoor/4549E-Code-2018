#include "main.h"
#include "variables.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

 void opcontrol() {
 	while (true) {
  		drive((master.get_analog(ANALOG_LEFT_Y)), (master.get_analog(ANALOG_RIGHT_Y)));

   		if (master.get_digital(DIGITAL_R1)) {
   			pivot.move(120);
   		}

      if (master.get_digital(DIGITAL_R2)) {
   		  pivot.move(-120);
   		}

     if (master.get_digital(DIGITAL_L1)) {
        intake.move(-127);
     }

      if (master.get_digital(DIGITAL_L2)) {
        intake.move(127);
     }

      if (master.get_digital(DIGITAL_A)) {
        shoot();
      }

      if (master.get_digital_new_press(DIGITAL_X)) {
        liftFunc(true);
      }

      if (master.get_digital_new_press(DIGITAL_B)) {
        liftFunc(false);
      }

      if (master.get_digital(DIGITAL_UP)) {
        autonomous();
      }

      // reset motors to 0 position when button is not pressed
      intake.move(0);
      pivot.move(0);

      // sensor stuff
      sensorReading();

      pros::delay(20);
 	  }
 }

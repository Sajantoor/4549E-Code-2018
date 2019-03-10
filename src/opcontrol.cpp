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
     pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
  		    (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
  		    (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);


     		printf("Sensor Reading: %d\n", sensor.get_value());
     	pros::lcd::print(1, "Sensor Reading %d\n", sensor.get_value());
     	pros::lcd::print(2,"Red Front : 0 < 400" );
    	pros::lcd::print(3,"Red Back : 500 < 900" );
    	pros::lcd::print(4,"Blue Front : 1000 < 1400" );
     	pros::lcd::print(5,"Blue Back : 1500 < 1900" );
      pros::lcd::print(6,"SKILLS: 2000 < 2400");

     	std::cout << "Sensor Reading:" << sensor.get_value();

      pros::delay(20);
 	  }
 }

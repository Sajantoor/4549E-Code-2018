#include "main.h"
#include "variables.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

 void opcontrol() {
 	while (true) {
 		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
 		    (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
 		    (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
 		int left = master.get_analog(ANALOG_LEFT_Y);
 		int right = (master.get_analog(ANALOG_RIGHT_Y) * -1);
 		int pivot;
   	int intake;
   	int punch;
    int lift;

 		if (master.get_digital(DIGITAL_R1) == 1) {
 			pivot = 120;
 		} else if (master.get_digital(DIGITAL_R2) == 1) {
 			pivot = -120;
 		} else {
 		   pivot = 0;
 		}


     if (master.get_digital(DIGITAL_L1) == 1) {
       intake = -127;
     } else if (master.get_digital(DIGITAL_L2) == 1) {
        intake = 127;
     } else {
       intake = 0;
     }


      if (master.get_digital(DIGITAL_A) == 1) {
         punch = -127;
      } else {
        punch = 0;
      }

      if (master.get_digital(DIGITAL_X) == 1) {
        lift = -127;
      } else if (master.get_digital(DIGITAL_B) == 1) {
        lift = 127;
      } else {
        lift = 0;
      }

     left_mtr = left;
     leftfront_mtr = left;
     right_mtr = right;
     rightfront_mtr = right;
     pivot_mtr = pivot;
     intake_mtr = intake;
     puncher_mtr = punch;
     lift_mtr = lift;
     pros::delay(20);


     		printf("Sensor Reading: %d\n", sensor.get_value());
     	pros::lcd::print(1, "Sensor Reading %d\n", sensor.get_value());
     	pros::lcd::print(2,"Red Front : 0 < 400" );
    	pros::lcd::print(3,"Red Back : 500 < 900" );
    	pros::lcd::print(4,"Blue Front : 1000 < 1400" );
     	pros::lcd::print(5,"Blue Back : 1500 < 1900" );
      pros::lcd::print(6,"SKILLS: 2000 < 2400");

     	std::cout << "Sensor Reading:" << sensor.get_value();
 	  }
 }

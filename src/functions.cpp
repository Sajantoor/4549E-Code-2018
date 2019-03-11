#include "main.h"
#include "variables.h"

void drive(int leftVelocity, int rightVelocity) {
  left_f.move(leftVelocity);
  left_b.move(leftVelocity);
  right_f.move(rightVelocity);
  right_b.move(rightVelocity);
}

void shoot() {
  puncher.move(127);
  delay(3000);
  puncher.move(0);
  delay(20);
}

void liftFunc(bool up) {
  if (up) {
    lift.move(127);
    delay(1000);
    lift.move(0);
    delay(20);
  } else {
    lift.move(-127);
    delay(1000);
    lift.move(0);
    delay(20);
  }
}

void sensorReading() {
  pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
  (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
  (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

   printf("Sensor Reading: %d\n", sensor.get_value());
   pros::lcd::print(1, "Sensor Reading %d\n", sensor.get_value());

   std::cout << "Sensor Reading:" << sensor.get_value();
}

#include "main.h"
#include "variables.h"

void shoot() {
  puncher.move(127);
  delay(500);
  puncher.move(0);
  delay(20);
}

void liftFunc(bool value) {
  if (value) {
    lift.move(-127);
    delay(360);
    lift.move(0);
    value = false;
    delay(20);
    lift.move(127);
    delay(360);
    lift.move(0);
    value = true;
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

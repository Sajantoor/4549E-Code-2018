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

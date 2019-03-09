#include "main.h"
#include "variables.h"

void drive(int leftVelocity, int rightVelocity) {
  left_f.move(leftVelocity);
  left_b.move(leftVelocity);
  right_f.move(rightVelocity);
  right_b.move(rightVelocity);
}

#include "main.h"
#include "variables.h"

// resets encoder counts to 0
void reset() {
  left_f.tare_position();
  left_b.tare_position();
  right_f.tare_position();
  right_b.tare_position();
  pivot.tare_position();
  intake.tare_position();
  puncher.tare_position();
  lift.tare_position();
  delay(20);
}

void drivePID(float target, unsigned int timeout) {
  reset();
  unsigned int initialMillis = millis();
  float integral;
  float proportional;
  float derivative;
  float velocity;
  int integralLimit = 50;

  float Kp = 0.2; //0.2
  float Kd = 0.25;		//0.27
  float Ki = 0; //0
  int maxSpeed = 127;
  bool forward;

  if (target > 0) {
    bool forward = true;
  } else if (target < 0) {
    bool forward = false;
  }

  bool pidLock = true;
  float targetEncoder = (target / 4 * PI * 900); // 4 inches is wheel diameter // target but in encoder units
  float distance = targetEncoder; // Initialize distance as distance from target
  float lastDistance; // Last distance from target
  unsigned int netTimer = timeout + millis(); // intialize timer

//BUG: If PID doesn't stop add "PIDlock to this while statement" or get rid of "netTimer > millis" and use only PIDlock.
// NetTimer is only needed when handling correction and for precision in movement by slowly gettting towards the target.
// Correction is not implemented yet so netTimer isn't needed atm.
  while (netTimer > millis()) { // begin driving while this condition is met
    float encoderAverage = (left_f.get_position() + left_b.get_position() + right_f.get_position() + right_b.get_position() / 4);
    lastDistance = distance;
    distance = fabs(targetEncoder) - fabs(encoderAverage);

    if (pidLock) {
      netTimer = timeout + millis();
    }
    // i should decrease this value but +/- 15 should be fine for testing
    // if distance is inbetween 15 and -15 encoder units
    if (15 > distance && distance < -15)   {
      pidLock = false; // this might nto work
    }

    derivative = (distance - lastDistance)*Kd;
    proportional = distance*Kp;
    integral = (distance + integral)*Ki;

    if (integral > integralLimit){
      integral = integralLimit;
    }

    velocity = proportional + derivative + integral;

    if (velocity > 127) { // checks if velocity is above the max velocity accepted by the motors
      velocity = 127;
    }

    if (forward) {
      drive(velocity, velocity);
    } else {
      drive(-velocity, -velocity);
    }
    // might decrease this delay value if we want more precision.
    delay(20);
  }
}
// need to add correction and turning

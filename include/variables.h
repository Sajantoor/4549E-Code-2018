#ifndef MOTOR_H_
#define MOTOR_H_
#include "main.h"
// motors
extern Motor left_f;
extern Motor left_b;
extern Motor right_f;
extern Motor right_b;
extern Motor pivot;
extern Motor intake;
extern Motor puncher;
extern Motor lift;
extern ADIAnalogIn sensor;

// functions
extern void drive(int leftVelocity, int rightVelocity);
extern void liftFunc(bool up);
extern void shoot();
extern void autonomous();
extern void drivePID(float target, unsigned int timeout);
extern void sensorReading();

// Math constants
extern const float PI;


#endif

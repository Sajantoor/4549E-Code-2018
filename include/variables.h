#ifndef MOTOR_H_
#define MOTOR_H_
#include "main.h"

extern Motor left_f;
extern Motor left_b;
extern Motor right_f;
extern Motor right_b;
extern Motor pivot;
extern Motor intake;
extern Motor puncher;
extern Motor lift;
extern ADIAnalogIn sensor;
extern void drive(int leftVelocity, int rightVelocity);

#endif

## 4549E-Code
### Code for the Enver Creek Robotics Team: 4549E.


#### Table of Contents
- [Initialize](#intialize)
- [Opcontrol](#Opcontrol)
- [Autonomous](#Autonomous)
- [Functions](#Functions)
- [Drive](#Drive)
- [Global Variables & Functions](#global-variables--functions)



## Initialize
This file is used to declare global functions that are used between files, usually motors, sensors, and math constants such as PI.
**Example:**
```cpp
  Motor left_f(8, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
  Motor left_b(19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
  Motor right_f(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
  Motor right_b(20, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
  Motor pivot(7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
  Motor intake(4, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
  Motor puncher(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
  Motor lift(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
```
[initialize.cpp](../master/src/initialize.cpp)



## Opcontrol
This code is used for controlling our robot. Some functions are called here when a button is pressed on the controller.
**Example:**
```cpp
  if (master.get_digital(DIGITAL_A)) {
      shoot();
    }
```
[opcontrol.cpp](../master/src/opcontrol.cpp)



## Autonomous
The scripted autonomous, this is where we call functions to make our bot perform the autonomous.
There are **multiple** functions called in the autonomous function followed by delays *(if necessary)*.
**Example of what autonomous code looks like:**

```cpp
  void autonomous() {
    drivePID(2, 2000);
    delay(20);
    drivePID(-2, 2000);
  }
```
[autonomous.cpp](../master/src/autonomous.cpp)



## Functions
This is where most of the functions are stored. Functions are global and can be used in [opcontrol](#opcontrol) and [autonomous](#autonomous).
**Example of one of our functions:**

```cpp
    void shoot() {
      puncher.move(127);
      delay(3000);
      puncher.move(0);
      delay(20);
    }
```
[functions.cpp](../master/src/functions.cpp)



## Drive
This is a separate file with the drive functions as drive is the most important and most complicated part of our programming. This is where our PID for our drive is which is used in [autonomous](#autonomous).
**Some of the PID code:**

```cpp
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
    ...
    ..
    .
  }
```
[drive.cpp](../master/src/drive.cpp)



## Global Variables & Functions
Global Variables & Functions are declared in a file called **variables.h**. It's included in all of the other files as they need to access the variables declared there.
**Example:**

```cpp
  // Motors
  extern Motor left_f;
  extern Motor left_b;
  // Functions
  extern void shoot();
  extern void drivePID(float target, unsigned int timeout);
```
[variables.h](../master/include/variables.cpp)

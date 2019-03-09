#include "main.h"
#include "variables.h"

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
*/


void driveForward(int distance, int velocity) {
    left_b.move_relative(distance, velocity);
    left_f.move_relative(distance, velocity);
    right_b.move_relative(-distance, -velocity);
    right_f.move_relative(-distance, -velocity);
  }

  void driveback(int distance, int velocity) {
      left_b.move_relative(-distance, -velocity);
      left_f.move_relative(-distance, -velocity);
      right_b.move_relative(distance, velocity);
      right_f.move_relative(distance, velocity);
    }

    void pivot_up (int distance, int velocity) {
      pivot.move_relative(distance,velocity);
    }

    void pivot_down(int distance,int velocity) {
      pivot.move_relative(-distance,-velocity);
    }

    void turnright(int distance,int velocity) {
      left_b.move_relative(distance, velocity);
      left_f.move_relative(distance, velocity);
      right_b.move_relative(distance, velocity);
      right_f.move_relative(distance, velocity);
    }

    void turnleft(int distance,int velocity) {
     left_b.move_relative(-distance, -velocity);
     left_f.move_relative(-distance, -velocity);
     right_b.move_relative(-distance, -velocity);
     right_f.move_relative(-distance, -velocity);
    }


    void intakeFunc (int distance, int velocity) {
      intake.move_relative(distance,velocity);
    }

    void shoot(int distance,int velocity) {
      puncher .move_relative(-distance,-velocity);
    }

  void autonomous() {
    drivePID(2, 2000); 
  }

// void autonomous() {
//       if (sensor.get_value() < 400) {// red front
//         driveback(3000,120);//towards cap
//         pros::delay(1950);
//         intakeFunc(1200,200); //intake the ball
//         driveForward(2900,120); //back to starting tile
//         pros::delay(2250);
//         turnleft(690,120); //facing flags
//         pros::delay(1550);
//         driveback(500,100); // closer to flags
//         pros::delay(950);
//         shoot(1000,200); // shoot top flag
//         pros::delay(950);
//         driveback(1500,100); // closer to flags
//         intakeFunc(2000,200); // intake if ball is there
//         pros::delay(1450);
//         shoot(1000,200); // shoot middle flag
//         pivot_down(1000,200); // flipper down
//         pros::delay(1250);
//         turnleft(730,175); // facing flat cap
//         pros::delay(1150);
//         driveForward(230,80); // flipper under flat cap
//         pivot_up(1000,200); // flip cap
//         pros::delay(1450);
//         turnleft(940,125); // facing flags
//         pros::delay(1250);
//         driveForward(1500,190); // into flags
//          pros::delay(1500);
//         pivot_down(300,190); // flipper down
//         pros::delay(1000);
//         pivot_up(300, 190);
//         pros::delay(1000);
//       }
//
//       else if(500 < sensor.get_value() && sensor.get_value() < 900){//red back
//         driveback(3000,150);// towards angled cao
//         pros::delay(2000);
//         turnleft(520,120);//facing platform
//         pros::delay(1800);
//         // turnright(100,75);//slight left turn
//         // pros::delay(1800);
//         // pivot_down(400,180);//flipper down
//         // pros::delay(1800);
//         shoot(1200,200);//shoot middle top flag
//         pros::delay(1800);
//         turnleft(225,150);
//           pros::delay(1800);
//         // turnright(660,150);//facing angled cap
//         // pros::delay(1000);
//         driveForward(470,100);//
//         intakeFunc(2000,120);
//         pros::delay(2000);
//         pros::delay(1800);
//         shoot(1000,200);
//           pros::delay(1800);
//         // intake(1000,200);//intake ball
//         // pros::delay(1800);
//         // turnleft(760,150);//facing platform
//         // pros::delay(1800);
//         // driveForward(300,70);//upto platform
//         // pros::delay(1800);
//         // driveForward(1200,150);//onto platform
//         // pros::delay(1800);
//       }
//
//     else if(1000 < sensor.get_value() && sensor.get_value() < 1400) {//blue front
//        driveback(3000,100);//towards cap
//        pros::delay(1950);
//        intakeFunc(1200,200); //intake the ball
//        driveForward(2900,100); //back to starting tile
//        pros::delay(2250);
//        turnright(680,120); //facing flags
//        pros::delay(1550);
//        driveback(500,100); // closer to flags
//        pros::delay(950);
//        shoot(1000,200); // shoot top flag
//        pros::delay(950);
//        driveback(1500,100); // closer to flags
//        intakeFunc(2000,200); // intake if ball is there
//        pros::delay(1450);
//        shoot(1000,200); // shoot middle flag
//        pivot_down(1000,200); // flipper down
//        pros::delay(1250);
//        turnright(710,175); // facing flat cap
//        pros::delay(1350);
//        driveForward(200,80); // flipper under flat cap
//        pivot_up(1000,200); // flip cap
//        pros::delay(1450);
//        turnright(970,175); // facing flags
//        pros::delay(1450);
//        driveForward(1300,190); // into flags
//         pros::delay(1500);
//        pivot_down(1000,190); // flipper down
//        pros::delay(1000);
//        pivot_up(500, 190);
//        pros::delay(1000);
//   }
//
//   else if(1500 < sensor.get_value() && sensor.get_value() < 1900) {//blue back
//       driveback(3000,100);      //towards cap
//       pros::delay(1950);
//       intakeFunc(1200,200);    //intake the ball
//       pros::delay(2000);
//       driveForward(2400,150);
//       pros::delay(1500);
//       turnright(524,150);     //turn towards flag on the another corner
//       pros::delay(2000);
//       shoot(1000,200);     //shoot the middle flag
//       pros::delay(1500);
//       driveForward(800,200);
//       intakeFunc(1200,200);
//       pros::delay(1500);
//       shoot(1000,200);
//       pros::delay(1500);
//   }
//
//   else if (2000 < sensor.get_value() && sensor.get_value() < 2400){//skill
//       driveForward(1350,175);//drive into corner
//       pros::delay(1000);
//       turnleft(760,190);//90 facing cap
//       pros::delay(750);
//       pivot_down(1000,150);//flipper down
//       driveForward(2500,150);//drive into cap
//       pros::delay(1800);
//       pivot_up(1000,175);//flip cap                                           cap 1
//       pros::delay(750);
//       driveback(2000,150);// back to starting square
//       pros::delay(1500);
//       turnleft(750,175);//facing upwards
//       pros::delay(750);
//       driveback(700,70);// lineup
//       pros::delay(1200);
//       driveForward(1800,175);// drive upwards
//       pros::delay(1200);
//       turnright(775,190);//
//       pros::delay(1200);
//       driveForward(2100,200);// into cap
//       pivot_down(750,180);//                                                  cap 2
//       pros::delay(1800);
//       driveback(3100,175);//drive back
//       pivot_up(750,200);//
//       pros::delay(2000);
//       driveback(400,70);// lineup
//       pros::delay(2000);
//       driveForward(750,125);// out from wall
//       pros::delay(1300);
//       turnleft(750,190);//turn facing upwards
//       pros::delay(1000);
//       driveForward(3100,175);//drive parrallel with cap
//       pros::delay(1500);
//       turnright(790,150);//turn towards cap
//       pros::delay(1000);
//       driveback(1250,60);// lineup
//       pros::delay(2000);
//       driveForward(3600,200);//drive into cap
//       pivot_down(750,150);//                                                  cap 3
//       pros::delay(1800);
//       driveback(1800,175);//back to flat cap
//       pivot_up(750,150);//
//       pros::delay(1400);
//       pivot_down(1000,200);// flipper down
//       pros::delay(1200);
//       turnleft(745,190);// facing cap
//       pros::delay(1200);
//       driveForward(1000,90);// drive into cap
//       pros::delay(1200);
//       pivot_up(1000,200);//                                                   cap 4
//       pros::delay(1200);
//       driveback(1200,175);// near platform
//       pros::delay(1000);
//       turnleft(770,190);// facing left side of field
//       pros::delay(1000);
//       driveForward(1450,175);// upto wall
//       pros::delay(1400);
//       driveForward(700,70);// lineup
//       pros::delay(1400);
//       driveback(500,100);// realign with flag
//       pros::delay(1400);
//       turnright(775,190);// facing flag
//       pros::delay(1000);
//       driveForward(3200,150);//drive into flag            thunbs up                   flag
//       pros::delay(2000);
//       driveback(5200,175);//back to platform
//       pros::delay(2500);
//       turnright(775,190);//face platform
//       pros::delay(1400);
//       driveback(750,70);//lineup
//       pros::delay(1400);
//       driveForward(5500,125);// onto platform                              center platform
//       pros::delay(1400);
//   }
//
//   else if(2450 < sensor.get_value() && sensor.get_value() < 2600) {//blue front simple
//       driveForward(2870,200);//flag
//       pros::delay(2200);
//       driveback(4820,200);//back towards platform
//       pros::delay(2900);
//       turnleft(760,200);//turn towards
//       pros::delay(1800);
//       driveback(320,80);//lineup with platform
//       pros::delay(2000);
//       driveForward(3820,200);//drive onto blue platform
//       pros::delay(1500);
//     }
//
//     else if (2650 < sensor.get_value() && sensor.get_value() < 2800) {//blue front flipper
//
//         driveForward(3020,175);// hit flag                                           flag
//         pros::delay(1700);
//         driveback(3135,175);// back to starting
//         pros::delay(1700);
//         turnleft(800,190);//face cap
//         pros::delay(900);
//         driveForward(1820,175);// upto cap
//         pros::delay(1200);
//         turnright(310,175);//adjust flipper
//         pros::delay(900);
//         pivot_down(1120,175);// flipper down
//         pros::delay(1000);
//         turnleft(310,200);// knock ball away from under cap                 cap
//         pros::delay(1000);
//         driveback(520,175);// lineup with flat cap
//         //pivot_up(1750,175);//flipper up
//         pros::delay(800);
//         turnright(760,190);//face flat cap
//         //pivot_down(1000,175);//flipper down
//         pros::delay(1100);
//         driveForward(1220,100);// drive into cap
//         pros::delay(1500);
//         driveback(105,175);//back a little from cap
//         pros::delay(1100);
//         pivot_up(1100,200);//flip cap
//         pros::delay(500);
//         turnleft(385,190);// 45
//         pros::delay(1100);
//         driveForward(2120,175);// close to middle flag
//         pros::delay(2400);
//         turnright(370,190);//realign to angled flag
//         pros::delay(1100);
//         driveForward(1220,175);// into middle flag
//         pros::delay(1400);
//     }
//
//     else if(2850 < sensor.get_value() && sensor.get_value() < 3000){// red front simple
//         driveForward(2870,200);//flag
//         pros::delay(2200);
//         driveback(4820,200);//back towards platform
//         pros::delay(2900);
//         turnright(760,200);//turn towards
//         pros::delay(1800);
//         driveback(320,80);//lineup with platform
//         pros::delay(2000);
//         driveForward(3820,200);//drive onto blue platform
//         pros::delay(1500);
//     }
// }

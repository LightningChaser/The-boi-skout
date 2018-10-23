/* ---------------------------------------------------------
* Author: Group 1
* Class: EGR10703
* Date: 10/23/2018
* Instructor: Professor Stevens
* Program: midterm competition 
* Description: Includes structures to control motors and
*              defines constants
* --------------------------------------------------------- */

#define START_END 2000
#define FIND_GOAL_1 60000
#define FIND_GOAL_2 120000

#define SPEED_HIGH 92          //fast motor speed
#define SPEED_MED 65            //medium motor speed
#define SPEED_REVERSE -100      //slow motor speed
#define SPEED_STOP 0            //motor speed 0

#define R_PWM 5           // motor pins for right motor
#define R_PIN1 9
#define R_PIN2 10
#define L_PWM 6           // motor pins for left motor
#define L_PIN1 7
#define L_PIN2 8

#define trigPinF 2        //front ultrasonic trigger
#define echoPinF 12       //front echo
#define trigPinR 3        //rear ultrasonic  
#define echoPinR 4        //rear echo

#define switchPin 30      //microswitch pin

#define TOP_IRPIN 0       //goal IR pin

unsigned long startTime, currentTime;
double durationF, durationR;

struct robotMotors{
  int leftPWM;
  int rightPWM;
};

struct robotSensors{
  double frontUltra;
  double rearUltra;
};

enum states{
  START,
  RANDOM,
  TO_WALL,
  FOLLOW,
  LEFT_90,
  RIGHT_90,
  REVERSE,
  FIRE,
};

struct Robot{
  struct robotMotors motors;
  struct robotSensors sensors;
  enum states state = START;
};

//function prototypes
void updateMotors(struct Robot *robot);
void updateSensors(struct Robot *robot);

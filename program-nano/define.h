
enum dir {FORWARD = 8, BACKWARD = 2, LEFT = 4, RIGHT = 6};
enum {BEGIN, STOP, TEST, BLUETOOTH};

/*----------------------------------------------------------------------------------------------*/
// Pin Mapping

// Change A,B pin numbers if motor rotate reverse direction
#define rightMotorA 6
#define rightMotorB 7
#define rightMotorPWM 9

// Change A,B pin numbers if motor rotate reverse direction
#define leftMotorA 10
#define leftMotorB 8
#define leftMotorPWM 11

#define BUTTON_1 12
#define BUTTON_2 4

#define LED_1 4
#define LED_2 13

#define BUZZER 2

int buttonStatus = 0;

/*----------------------------------------------------------------------------------------------*/
// Motor Control

int leftMotorDir, rightMotorDir;
int leftMotorDirOld, rightMotorDirOld;

#define MAX_MOTOR_SPEED 255
#define MIN_MOTOR_SPEED 100


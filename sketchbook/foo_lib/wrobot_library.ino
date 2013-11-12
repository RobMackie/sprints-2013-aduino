
//Arduino PWM Speed Control：
// Pin definitions for PWM speed control using 
// DFRobot Arduino Compatible Motor Shield (2A):
// Motor 1:
int 1_DIRECTION = 5;   //HIGH means spin forward
int 1_PWM = 4;         // a value from 0..255, 255 is full speed

// Motor 2:
int 2_DIRECTION = 6;   //HIGH means spin forward
int 2_PWM = 7;         // a value from 0..255, 255 is full speed

Analog input pin definitions:
// Read a value from 0..1023, 
// 1023 is max analog input
// Sensor 1: 
int 0_LIGHT_SENSOR = 0; 
int 1_LIGHT_SENSOR = 1; 
int 2_LIGHT_SENSOR = 2; 
int 3_LIGHT_SENSOR = 3; 
int 4_LIGHT_SENSOR = 4; 
int 5_LIGHT_SENSOR = 5; 

// Motor macros for convenience
#define FORWARD HIGH
#define REVERSE LOW

typedef struct motor_def_t_ {
	int dir;
    int speed;
} motor_def_t;

motor_def_t MOTOR_SPEC = {
  { 1_DIRECTION, 1_PWM },
  { 2_DIRECTION, 2_PWM }
};

int MAX_MOTOR_SPEC = sizeof(MOTOR_SPEC) / sizeof(motor_def_t);

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

int dir;
 
void setup_motor_sheild () 
{ 
    pinMode(MOTOR_SPEC[LEFT_MOTOR].dir, OUTPUT);   
    pinMode(MOTOR_SPEC[RIGHT_MOTOR].dir, OUTPUT); 
    analogWrite(MOTOR_SPEC[LEFT_MOTOR].speed, 0);
    analogWrite(MOTOR_SPEC[RIGHT_MOTOR].speed, 0);
} 

void set_motor (int motor_id, int direction, int speed)
{
  if (! (motor_id < MAX_MOTOR_SPEC)) {
    return;
  }
  digitalWrite(MOTOR_SPEC[motor_id].dir, direction);
  analogWrite(MOTOR_SPEC[motor_id].speed, speed);
}


 
void loop() 
{ 
  int motor_direction;
  int speed_input;
  int speed; 

  for (speed = 0; speed < 255; speed += 5) {
    set_motor(LEFT_MOTOR, FORWARD, 125);
    set_motor(RIGHT_MOTOR, FORWARD, 125);
  }
  for (speed = 255; speed > 0; speed -= 5) {
    set_motor(LEFT_MOTOR, FORWARD, 125);
    set_motor(RIGHT_MOTOR, FORWARD, 125);
  }
 
  delay(30); 
 
}


//Arduino PWM Speed Control：
// Pin definitions for PWM speed control using 
// DFRobot Arduino Compatible Motor Shield (2A):

#include "Motor.h"

Motor right_motor(5 /*dir*/, 4 /*pwm*/);
Motor left_motor(6 /*dir*/, 7 /*pwm*/);


void setup () 
{ 
  right_motor.setup();
  left_motor.setup();
} 

void loop () 
{ 
  int speed; 

  for (speed = 0; speed < 255; speed += 5) {
    left_motor.forward(speed);
    right_motor.forward(speed);
  }
  for (speed = 255; speed > 0; speed -= 5) {
    left_motor.forward(speed);
    right_motor.forward(speed);
  }
 
  delay(30); 
 
}

/*
 * This is the implementation file that goes with Motor.h
 * It gives control of a motor attached to DFRobotics Motor Shield for the
 * Arduino.  The constructor needs the pin numbers for the enable pin
 * that controls direction (HIGH/LOW) and for the pwm pin that controls 
 * speed. It should work for pretty much any pwm controlled motor even with
 * other controllers.
 * author - Rob Mackie
 * date   - 10/20/2013
 */

#ifndef __MOTOR__
#define __MOTOR__

#include "Arduino.h"

class Motor {
  public:
    Motor(int pin_direction, int pin_pwm);
    void setup(void);
    void forward(unsigned char speed);
    void reverse(unsigned char speed);
    void stop(void);
    
    static int const FORWARD = HIGH;
    static int const REVERSE = LOW;

  private:
    int direction_pin;
    int speed_pin;
};

#endif //__MOTOR__


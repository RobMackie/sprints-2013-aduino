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
#include "Motor.h"

Motor::Motor(int pin_direction, int pin_pwm)
{
    direction_pin = pin_direction;
    speed_pin = pin_pwm;
}

void Motor::setup(void)
{
  pinMode(direction_pin, OUTPUT);
  this->stop();
}

void Motor::forward(unsigned char speed)
{
    digitalWrite(direction_pin, FORWARD);
    analogWrite(speed_pin, speed);
}

void Motor::reverse(unsigned char speed)
{
	digitalWrite(direction_pin, REVERSE);
    analogWrite(speed_pin, speed);
}

void Motor::stop(void)
{
	digitalWrite(direction_pin, FORWARD);
    analogWrite(speed_pin, 0);
}



//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;  
int LIGHT_SENSOR = 0;

#define FORWARD HIGH
#define REVERSE LOW
#define DIR_LEFT(fwd) (fwd % 2 ? FORWARD : REVERSE)
#define DIR_RITE(fwd) (fwd % 2 ? FORWARD : REVERSE)

#define THRESH 350
 
int dir;
 
void setup() 
{ 
    pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT); 
    dir = 0;
} 
 
void loop() 
{ 
  int motor_direction;
  int speed_input;
  
  motor_direction = FORWARD;
  speed_input = analogRead(LIGHT_SENSOR);

  speed_input -= 511; // now we have -512 .. +511
  // deal with negative imbalance as a speed and a direction:
  if (speed_input < 0) {
	speed_input *= -1;
    motor_direction = REVERSE;
  }

  // deal with nearly balanced sensor readings 
  // (our sensors are wildly imbalanced)
  if (speed_input < 250) {
	speed_input = 0;
  }

  // we're now in a range from 300 .. 511 and a positive number or 0.
  // we need 50 or higher to move the motors and we want a range of almost 
  // equal, so this works if you look at the next calculation.

  // now to get a number that fits in the pwm range of 0..255.
  int motor_setting = speed_input / 2; // (300..511)/2 => (150..255)
  
  digitalWrite(M1,DIR_LEFT(motor_direction));   
  digitalWrite(M2, DIR_RITE(motor_direction));     
  analogWrite(E1, motor_setting);   //PWM Speed Control
  analogWrite(E2, motor_setting);   //PWM Speed Control
  
  delay(30); 
 
}

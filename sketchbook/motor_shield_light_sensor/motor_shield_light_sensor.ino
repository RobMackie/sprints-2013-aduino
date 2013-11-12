
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
  if (speed_input < 300)  {
    speed_input = 0; 
  }

  int motor_setting = speed_input / 4; 
  
  digitalWrite(M1,DIR_LEFT(motor_direction));   
  digitalWrite(M2, DIR_RITE(motor_direction));     
  analogWrite(E1, motor_setting);   //PWM Speed Control
  analogWrite(E2, motor_setting);   //PWM Speed Control
  
  delay(30); 
 
}

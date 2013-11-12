
//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;  

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
  int value;
  dir++;
  
  for(value = 0 ; value <= 255; value+=5) 
  { 
    digitalWrite(M1,DIR_LEFT(dir));   
    digitalWrite(M2, DIR_RITE(dir));     
    analogWrite(E1, value);   //PWM Speed Control
    analogWrite(E2, value);   //PWM Speed Control
    delay(30); 
  }  
  for(value = 255 ; value >= 0; value-=5) 
  { 
    digitalWrite(M1,DIR_LEFT(dir));   
    digitalWrite(M2, DIR_RITE(dir));     
    analogWrite(E1, value);   //PWM Speed Control
    analogWrite(E2, value);   //PWM Speed Control
    delay(30); 
  }  
}

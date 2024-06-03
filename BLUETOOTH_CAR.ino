#include <AFMotor.h>
  
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
  
int value;
int Speeed = 255;
  
void setup()
{
  Serial.begin(9600);  
}
void loop(){
  if(Serial.available() > 0){
    value = Serial.read();
      
    Stop(); 
      
          if (value == 'F'){
          forward();
          }
  
          if (value == 'B'){
          back();
          }
  
          if (value == 'L'){
          left();
          }
  
          if (value == 'R'){
          right();
          }
    
  }
}
           
  
            
  
  
  
void forward()
{
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  
}
  
void back()
{
  motor1.setSpeed(Speeed); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
}
  
void left()
{
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE);


  
}
  
void right()
{
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
}

void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  
}

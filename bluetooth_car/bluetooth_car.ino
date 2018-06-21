#include "motor_driver.h"

motor_drive motor1(50,51,52,53,2,3,100);

char blue;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{  


    if(Serial.available()>0)
    {
      blue=Serial.read();
    }
 
    motor1.command(blue);
 

}

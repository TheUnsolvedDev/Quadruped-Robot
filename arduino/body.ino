#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

char ch = "L";
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);

  pwm.begin();
  
  pwm.setPWMFreq(60);
  
  pwm.setPWM(0, 0, angleToPulse(160));
  pwm.setPWM(1, 0, angleToPulse(145));
  pwm.setPWM(2, 0, angleToPulse(155));
  pwm.setPWM(3, 0, angleToPulse(60) );
  
  pwm.setPWM(4, 0, angleToPulse(85) );
  pwm.setPWM(5, 0, angleToPulse(55) );
  pwm.setPWM(6, 0, angleToPulse(140) );
  pwm.setPWM(7, 0, angleToPulse(150));

  pwm.setPWM(8, 0, angleToPulse(90) );
  pwm.setPWM(9, 0, angleToPulse(145));
  pwm.setPWM(10,0, angleToPulse(160));
  pwm.setPWM(11,0, angleToPulse(60) );
  delay(2000);  
  }

void loop() {
  delay(100);
//  walk();
}

void rotation(char ch,int rotate)
{
  if(ch=="A"){      //if "A" then Anti-Clockwise else "C" i.e Clockwise
    rotate=-rotate;
  }
  
  pwm.setPWM(4, 0, angleToPulse(85+30));
  delay(100);
  pwm.setPWM(8, 0, angleToPulse(90-rotate));  
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85));
  delay(500);

  pwm.setPWM(5, 0, angleToPulse(55+40));
  delay(100);
  pwm.setPWM(9, 0, angleToPulse(145-rotate));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(500);

  pwm.setPWM(6, 0, angleToPulse(140+30));  
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(160-rotate));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));
  delay(500);
  
  pwm.setPWM(7, 0, angleToPulse(150-50));
  delay(100);
  pwm.setPWM(11, 0, angleToPulse(60-rotate));
  delay(100);
  pwm.setPWM(7, 0, angleToPulse(150));
  delay(500);

  pwm.setPWM(0, 0, angleToPulse(160));
  pwm.setPWM(1, 0, angleToPulse(145));
  pwm.setPWM(2, 0, angleToPulse(155));
  pwm.setPWM(3, 0, angleToPulse(60) );
  
  pwm.setPWM(4, 0, angleToPulse(85) );
  pwm.setPWM(5, 0, angleToPulse(55) );
  pwm.setPWM(6, 0, angleToPulse(140) );
  pwm.setPWM(7, 0, angleToPulse(150));

  pwm.setPWM(8, 0, angleToPulse(90) );
  pwm.setPWM(9, 0, angleToPulse(145));
  pwm.setPWM(10,0, angleToPulse(160));
  pwm.setPWM(11,0, angleToPulse(60) );
 
}

void walk(){
  
  // move leg
  pwm.setPWM(7, 0, angleToPulse(150-50));
  delay(100);
  pwm.setPWM(11, 0, angleToPulse(60-45));  
  delay(100);
  pwm.setPWM(7, 0, angleToPulse(150));
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85+40));
  delay(100);
  pwm.setPWM(0, 0, angleToPulse(160-30));
  pwm.setPWM(8, 0, angleToPulse(90-50));
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85));
  
  delay(100); 

  // push
  pwm.setPWM(0, 0, angleToPulse(160));
  pwm.setPWM(11, 0, angleToPulse(60));
  pwm.setPWM(9, 0, angleToPulse(145-55));
  pwm.setPWM(2, 0, angleToPulse(155-45));
  delay(100);
  pwm.setPWM(2, 0, angleToPulse(155));

  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140+40));
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(160+40));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));
  
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55+40));
  delay(100);
  pwm.setPWM(1, 0, angleToPulse(145-30));
  pwm.setPWM(9, 0, angleToPulse(145+5));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(100);
  // push  
  pwm.setPWM(1, 0, angleToPulse(145));
  pwm.setPWM(3, 0, angleToPulse(60+35)); 
  pwm.setPWM(10, 0, angleToPulse(150+10));
  pwm.setPWM(8, 0, angleToPulse(90));
  delay(100);
  pwm.setPWM(3, 0, angleToPulse(60));
  delay(100);  
}

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   return pulse;
}

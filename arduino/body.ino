#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

//  pwm.setPWM(0, 0, angleToPulse(120) );
//  pwm.setPWM(1, 0, angleToPulse(110) );
//  pwm.setPWM(2, 0, angleToPulse(110) );
//  pwm.setPWM(3, 0, angleToPulse(100) );
//  
//  pwm.setPWM(4, 0, angleToPulse(10) );
//  pwm.setPWM(6, 0, angleToPulse(10) );
//  pwm.setPWM(5, 0, angleToPulse(10) );
//  pwm.setPWM(7, 0, angleToPulse(180) );
//

  
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
  pwm.setPWM(7, 0, angleToPulse(100));
  delay(100);
  pwm.setPWM(11, 0, angleToPulse(15));  
  delay(100);
  pwm.setPWM(7, 0, angleToPulse(150));
  pwm.setPWM(11,0,angleToPulse(0));
  walk();
  rotation('C',30);    //clockwise_
  rotation('A',30);    //anti-clockwise_
//    rotation(30);
}


void walk(){

  // move leg  
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(115));
  delay(100);
  pwm.setPWM(0, 0, angleToPulse(130));
  pwm.setPWM(8, 0, angleToPulse(40));
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85));
  
  delay(100); //1000

  // push
  pwm.setPWM(0, 0, angleToPulse(160));
  pwm.setPWM(11, 0, angleToPulse(60));
  pwm.setPWM(9, 0, angleToPulse(90));
  pwm.setPWM(2, 0, angleToPulse(110));
  delay(100);
  pwm.setPWM(2, 0, angleToPulse(155));




  
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(180));
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(200));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));




  
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(95));
  delay(100);
  pwm.setPWM(1, 0, angleToPulse(115));
  pwm.setPWM(9, 0, angleToPulse(150));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(100);
  // push  
  pwm.setPWM(1, 0, angleToPulse(145));
  pwm.setPWM(3, 0, angleToPulse(95)); 
  pwm.setPWM(10, 0, angleToPulse(150));
  pwm.setPWM(8, 0, angleToPulse(90));
  delay(100);
  pwm.setPWM(3, 0, angleToPulse(60));
  delay(200); //1000
  
}

void rotation(char ch,int rotate)
{
  if(ch=='A'){      //if "A" then Anti-Clockwise else "C" i.e Clockwise
    rotate=-rotate;
  }

  
  pwm.setPWM(4, 0, angleToPulse(115));
  delay(100);
  pwm.setPWM(8, 0, angleToPulse(90-rotate));  
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85));
  delay(500);

  
  pwm.setPWM(5, 0, angleToPulse(95));
  delay(100);
  pwm.setPWM(9, 0, angleToPulse(145-rotate));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(500);

  
  pwm.setPWM(6, 0, angleToPulse(170));  
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(160-rotate));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));
  delay(500);

  
  pwm.setPWM(7, 0, angleToPulse(100));
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




  // move leg  
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(115));
  delay(100);
  pwm.setPWM(0, 0, angleToPulse(130));
  pwm.setPWM(8, 0, angleToPulse(40));
  delay(100);
  pwm.setPWM(4, 0, angleToPulse(85));
  
  delay(100); //1000

  // push
  pwm.setPWM(0, 0, angleToPulse(160));
  pwm.setPWM(11, 0, angleToPulse(60));
  pwm.setPWM(9, 0, angleToPulse(90));
  pwm.setPWM(2, 0, angleToPulse(110));
  delay(100);
  pwm.setPWM(2, 0, angleToPulse(155));







  
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(180));
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(200));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));







  
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(95));
  delay(100);
  pwm.setPWM(1, 0, angleToPulse(115));
  pwm.setPWM(9, 0, angleToPulse(150));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(100);
  // push  
  pwm.setPWM(1, 0, angleToPulse(145));
  pwm.setPWM(3, 0, angleToPulse(95)); 
  pwm.setPWM(10, 0, angleToPulse(150));
  pwm.setPWM(8, 0, angleToPulse(90));
  delay(100);
  pwm.setPWM(3, 0, angleToPulse(60));
  delay(200); //1000
  
}

void rotation(int rotate)
{
  //rotate leg 0 by angle (int)rotate
  pwm.setPWM(4, 0, angleToPulse(115));
  delay(500);
  pwm.setPWM(8, 0, angleToPulse(90-rotate));  
  delay(500);
  pwm.setPWM(4, 0, angleToPulse(85));
  delay(500);

  
  
  pwm.setPWM(5, 0, angleToPulse(95));
  delay(100);
  pwm.setPWM(9, 0, angleToPulse(145-rotate));
  delay(100);
  pwm.setPWM(5, 0, angleToPulse(55));
  delay(500);

  pwm.setPWM(6, 0, angleToPulse(170));  
  delay(100);
  pwm.setPWM(10, 0, angleToPulse(160-rotate));
  delay(100);
  pwm.setPWM(6, 0, angleToPulse(140));
  delay(500);

  
  
  
  pwm.setPWM(7, 0, angleToPulse(100));
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



//void walk(int cycle)



int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
//   Serial.print("Angle: ");Serial.print(ang);
//   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

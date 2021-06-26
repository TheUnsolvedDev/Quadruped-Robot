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
#define SERVOMIN 125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 575 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("16 channel Servo test!");

	pwm.begin();

	pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
}

void loop()
{
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
	pwm.setPWM(3, 0, angleToPulse(60));

	pwm.setPWM(4, 0, angleToPulse(85));
	pwm.setPWM(5, 0, angleToPulse(55));
	pwm.setPWM(6, 0, angleToPulse(60));
	pwm.setPWM(7, 0, angleToPulse(150));

	pwm.setPWM(8, 0, angleToPulse(90));
	pwm.setPWM(9, 0, angleToPulse(120));
	pwm.setPWM(10, 0, angleToPulse(180));
	pwm.setPWM(11, 0, angleToPulse(60));

	delay(2000);

	rotation(30);
}

void rotation(int rotate)
{
	//rotate leg 0 by angle (int)rotate
	pwm.setPWM(4, 0, angleToPulse(115));
	for (int angle = 90; angle >= 90 - rotate; angle -= 10)
	{
		pwm.setPWM(8, 0, angleToPulse(angle));
		delay(100);
	}
	pwm.setPWM(4, 0, angleToPulse(85));
	delay(1000);

	pwm.setPWM(5, 0, angleToPulse(95));
	for (int angle = 120; angle >= 120 - rotate; angle -= 10)
	{
		pwm.setPWM(9, 0, angleToPulse(angle));
		delay(100);
	}
	pwm.setPWM(5, 0, angleToPulse(60));
	delay(1000);

	pwm.setPWM(6, 0, angleToPulse(95));
	for (int angle = 180; angle >= 180 - rotate; angle -= 10)
	{
		pwm.setPWM(10, 0, angleToPulse(angle));
		delay(100);
	}
	pwm.setPWM(6, 0, angleToPulse(60));
	delay(1000);

	pwm.setPWM(7, 0, angleToPulse(110));
	for (int angle = 60; angle >= 60 - rotate; angle -= 10)
	{
		pwm.setPWM(11, 0, angleToPulse(angle));
		delay(100);
	}
	pwm.setPWM(7, 0, angleToPulse(150));
	delay(1000);
}

int angleToPulse(int ang)
{
	int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max
	Serial.print("Angle: ");
	Serial.print(ang);
	Serial.print(" pulse: ");
	Serial.println(pulse);
	return pulse;
}

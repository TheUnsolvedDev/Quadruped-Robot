#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Essential libraries

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void normal()
{
	display.clearDisplay();
	display.fillCircle(50, 15, 12, WHITE);
	display.fillCircle(82, 20, 7, WHITE);
	display.display();
}

void annoy()
{
	display.clearDisplay();
	display.drawFastHLine(40, 15, 20, WHITE);
	display.drawFastHLine(72, 20, 15, WHITE);
	display.display();
}

void angry_annoy()
{
	display.clearDisplay();
	display.fillCircle(42, 10, 20, WHITE);
	display.fillCircle(82, 10, 15, WHITE);
	display.fillRect(0, 0, 128, 15, BLACK);
	display.fillRect(0, 40, 128, 15, BLACK);
	display.display();
}

void sad()
{
	display.clearDisplay();
	display.fillCircle(42, 10, 17, WHITE);
	display.fillCircle(82, 10, 17, WHITE);
	display.fillTriangle(0, 0, 0, 35, 78, 0, BLACK);
	display.fillTriangle(50, 0, 128, 35, 128, 0, BLACK);
	display.display();
}

void happy()
{
	display.clearDisplay();
	display.fillCircle(42, 25, 15, WHITE);
	display.fillCircle(82, 25, 15, WHITE);
	display.fillCircle(42, 33, 20, BLACK);
	display.fillCircle(82, 33, 20, BLACK);
	display.display();
}

void angry()
{
	display.clearDisplay();
	display.fillCircle(42, 10, 18, WHITE);
	display.fillCircle(82, 10, 12, WHITE);
	display.fillTriangle(0, 0, 54, 26, 118, 0, BLACK);
	display.display();
}
void (*func_ptr[6])(void) = {normal, annoy, angry_annoy, sad, happy, angry};

void setup()
{
	Serial.begin(9600);
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;); // Don't proceed, loop forever
	}
}

void faces()
{
	while (true)
	{
		int num = rand() % 1000;
		display.display();
		delay(200);
		display.clearDisplay();
		for (int i = 0; i < 7; i++)
		{
			(*func_ptr[rand() % 6])();
			delay(num);
		}
		display.clearDisplay();
	}
}

void loop()
{
	faces();
}

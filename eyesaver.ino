// Import required libraries
#include <ArducamSSD1306.h> // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <Wire.h>           // For I2C comm, but needed for not getting compile error

/*
HardWare I2C pins
A4   SDA
A5   SCL
*/

// Pin definitions
#define OLED_RESET 16 // Pin 15 -RESET digital signal

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH 16

ArducamSSD1306 display(OLED_RESET); // FOR I2C

bool work = false;
const int WORK_MINS = 1;
const int BREAK_MINS = 1;
int sec = 0;
int min = 0;

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // SSD1306 Init
  display.begin(); // Switch OLED
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.println(3);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setCursor(50, 20);
  display.println(2);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setCursor(80, 20);
  display.println(1);
  display.display();
  delay(1000);
}

void loop()
{
  if (work == true)
  {

    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("Work");
    display.setCursor(0, 20);
    display.setTextSize(4.5);
    char timeString[5];
    int bbbb = sprintf(timeString, "%02d:%02d", min, sec);
    display.println(timeString);
    // display.setCursor(0, 40);
    // display.println(hr);
    display.display();
    if (sec == 0 && min == 0)
    {
      delay(1000);
      work = false;
      min = BREAK_MINS;
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(2);
      char message[10];
      int nothing = sprintf(message, "%02d:%02d", min, sec);
      display.println(message);
      display.setCursor(0, 20);
      display.setTextSize(4);
      display.println("Break");
      display.display();
      delay(3000);
    }
  }
  else
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("Break");
    display.setCursor(0, 20);
    display.setTextSize(4.5);
    char timeString[5];
    int bbbb = sprintf(timeString, "%02d:%02d", min, sec);
    display.println(timeString);
    display.display();
    if (sec == 0 && min == 0)
    {
      delay(1000);
      work = true;
      min = WORK_MINS;
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(2);
      char message[10];
      int nothing = sprintf(message, "%02d:%02d", min, sec);
      display.println(message);
      display.setCursor(0, 20);
      display.setTextSize(4);
      display.println("Work");
      display.display();
      delay(3000);
    }
  }
  if (sec == 0)
  {
    min -= 1;
    sec = 59;
  }
  else
  {
    sec -= 1;
  }
  // delay(950);
}

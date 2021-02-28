/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  // 1. Drawing a square line
//  display.drawRect(40, 20, 40, 40, WHITE);
  // 2. Drawing a filled square
//  display.fillRect(40, 20, 40, 40, WHITE);
  // 3. Drawing a circle
  display.drawCircle(64 ,32 ,15 ,WHITE);
  display.display();
}
void loop() {
  
}

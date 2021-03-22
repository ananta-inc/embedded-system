#include <Wire.h>
//#include <SPI.H>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
//#define DHTPIN 4
//#define DHTTYPE DHT11   // DHT 11
//#include <LiquidCrystal_I2C.h>
DHT dht(DHTPIN, DHTTYPE);
// set the LCD number of columns and rows
//int lcdColumns = 16;
//int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif
BluetoothSerial SerialBT;
void setup() {
  dht.begin();
  Serial.begin(115200);
  SerialBT.begin("JJS"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  lcd.begin(16,2);
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}
void loop() {
  lcd.clear();
  String message;
if (SerialBT.available()) {
    message = "";
    lcd.clear();
      while(SerialBT.available()){
        char incomingChar = SerialBT.read();
        message += String(incomingChar);
      }
  }
// Display Text
  lcd.setCursor(0,0);
  lcd.print(message);
  Serial.println(message);
  
  delay(3000);
  
  lcd.clear();
  lcd.clear();  
  
  //SENSOR
  float h = bmp.readHumidity();
  // Read temperature as Celsius (the default)
  float t = bmp.readTemperature();
SerialBT.print(F("Humidity: "));
  SerialBT.print(h);
  SerialBT.println(F("%"));
  SerialBT.print(F("Temp: "));
  SerialBT.print(t);
  SerialBT.println(F(" C"));
  delay(1000);
  
}

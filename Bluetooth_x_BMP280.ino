#include <Wire.h>
//#include <SPI.H>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

#include "BluetoothSerial.h"

Adafruit_BMP280 bmp;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  Serial.println(F("BMP280 test"));

  // inisialisasi alamat bmp280
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  delay(1000);
  if (SerialBT.available()){
    
  }

  //read temperature and humidity
  float t = bmp.readTemperature();
  float h = bmp.readPressure();
  SerialBT.print(F("Pressure: "));
  SerialBT.print(h);
  SerialBT.println(F("Pa"));
  SerialBT.print(F("Temp: "));
  SerialBT.print(t);
  SerialBT.println(F(" C"));
  delay(1000);
  
}

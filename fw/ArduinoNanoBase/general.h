#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <RF24.h>
#include <HX711.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_SleepyDog.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED32 1
//#define OLED64_09 1
//#define OLED64_13 1


#ifdef OLED32
  #define SCREEN_WIDTH 128 // OLED display width, in pixels
  #define SCREEN_HEIGHT 32 // OLED display height, in pixels
  #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#elif OLED64_09
  #define SCREEN_WIDTH 128 // OLED display width, in pixels
  #define SCREEN_HEIGHT 64 // OLED display height, in pixels
  #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#elif OLED64_13
  #define SCREEN_WIDTH 128 // OLED display width, in pixels
  #define SCREEN_HEIGHT 32 // OLED display height, in pixels
  #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#endif



// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };


#define MAIN_TIME   1000   //ms
int new_time, old_time;

#define SLEEP_DELAY 1     // debug
//#define SLEEP_DELAY 3     // debug
//#define SLEEP_DELAY 75    // 10min
//#define SLEEP_DELAY 150   // 20min
//#define SLEEP_DELAY 225   // 30min
//#define SLEEP_DELAY 450   // 60min

#define LED1  A1
#define LED2  A2
#define LED3  A3
#define SW1   6
#define SW2   9

// DS18B20
#define ONE_WIRE_BUS 2                 // Data wire is connected to GPIO2
OneWire oneWire(ONE_WIRE_BUS);         // Setup a oneWire instance to communicate with a OneWire device
DallasTemperature sensors(&oneWire);   // Pass our oneWire reference to Dallas Temperature sensor 

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 5;
const int LOADCELL_SCK_PIN = 4;
HX711 scale;

// NRF24L01
RF24 radio(7, 8); // (CE, CSN)
const byte address[6] = "1RF24"; // address / identifier
const int chipSelect = 10;

// LCD
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

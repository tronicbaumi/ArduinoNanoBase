
#include "general.h"


#define UART

#define SAVE_POWER
#define SCHEDULER

//char value0char[8] = "";
//char value1char[8] = "";
char value2char[8] = "";
char value3char[8] = "";
//char value4char[8] = "";
//char value5char[8] = "";

//String value0;
//String value1;
String value2;
String value3;
//String value4;
//String value5;

float tempDS18B20;
char tempDS18B20String[5];

float weight = 0;
float weightfactor = 0.085;
char weightString[12];
float weightoffset;

unsigned int count1=0;

void setup() 
{
 // delay(5000);
  Serial.begin(115200);
  Serial.println("\n\n\n\n\n");
  Serial.println("ArduinoNanoBase started....");
  Serial.println("===========================");

  Init_LED();
  Init_BTN();
  Init_LCD();

    lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("Spargewater");
    lcd.setCursor(0, 1);
    lcd.print("ChB 2025 (c)");

  Init_DS18B20();
  Init_LoadCell();

  old_time = millis();
  Serial.println("Main Loop");
}



void loop() 
{
  //Serial.print(new_time);Serial.print(";");Serial.println(old_time);
  new_time = millis();
  if ((new_time-old_time) >= MAIN_TIME)
  {
    old_time = new_time;
  
    weight = weightfactor*scale.get_units(10);
    //Serial.print("weight float");Serial.println(weight);
     if(!digitalRead(SW1))
     {
        weightoffset = weight;
        Serial.println("Calibrated.....");
     }

     weight = weight-weightoffset;

    value2 = String(weight,3);
    value2.toCharArray(value2char,8);
    #ifdef UART
      Serial.print("Gewicht: ");Serial.println(value2char);
    #endif


    sensors.requestTemperatures(); // Send the command to get temperatures
    tempDS18B20 = sensors.getTempCByIndex(0);
    if (tempDS18B20 != DEVICE_DISCONNECTED_C)
    {
      value3 = String(tempDS18B20);
      value3.toCharArray(value3char,8);
    #ifdef UART
      Serial.print("Temperature: ");Serial.println(value3char);
      
    #endif
        


    }
    else
    {
      #ifdef UART    
      Serial.println("Error: Could not read temperature data");
      #endif
      tempDS18B20 = -100;
    }
    lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("Liter..");
    lcd.print(weight);
    lcd.print(" l");
    lcd.setCursor(0, 1);
    lcd.print("Temp...");
    lcd.print(tempDS18B20);
    lcd.print(" ");
    lcd.write(0xDF);
    lcd.print("C");

    
  }
}


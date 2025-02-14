
#include "general.h"


#define UART

#define SAVE_POWER
#define SCHEDULER

char value0char[8] = "";
char value1char[8] = "";
char value2char[8] = "";
char value3char[8] = "";
char value4char[8] = "";
char value5char[8] = "";

String value0;
String value1;
String value2;
String value3;
String value4;
String value5;

float tempDS18B20;
char tempDS18B20String[5];

float weight = 0;
float weightfactor = 0.085;
char weightString[12];

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
  //Init_Display();
  Init_LCD();
  Init_DS18B20();
  Init_NRF24L01();
  Init_LoadCell();

  // while(1)
  // {
  //   display.clearDisplay();
  //   display.setCursor(0,0);             // Start at top-left corner
  //   display.println(F("Test..."));
  //   display.display();
  //   delay(2000);
  // }
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
  
    value0 = String(count1++,DEC);
    if(count1>=999) count1=0;
    
    value0.toCharArray(value0char,8);
    Serial.print("Counter: ");
    Serial.println(value0);

    lcd.setCursor(0, 0);
    lcd.print(value0);


    // value1 = String(float(1690/float(analogRead(1))),2);
    // value1.toCharArray(value1char,8);
    // #ifdef UART
    // Serial.print("Vbat: ");
    // Serial.println(value1char);
    // #endif

    weight = weightfactor*scale.get_units(10);
    //Serial.print("weight float");Serial.println(weight);
    value2 = String(weight,3);
    value2.toCharArray(value2char,8);
    #ifdef UART
      Serial.print("Stockgewicht: ");Serial.println(value2char);
    #endif

    sensors.requestTemperatures(); // Send the command to get temperatures
    tempDS18B20 = sensors.getTempCByIndex(0);
    if (tempDS18B20 != DEVICE_DISCONNECTED_C)
    {
      value3 = String(tempDS18B20);
      value3.toCharArray(value3char,8);
    #ifdef UART
      Serial.print("StockTemperature: ");Serial.println(value3char);
    #endif

    }
    else
    {
      #ifdef UART    
      Serial.println("Error: Could not read temperature data");
      #endif
    }

    char csvString[64] = "";
    strcat(csvString,value0char);
    strcat(csvString,";");
    strcat(csvString,value1char);
    strcat(csvString,";");
    strcat(csvString,value2char);
    strcat(csvString,";");
    strcat(csvString,value3char);
    strcat(csvString,";");

    #ifdef UART 
    Serial.println(csvString);
    #endif
    //Serial.println(sizeof(csvString));
    radio.write(&csvString, sizeof(csvString));
    #ifdef UART 
    Serial.println("Message sent.");
    #endif

    //delay(3000);
    // radio.powerDown();
    // scale.power_down();
    // for(int i=0;i<SLEEP_DELAY;i++)
    // {
    //   #ifdef UART 
    //   Serial.println("Going to sleep ...");

    //   #endif
      
    //   delay(10);
    //   int sleepMS = Watchdog.sleep(8000);

    //   #ifdef UART 
    //   Serial.print("I'm awake now! I slept for ");
    //   //Serial.print(sleepMS, DEC);
    //   Serial.println(" milliseconds.");
    //   #endif
      
    // }
    // #ifdef UART 
    // Serial.println();
    // #endif

    // radio.powerUp();
    // scale.power_up();
  }
}


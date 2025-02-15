void Init_DS18B20(void)
{
  Serial.print("Initializing DS18B20...");
  sensors.begin();
  Serial.println(" Done!");
}
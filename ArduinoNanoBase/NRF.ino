



void Init_NRF24L01(void)
{
  // initialize the transceiver on the SPI bus
  Serial.print("Initializing NRF24L01...");
  if (!radio.begin()) 
  {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }
  Serial.println(F("done."));
  
  radio.setPALevel(RF24_PA_MAX);  // RF24_PA_MAX is default.

  radio.openWritingPipe(address); // set the address
  radio.stopListening(); // set as transmitter

}
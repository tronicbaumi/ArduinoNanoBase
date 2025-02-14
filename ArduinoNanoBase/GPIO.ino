

void Init_LED(void)
{
  Serial.print("Initializing LEDs...");
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1,HIGH);
  delay(300);
  digitalWrite(LED1,LOW);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2,HIGH);
  delay(300);
  digitalWrite(LED2,LOW);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED3,HIGH);
  delay(300);
  digitalWrite(LED3,LOW);
  Serial.println("done!");
}

void Init_BTN(void)
{
  Serial.print("Initializing BTNs...");
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  Serial.println("done!");
}

//
//    if(!digitalRead(SW1)) Serial.println("SW1");
//    if(!digitalRead(SW2)) Serial.println("SW2");
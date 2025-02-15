void Init_LCD(void)
{
  Serial.print("Initialize LCD...");
  lcd.begin();
  lcd.backlight();
  Serial.println("done.");
}

	// // Turn on the blacklight and print a message.
	// lcd.backlight();
	// lcd.print("Hello, world!");
  // lcd.setCursor(0, 1);
  // lcd.print("Baumi");
  // //lcd.autoscroll();
  // //lcd.noAutoscroll();
  // delay(4000);
  // lcd.clear();
  // //lcd.noBacklight();
  // //lcd.backlight();
  // lcd.setCursor(0, 0);
  // lcd.print("Hello, world!2");
  // lcd.setCursor(0, 1);
  // lcd.print("Baumi 2");
  // lcd.write(65);
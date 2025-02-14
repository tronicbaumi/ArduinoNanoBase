void Init_Display(void)
{
  Serial.print("Initializing Display..."); 
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
  //  for(;;); // Don't proceed, loop forever
  }
  Serial.println("Done!");
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  Serial.println(display.height());
  display.display();
  delay(2000); // Pause for 2 seconds

  // while(1)
  // {
  //   display.clearDisplay();
  //   display.setTextSize(1);             // Normal 1:1 pixel scale
  //   display.setTextColor(SSD1306_WHITE);        // Draw white text
  //   display.setCursor(0,0);             // Start at top-left corner
  //   display.println(F("Initializing..."));
  //   display.display();
  //   delay(2000);
  // }
}
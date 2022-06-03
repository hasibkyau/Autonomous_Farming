//this is for displaying clock 

#ifndef CLOCK_A
#define CLOCK_A

void jarvisClock() 
{
  display.clearDisplay();
  display.setCursor(0,0);
  
  //day and year
  display.println(myTZ.dateTime("l Y"));
  display.println(); 
   
  //time
  display.setTextSize(2);
  display.println(myTZ.dateTime("g:i A") + "\"");

  //date
  display.setTextSize(1);
  display.println();
  display.println(myTZ.dateTime("jS F"));

  //temperature
  display.setCursor(0, 55);
  display.print(bme.readTemperature() , 0);
  display.println("*C");

  //humidity
  display.setCursor(50, 55);
  display.print(bme.readHumidity(), 0);
  display.println("%");

  display.display();
}
  

#endif

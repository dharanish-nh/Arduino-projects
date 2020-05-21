// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*
   The setup function. We only start the sensors here
*/
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  //Serial.println("Dallas Temperature IC Control Library Demo");
  pinMode(13,OUTPUT);
  // Start up the library
  sensors.begin();
}

/*
   Main function, get and show the temperature
*/
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  // Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  // Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));

  while (Serial.available() > 0)
  { 
    String mm = Serial.readStringUntil('\n');
    mm.trim();
    Serial.println(mm);
    if (mm == "cmd:on") {
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
    }
  }
  delay(5000);
}

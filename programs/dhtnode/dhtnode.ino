#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11  // DHT 11

#define dht_dpin 7
int vib=A0;
int val;
DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  pinMode(vib,INPUT);
  dht.begin();
  Serial.begin(9600);
//  Serial.println("Humidity and temperature\n\n");
  //delay(700);

}
void loop() {
    /*float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.print("C  ");*/
    //long measurement =TP_init();
    //delay(50);
    val=analogRead(vib);
    Serial.println(val);
  //delay(800);
}

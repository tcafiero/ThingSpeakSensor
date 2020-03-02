#include <DHTesp.h>

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN  4
//DHT dht(DHTPIN, DHTTYPE, 11);// 11 works fine for ESP8266
DHTesp dht;
float humidity, temp;  // Values read from sensor
int i;


//char ssid[] = "IoThingsWareBus";    //  your network SSID (name)
//char pass[] = "07B04U1957S";   // your network password
char ssid[] = "Ambrogio";    //  your network SSID (name)
char pass[] = "20Eco_Ap16";   // your network password
int status = WL_IDLE_STATUS;
WiFiClient  client;
//unsigned long weatherStationChannelNumber = 12397;
//unsigned int temperatureFieldNumber = 4;
//unsigned long IoThingsWareChannelNumber = 44183;
//const char * IoThingsWareChannelWriteAPIKey = "OFMO9VLX1X6O9JAT";
unsigned long IoThingsWareChannelNumber = 167475;
const char * IoThingsWareChannelWriteAPIKey = "5XB2I9UBNJFD32Q8";


void setup() {
  Serial.begin(9600);
  delay(2000);
  dht.setup(DHTPIN, DHTesp::DHT11);

  //dht.begin();           // initialize temperature sensor
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  i=0;
}

void loop() {
  // get sensors falue and write on channel 168044
  //delay(600); // Note that the weather station only updates once a minute
  //delay(dht.getMinimumSamplingPeriod());
  delay(1200);
  getvalues();       // read sensor
}

void getvalues() {
  if(i == 0)
  {
    temp = 0;
    humidity = 0;
  }
  humidity += dht.getHumidity();          // Read humidity (percent)
  temp += dht.getTemperature();      // Read temperature as Fahrenheit
  if(++i >= 50)
  {
    humidity /= i;
    temp /= i;
    i=0;
  }
  else return;
  // Check if any reads failed and exit early (to try again).

  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.printf("Current temp is: ");
  Serial.print(temp);
  Serial.print(" °C\n");
  Serial.print("Current humidity is: ");
  Serial.print(humidity);
  Serial.println(" %");
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(IoThingsWareChannelNumber, IoThingsWareChannelWriteAPIKey);
}

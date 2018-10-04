//#include <DHTesp.h>

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN  4
DHT dht(DHTPIN, DHTTYPE, 11); // 11 works fine for ESP8266
float humidity, temp_f;  // Values read from sensor



char ssid[] = "IoThingsWareBus";    //  your network SSID (name)
char pass[] = "07B04U1957S";   // your network password
int status = WL_IDLE_STATUS;
WiFiClient  client;
//unsigned long weatherStationChannelNumber = 12397;
//unsigned int temperatureFieldNumber = 4;
unsigned long InputChannelNumber = 168044;
const char * InputChannelWriteAPIKey = "9W0Y5T5P2ICBF1HX";


void setup() {
  Serial.begin(9600);
  dht.begin();           // initialize temperature sensor
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
}

void loop() {
  // get sensors falue and write on channel 168044
  getvalues();       // read sensor
  delay(20000); // Note that the weather station only updates once a minute
}

void getvalues() {
  humidity = dht.readHumidity();          // Read humidity (percent)
  temp_f = dht.readTemperature(true);     // Read temperature as Fahrenheit
  // Check if any reads failed and exit early (to try again).

  if (isnan(humidity) || isnan(temp_f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Current temp is: ");
  Serial.print(temp_f);
  Serial.println(" °F");
  Serial.print("Current humidity is: ");
  Serial.print(humidity);
  Serial.println(" %");
  ThingSpeak.setField(1, temp_f);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(InputChannelNumber, InputChannelWriteAPIKey);
}


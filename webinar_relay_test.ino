#include "madBlocks.h" // User-Defined Headr File
#include <ESP8266WiFi.h> // Pre-Defined Hedar File

madBlocks mB; 

#define relay D0 // IN Pin of Relay

void relayon(void)
{
 Serial.println("Relay On");
 digitalWrite(relay,1);  // Inverse 
}

void relayoff(void)
{
 Serial.println("Relay Off");
 digitalWrite(relay,0);  
}

void connectWifi(void)
{
  Serial.println("Connecting to WiFi...");
  WiFi.disconnect(); // reset wi-Fi
  WiFi.begin("Automad","@ut0M@D0");
  while(!(WiFi.status()==WL_CONNECTED)) // WL_CONNECTED (1), WL_NOTCONNECTED (0)
  {
    delay(300); // 300ms For every 300ms, it keeps checking there
  }
  Serial.println("WiFi Connected");
}

void setup() // only one-time executable - configure
{
 Serial.begin(9600); // default speed (baudrate) of the monitor
 Serial.println("WELCOME To IoT Project");
 pinMode(relay,OUTPUT); // Taking permission from CPU
 relayoff();
 connectWifi(); // function calls
}

void loop() // infinite executable - iteratable
{
 if(mB.read("58a9ecf70021e4c2f5fa534d3635650f")=="on") // read will always the read 
  relayon();
 else if(mB.read("58a9ecf70021e4c2f5fa534d3635650f")=="off")
  relayoff();
 delay(1000);
}

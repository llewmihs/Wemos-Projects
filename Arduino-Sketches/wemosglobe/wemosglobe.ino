#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"
#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>

#define SERIAL_BAUDRATE                 115200
 
fauxmoESP fauxmo;
 
// -----------------------------------------------------------------------------
// Wifi
// -----------------------------------------------------------------------------
 
void setup() {
 
    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println();
    Serial.println();
 
    // Wifi
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("AutoConnectAP");
 
    // Fauxmo v2.0
    fauxmo.addDevice("light one");
    fauxmo.addDevice("light two");
    fauxmo.onMessage([](unsigned char device_id, const char * device_name, bool state) {
        Serial.printf("[MAIN] Device #%d (%s) state: %s\n", device_id, device_name, state ? "ON" : "OFF");
    });
 
}
 
void loop() {
    fauxmo.handle();
}

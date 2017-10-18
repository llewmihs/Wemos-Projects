/* After you write your sketch and start the ESP, 
it will try to connect to WiFi. If it fails it starts in Access Point mode. 
While in AP mode, connect to it then open a browser to the gateway IP, 
default 192.168.4.1, configure wifi, save and it should reboot and connect.
*/

#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>

void setup(){
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("AutoConnectAP");
}

void loop(){

}
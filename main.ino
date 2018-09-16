#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "jarvis";
const char *password = "";

ESP8266WebServer server(80);
const int led = 0;
const int led1 = 2; 

/* Just a little test message.  //Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {

  int size=1000;
  char temp[size];
  
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf ( temp, size,

"<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>JARVIS - Smart Home</title><style>body { height: 200px;background-color: yellow;font-family: Arial,Helvetica, Sans-Serif;background-image: linear-gradient(to right, #ff00cc , #333399); Color: #ffffff;} .button {background-color: #012E5E; color: #FDE428; padding: 15px 32px; text-align: center; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head><body><h1 align=\"center\">JARVIS - Smart Home</h1><h1 align=\"center\">LED 1</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/on\" class=\"button\"><h1 >ON</h1></a></td><td><a href=\"http://192.168.4.1/off\" class=\"button\"><h1>OFF</h1></a></td></tr></table><h1 align=\"center\">LED 2</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/onled1\" class=\"button\"><h1>ON</h1></a></td><td><a href=\"http://192.168.4.1/offled1\" class=\"button\"><h1>OFF</h1></a></td></tr></table></html>",

    hr, min % 60, sec % 60
  );
  server.send ( 200, "text/html", temp );  
  
}

void setup() {
  delay(0);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point...");

  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  pinMode(led, OUTPUT);
  digitalWrite ( led, HIGH );
pinMode(led1, OUTPUT);
  digitalWrite ( led1, HIGH );

  //URLs available to query
  server.on("/", handleRoot);
  server.on ( "/on", turnONled );    
  server.on ( "/off", turnOFFled );
  server.on ( "/onled1", turnONled1 );    
  server.on ( "/offled1", turnOFFled1 );
  server.begin();
  Serial.println("HTTP server started");
  
}

void turnONled(){

  digitalWrite ( led, HIGH );

  int size=1000;
  char temp[size];

  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf ( temp, size,

"<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>JARVIS - Smart Home</title><style>body { height: 200px;background-color: yellow;font-family: Arial,Helvetica, Sans-Serif;background-image: linear-gradient(to right, #ff00cc , #333399); Color: #ffffff;} .button {background-color: #012E5E; color: #FDE428; padding: 15px 32px; text-align: center; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head><body><h1 align=\"center\">JARVIS - Smart Home</h1><h1 align=\"center\">LED 1</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/on\" class=\"button\"><h1 >ON</h1></a></td><td><a href=\"http://192.168.4.1/off\" class=\"button\"><h1>OFF</h1></a></td></tr></table><h1 align=\"center\">LED 2</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/onled1\" class=\"button\"><h1>ON</h1></a></td><td><a href=\"http://192.168.4.1/offled1\" class=\"button\"><h1>OFF</h1></a></td></tr></table></html>",

    hr, min % 60, sec % 60
  );

  server.send ( 200, "text/html", temp);
  
}

void turnONled1(){

  digitalWrite ( led1, HIGH );

  int size=1000;
  char temp[size];

  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf ( temp, size,

"<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>JARVIS - Smart Home</title><style>body { height: 200px;background-color: yellow;font-family: Arial,Helvetica, Sans-Serif;background-image: linear-gradient(to right, #ff00cc , #333399); Color: #ffffff;} .button {background-color: #012E5E; color: #FDE428; padding: 15px 32px; text-align: center; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head><body><h1 align=\"center\">JARVIS - Smart Home</h1><h1 align=\"center\">LED 1</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/on\" class=\"button\"><h1 >ON</h1></a></td><td><a href=\"http://192.168.4.1/off\" class=\"button\"><h1>OFF</h1></a></td></tr></table><h1 align=\"center\">LED 2</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/onled1\" class=\"button\"><h1>ON</h1></a></td><td><a href=\"http://192.168.4.1/offled1\" class=\"button\"><h1>OFF</h1></a></td></tr></table></html>",

    hr, min % 60, sec % 60
  );

  server.send ( 200, "text/html", temp);
  
}

void turnOFFled(){

  digitalWrite ( led, LOW );

  int size=1000;
  char temp[size];

  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf ( temp, size,
"<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>JARVIS - Smart Home</title><style>body { height: 200px;background-color: yellow;font-family: Arial,Helvetica, Sans-Serif;background-image: linear-gradient(to right, #ff00cc , #333399); Color: #ffffff;} .button {background-color: #012E5E; color: #FDE428; padding: 15px 32px; text-align: center; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head><body><h1 align=\"center\">JARVIS - Smart Home</h1><h1 align=\"center\">LED 1</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/on\" class=\"button\"><h1 >ON</h1></a></td><td><a href=\"http://192.168.4.1/off\" class=\"button\"><h1>OFF</h1></a></td></tr></table><h1 align=\"center\">LED 2</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/onled1\" class=\"button\"><h1>ON</h1></a></td><td><a href=\"http://192.168.4.1/offled1\" class=\"button\"><h1>OFF</h1></a></td></tr></table></html>",

    hr, min % 60, sec % 60
  );

  server.send ( 200, "text/html", temp);
  
}

void turnOFFled1(){

  digitalWrite ( led1, LOW );

  int size=1000;
  char temp[size];

  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf ( temp, size,
"<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>JARVIS - Smart Home</title><style>body { height: 200px;background-color: yellow;font-family: Arial,Helvetica, Sans-Serif;background-image: linear-gradient(to right, #ff00cc , #333399); Color: #ffffff;} .button {background-color: #012E5E; color: #FDE428; padding: 15px 32px; text-align: center; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head><body><h1 align=\"center\">JARVIS - Smart Home</h1><h1 align=\"center\">LED 1</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/on\" class=\"button\"><h1 >ON</h1></a></td><td><a href=\"http://192.168.4.1/off\" class=\"button\"><h1>OFF</h1></a></td></tr></table><h1 align=\"center\">LED 2</h1><table align=\"center\"><tr><td><a href=\"http://192.168.4.1/onled1\" class=\"button\"><h1>ON</h1></a></td><td><a href=\"http://192.168.4.1/offled1\" class=\"button\"><h1>OFF</h1></a></td></tr></table></html>",

    hr, min % 60, sec % 60
  );

  server.send ( 200, "text/html", temp);
  
}



void loop() {
  server.handleClient();
}

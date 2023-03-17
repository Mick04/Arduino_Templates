#include <ESP8266WiFi.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

// Your WiFi credentials.
//char ssid[] = "Gimp_EXT";//outside board
char ssid[] = "Gimp";//inside board
char password[] = "FC7KUNPX";
/********************************************
            Static IP address Start
 ********************************************/

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

// HTML comments look like this <! comment in between here >
const char htmlCode[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Page Title</title>
</head>
<body>

<h1>My First Heading</h1>
<p>My first paragraph.</p>

</body>
</html>
)rawliteral";
void setup()
{
    Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP

  // put your setup code here, to run once:
  Serial.begin(115200);
    
  // WiFi.mode(WiFi_STA); // it is a good practice to make sure your code sets wifi mode how you want it.

  //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wm;

  //reset settings - wipe credentials for testing
  //wm.resetSettings();
  
  bool res;
  // res = wm.autoConnect(); // auto generated AP name from chipid
  // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
  res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

  if(!res) {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else {
    //if you get here you have connected to the WiFi    
    Serial.println("connected...yeey :)");
    Serial.println(WiFi.localIP());
  }
}
/********************************************
            Static IP address end
 ********************************************/

void loop() {
  // put your main code here, to run repeatedly:

}

  #include <ESP8266WiFi.h>
#include <WiFiUdp.h>

IPAddress local_IP(192,168,1,25);
IPAddress gateway(192,168,1,10);
IPAddress subnet(255,255,255,0);


// UDP
#define UDP_PORT 4100
WiFiUDP UDP;
char packet[255];
char reply[]="Packet received";

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("ESPsoftAP_02","123456789") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  int connected = 0;
  while(connected == 0) {
    connected = WiFi.softAPgetStationNum();
    delay(3000);
  }

  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port: ");
  Serial.println(UDP_PORT);

  //Serial.print("Soft-AP IP Address = ");
  //Serial.println(WiFi.softAPIP());
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
  // send udp
  int packetSize = UDP.parsePacket();
  if (packetSize) {
    Serial.print("Received packet! Size: ");
    Serial.println(packetSize);
    int len = UDP.read(packet, 255);
    if (len > 0)
    {
      packet[len] = '\0';
    } 
    Serial.print("Packet received: ");
    Serial.println(packet); 

    UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
    UDP.write(reply);
    UDP.endPacket();

    UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
    UDP.write("ESP says hello back :D");
    UDP.endPacket();
  }
  
 }

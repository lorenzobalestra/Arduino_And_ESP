#####################################################################
# Author: 	Bent Haugaløkken 				    #
# Contact: 	github 						    #
# Date:   	November, 2020					    #
# Description:  Setup for and how to use the ESP Device NodeMCU8266 #
#####################################################################

### Requirements
This guide has been verified for Arduino IDE version 1.8.3.

### Setup

1) Navigate to File > Preferences > Settings (first tab) > Put the following text into "Additional Boards Manager URLs" (Note: If you have something in this field already, place the following text after a comma):

http://arduino.esp8266.com/stable/package_esp8266com_index.json

2) Navigate to Tools > Boards > Board Manager > Find the package called esp8266 > Select Install (Version 2.7.4 is verified)

3) If you haven't already, plug the device in

4) Navigate to Tools > Port > choose the port for the device

5) Navigate to Tools > Boards > ESP8266 Boards > NodeMCU 1.0 (ESP-12E Module) 

### Usage

With the ESP Device connected, follow the steps below:

1) Open the file you want to upload

2) Hold the "Reset" button on the board when clicking upload, and when the terminal outputs "Connecting..." release the "Reset" button. 

3) Done

### Test WiFi Scan

1) Choose the WiFi scan file and follow the "Usage" procedure

2) Open the terminal in arduino to receive the output from the ESP device (Ctrl+Shift+M)

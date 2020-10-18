// CONTROL OF THE RC BOAT OVER BLUETOOTH WITH HC-05.
// HARDWARE CONFIGURATION 2 DOF: RUDDER AND DC BRUSHED MOTOR WITH H-BRIDGE. NON PROPORTIONAL CONTROLS 

//The servo library is necessary when controlling motors and servos
#include <Servo.h>            

// Definition of the pins used

#define enA 9                   // Enable line of the motor. 
#define in1 4                   // Input line 1 of the motor.
#define in2 5                   // Input line 2 of the motor.
#define rudderpin 6             // Pin controlling the rudder.
#define ledpin 12               // Pin controlling the position light.

char data = 0;                   //Variable for storing received BT data

Servo rudder;                   //Create an object rudder associated to a servo

void setup() {
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(rudderpin, OUTPUT);

Serial.begin(115200);                     //Sets the data rate in bits per second (baud) for serial data transmission

rudder.attach(rudderpin);                 //Links the rudder to its pin
}

void loop(){

// BT CONTROLS

if(Serial.available() > 0)            // Send data only when you receive data:
{
data = Serial.read();                 //Read the incoming data and store it into variable data

if(data == 'F'){                      //Checks whether value of data is equal to F 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, 150);
}

else if(data =='S'){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
 }

else if(data =='B'){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enA, 50);
}

else if(data =='R'){
  rudder.write(130);                              
}

else if(data =='L'){
  rudder.write(50);  
}
else if(data =='C'){
  rudder.write(90);
  }
}}

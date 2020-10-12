// CONTROL OF THE RC BOAT OVER BLUETOOTH WITH HC-05.
// HARDWARE CONFIGURATION 2 DOF: RUDDER AND DC BRUSHED MOTOR WITH H-BRIDGE. NON PROPORTIONAL CONTROLS 

//The servo library is necessary when controlling motors and servos
#include <Servo.h>            

// Initialization

#define enA 9
#define in1 4
#define in2 5
#define rudderpin 6
#define ledpin 12


char data = 0;                   //Variable for storing received BT data
int motorSpeed = 0;                

Servo rudder;                   //Create an object rudder associated to a servo

void setup() 
{
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

pinMode(rudderpin, OUTPUT);

Serial.begin(115200);                     //Sets the data rate in bits per second (baud) for serial data transmission

rudder.attach(rudderpin);                 //Links the rudder to its pin

}

void loop(){

// POSITION LIGHT

digitalWrite(ledpin, HIGH);           // turn the LED on (HIGH is the voltage level)
delay(1000);                          // wait for a second
digitalWrite(ledpin, LOW);            // turn the LED off by making the voltage LOW
delay(1000);                          // wait for a second

// RC CONTROLS

if(Serial.available() > 0)            // Send data only when you receive data:
{
data = Serial.read();                 //Read the incoming data and store it into variable data
delay(10);

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
  rudder.write(120);                              
}

else if(data =='L'){
  rudder.write(50);  
}
else if(data =='C'){
  rudder.write(90);
  }

}
}

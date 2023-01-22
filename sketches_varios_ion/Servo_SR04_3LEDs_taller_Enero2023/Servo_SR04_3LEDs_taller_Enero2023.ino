// Include servo library. we can llok upa for different libraries to control sevo
#include <Servo.h>

int rojo = 13;
int amarillo = 11;
int verde = 9;
// PWN pin 1 is to control servo (yellow-orange)
int servo_control = 1;
// trigger SR04 PWN Pin 6
int trigger = 6;
// echo SR04 PWN Pin 4
int echo = 4;
void setup() {
  Serial.begin (9600);
  pinMode(trigger, OUTPUT); // Set up trigger ping from ultrasonic sensor HC-SR04
  pinMode(echo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  servo.attach(servo_control); // Define Pin connected to servo control cable
}
void loop() {
  // measure distance with HC-SR04 sensor
  long
  // Sample LED blinking code
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, HIGH); 
  delay(500);              
  digitalWrite(rojo, LOW);   
  digitalWrite(amarillo, LOW); 
  digitalWrite(verde, LOW); 
  delay(500);
  // END of Sample LED blinking code
  // Sample Servo code

  // END of Sample Servo code
  }
// Code copied from https://www.instructables.com/Controlling-a-Servo-With-an-Ultrasonic-Sensor-Usin/
// Include servo library. we can look up a for different libraries to control servo
#include <Servo.h>

int rojo = 13;
int amarillo = 11;
int verde = 9;
// PWN pin 1 is to control servo (yellow-orange)
int servo_control = 2;
Servo servo; // Declare the servo variable
int sound = 250; // from 
// trigger SR04 PWN Pin 6
int triggerpin = 6;
// echo SR04 PWN Pin 4
int echopin = 4;
void setup() {
  Serial.begin (9600);
  pinMode(triggerpin, OUTPUT); // Set up trigger ping from ultrasonic sensor HC-SR04
  pinMode(echopin, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  servo.attach(servo_control); // Attach to defined Pin connected to servo control cable
}
void loop() {
  // measure distance with HC-SR04 sensor
  long duration, distance;
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)/29.1;
  if (distance <10){
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(verde, HIGH); 
    //delay(500);
    servo.write(90);
    delay(1000);
    digitalWrite(verde, LOW); 
  }
  else if (distance < 80){
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(rojo, HIGH);
    servo.write(145);
    delay(1000);
    digitalWrite(rojo, LOW);
  }
  else{
    Serial.println("The distance is more than 80cm.");
    digitalWrite(rojo, HIGH);
    servo.write(145);
    delay(1000);    
  }
  delay(500);
  // Sample LED blinking code
  /*
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, HIGH); 
  delay(500);              
  digitalWrite(rojo, LOW);   
  digitalWrite(amarillo, LOW); 
  digitalWrite(verde, LOW); 
  delay(500);
  // END of Sample LED blinking code
  */  
  // Sample Servo code

  // END of Sample Servo code
  }
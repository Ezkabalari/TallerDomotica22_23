

// Code copied from https://www.instructables.com/Controlling-a-Servo-With-an-Ultrasonic-Sensor-Usin/
// Include servo library. we can look up a for different libraries to control servo???
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
// here we declare pos as initial servo position for the angle in our case 145º
int pos0 = 145;
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
  servo.write(pos0);
  //delay(5000);
  // measure distance with HC-SR04 sensor
  long duration, distance;
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)/29.1;
  if (distance <12){
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(verde, HIGH); 
    //delay(1000);
    //servo.write(90);
    for (pos = 145; pos <= 235; pos += 1) {
      // In steps on 1 degree
      servo.write(pos);
      delay(15);
      }
    delay(6000); // To allow the car to pass the barrier with sufficient time
    // Now we lower the barrier 
    for (pos = 235; pos <= 145; pos -= 1) {
      servo.write(pos);
      //digitalWrite(verde, LOW); // Green led stays lit all the loop
      delay(15);
    }
    digitalWrite(verde, LOW); 
  }
  else if (distance < 50){
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(rojo, HIGH);
    //servo.write(145); //moves too fast
    for (pos = 235; pos <= 145; pos -= 1) {
      servo.write(pos);
      digitalWrite(rojo, LOW);
      delay(15);
    }
    //delay(2000);
    //digitalWrite(rojo, LOW);
  }
  else{
    Serial.println("The distance is more than 80cm.");
    digitalWrite(rojo, HIGH);
    servo.write(145); //moves too fast
    //delay(2000);
    digitalWrite(rojo, LOW);  
  }
  //delay(1000);
  // EXTRA CODE
  /*
  digitalWrite(amarillo, HIGH);
  delay(500);                
  digitalWrite(amarillo, LOW);  
  delay(500);
  */
  }  
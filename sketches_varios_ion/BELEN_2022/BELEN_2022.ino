#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
// HC-SR04
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el echo del sensor

void setup() {
  myservo.attach(7);  // attaches the servo on pin 7 to the servo object
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {  
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;//escalamos el tiempo a una distancia en cm
  // Here we add code to move servo form 0º to 90º.
  if (d <= 30){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    Serial.print("Distancia: ");
    Serial.print(d);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    delay(100);          //Hacemos una pausa de 100ms
  }
  }
  else if (d> 30){
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    Serial.print("Distancia: ");
    Serial.print(d);      //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    delay(50);
  }
  }
}

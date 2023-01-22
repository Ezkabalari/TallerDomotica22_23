// Programa para modificar la intensidad de un LED for.
int LEDA=13;// Salida PWM a utilizar con el LED.
int LEDB=12;
int LEDC=10;
int LEDD=8;
int angle=0;
//Include servo  library
#include <Servo.h>
Servo servo;
void setup() {
  //servo setup
  servo.attach(6);
  servo.write(angle);
  // Bloque de código de configuración de Leds
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDD, OUTPUT);
}
void loop() {
  // Ciclo de dia
  for(int i=1;i<255;i++){
    analogWrite(LEDA,i);
    analogWrite(LEDB,i);
    analogWrite(LEDC,i);
    analogWrite(LEDD,i);
    delay(100);
  }
  // Ciclo de noche
  for(int i=255;i>=1;i--){
    analogWrite(LEDA,i);
    analogWrite(LEDB,i);
    analogWrite(LEDC,i);
    analogWrite(LEDD,i);
    delay(100);
    }
  // move servo while dimming light
  // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++){
    servo.write(angle);
    delay(15);
  }
  for(angle = 180; angle > 10; angle--){                                
    servo.write(angle);           
    delay(15);       
  }
}
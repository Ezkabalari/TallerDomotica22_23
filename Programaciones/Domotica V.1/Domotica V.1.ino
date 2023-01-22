/* HECHO:
 *  Integración de componentes en general (Leds, GAS, LDR, LDR PARKING, PIR, HUMEDAD, relés y servomotor)
 *  Condiciones para los sensores (Parking, GAS, alarma, LDR y autorriego)
 *  
 * POR HACER:
 *  Nextion:  - Interfaz gráfica
 *            - Transmisión de datos
 *  Luces     - Implementación con Nextion
 *  Sensores: - Temperatura y ventilación
 *            
*/


//PIR               https://www.luisllamas.es/detector-de-movimiento-con-arduino-y-sensor-pir/
//LDR               https://www.luisllamas.es/medir-nivel-luz-con-arduino-y-fotoresistencia-ldr/
//Sensor Humedad    https://www.automatizacionparatodos.com/sensor-de-humedad-de-suelo-con-arduino/
//Servo             https://programarfacil.com/blog/arduino-blog/servomotor-con-arduino/
// Nextion          https://www.taloselectronics.com/blogs/tutoriales/como-usar-pantalla-nextion-con-arduino
// MQ 2             https://www.luisllamas.es/arduino-detector-gas-mq/


#include <Servo.h>

int luz_porche = 13;
int luz_salon = 12;
int luz_cocina = 11;
int luz_hab1 = 10;
int luz_hab2 = 9;
int luz_pasillo = 8;
int luz_wc = 7;
int luz_jardin = 6;

int zumbador = 5;

int rele1 = 4;
int rele2 = 3;

//Pines 0 y 1 reservados para Nextion

Servo valla;

int sensor_PIR = A0;
int sensor_PARKING= A1;
int sensor_LDR = A2;
int sensor_HUMEDAD = A3;
int sensor_GAS = A4;


void setup() {
  Serial.begin(115200);
  pinMode (luz_porche, OUTPUT);
  pinMode (luz_salon, OUTPUT);
  pinMode (luz_cocina, OUTPUT);
  pinMode (luz_hab1, OUTPUT);
  pinMode (luz_hab2, OUTPUT);
  pinMode (luz_pasillo, OUTPUT);
  pinMode (luz_wc, OUTPUT);
  pinMode (luz_jardin, OUTPUT);

  pinMode (zumbador, OUTPUT);

  pinMode (rele1, OUTPUT);
  pinMode (rele2, OUTPUT);

  valla.attach (2);

  pinMode (sensor_PIR, INPUT);
  pinMode (sensor_PARKING, INPUT);
  pinMode (sensor_LDR, INPUT);
  pinMode (sensor_HUMEDAD, INPUT);
  pinMode (sensor_GAS, INPUT);
}

void loop() {
  digitalWrite (luz_porche, LOW);
  digitalWrite (luz_salon, LOW);
  digitalWrite (luz_cocina, LOW);
  digitalWrite (luz_hab1, LOW);
  digitalWrite (luz_hab2, LOW);
  digitalWrite (luz_pasillo, LOW);
  digitalWrite (luz_wc, LOW);
  digitalWrite (luz_jardin, LOW);

  int valorPIR = digitalRead (sensor_PIR); ///////////////////////////////////////////////////////////////////////////////
  if (valorPIR == HIGH){
    tone (zumbador, 244, 100);
    tone (zumbador, 200, 100);
    tone (zumbador, 244, 100);
    tone (zumbador, 200, 100);
    tone (zumbador, 244, 100);
    tone (zumbador, 200, 100);
  }

  int valorPARKING = digitalRead (sensor_PARKING); ///////////////////////////////////////////////////////////////////////////
  if (valorPARKING == LOW){
    valla.write(90);
  }
  else {
    valla.write(0);
  }

  int valorLDR = digitalRead (sensor_LDR); /////////////////////////////////////////////////////////////////////////////
  if (valorLDR == LOW){
    digitalWrite (luz_porche, HIGH);
  }
  else {
    digitalWrite (luz_porche, LOW);
  }

  int valorHUM = digitalRead (sensor_HUMEDAD); ////////////////////////////////////////////////////////////////////////
  if (valorHUM >= 460) {
    digitalWrite (rele1, HIGH)
    delay (10000);
    digitalWrite (rele1, LOW);
  }
  
  int valorGASb = digitalRead (sensor_GAS);
  float valorGAS= valorGASb * (5.0 / 1023.0);
   if (valorGAS >= 700) {
    digitalWrite (rele2, HIGH);
    delay (10000);
    digitalWrite (rele2, LOW);
  }
}

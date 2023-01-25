/*
 * Pines de conexionado a arduino UNO:
 * 
 * A0: Sensor de gas para la cocina           (MQ-02)
 * A1: Sensor de humedad de la tierra         (Higrometro V1.2)
 * A2: Sensor de luz para garaje              (KY-018)
 * A3: Sensor de luz para exterior            (KY-018)
 * A4: Sensor de presencia del pasillo        (HC-SR505)
 * A5: Sensor de temperatura de habitación 1  (LM35)
 * D0: Nextion cable azul                     (Nextion NX8048T050)
 * D1: Nextion cable amarillo                 (Nextion NX8048T050)
 * D2: Leds Habitación 1                      (Led amarillo 5mm)
 * D3: Leds Baño                              (Led amarillo 5mm)
 * D4: Leds Cuarto lavadora                   (Led amarillo 5mm)
 * D5: Leds Habitación 2                      (Led amarillo 5mm)
 * D6: Leds Pasillo                           (Led amarillo 5mm)
 * D7: Leds Cocina                            (Led amarillo 5mm)
 * D8: Leds Salón                             (Led amarillo 5mm)
 * D9: Leds Gimnasio                          (Led amarillo 5mm)
 * D10: ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * D11: Servomotor de la puerta principal     (SG-90)
 * D12: Ventilador de la habitación 1         (Noctua NF-A4x10)
 * D13: Bomba de agua de la tierra            (Bomba de agua de 12v)
 */

/* 
DATOS MANDADOS DE NEXTION A ARDUINO

NAME     |  ON    |  OFF   |  description
=====================================================
lall     |  100   |  101   |  luces de toda la casa
lh1      |  102   |  103   |  luces habitación 1
lwc      |  104   |  105   |  luces baño
llav     |  106   |  107   |  luces lavadora
lh2      |  108   |  109   |  luces habitación 2
lco      |  110   |  111   |  luces cocina
lpas     |  112   |  113   |  luces pasillo
lgym     |  114   |  115   |  luces gimnasio
lsal     |  116   |  117   |  luces salón
bal      |   1    |   2    |  botón alarma
bven     |  200   |        |  botón ventilador
bag      |  201   |        |  botón agua
bpu      |  202   |        |  botón puerta



DATOS MANDADOS DE ARDUINO A NEXTION
variable |    sensor   | lugar
=======================================
stem     | temperatura | habitación 1
sgas     |     gas     | cocina
ssum     |   humedad   | jardín
spir     |  movimiento | pasillo
sldr     |     LDR     | menú
sppal    |     LDR     | puerta principal

*/
// LIBRERÍAS
#include <Servo.h>


//PINES UTILIZADOS
int rele_bomba = 13;                              //Configuramos la salida digital 13 para el relé que controla la bomba de agua
int rele_ventilador = 12;                         //Configuramos la salida digital 12 para el relé que controla el ventilador
Servo puerta_principal;                           //Los servos se configuran en el void setup
//////////////////////////////////////////////////////////////////////////SALIDA 10 DISPONIBLE//////////////////////////////////////////////////////////////////////////
int led_gimnasio = 9;                             //Configuramos la salida digital 9 para la luz del gimnasio
int led_salon = 8;                                //Configuramos la salida digital 8 para la luz del salón
int led_cocina = 7;                               //Configuramos la salida digital 7 para la luz de la cocina
int led_pasillo = 6;                              //Configuramos la salida digital 6 para la luz del pasillo
int led_hab2 = 5;                                 //Configuramos la salida digital 5 para la luz de la habitación 2
int led_lavadora = 4;                             //Configuramos la salida digital 4 para la luz del cuarto de la lavadora
int led_wc = 3;                                   //Configuramos la salida digital 3 para la luz del baño
int led_hab1 = 2;                                 //Configuramos la salida digital 2 para la luz de la habitación 1
// Pin 1 reservado para Nextion                   //Arduino trae por defecto éste pin para la transmisión de datos
// Pin 0 reservado para Nextion                   //Arduino trae por defecto éste pin para la recepción de datos
int sensor_temperatura = A5;                      //Configuramos la entrada analógica 5 para el sensor de temperatura
int sensor_PIR = A4;                              //Configuramos la entrada analógica 4 para el sensor de movimiento
int sensor_luz = A3;                              //Configuramos la entrada analógica 3 para el sensor de luz
int sensor_puerta = A2;                           //Configuramos la entrada analógica 2 para el sensor de luz
int sensor_tierra = A1;                           //Configuramos la entrada analógica 1 para el sensor de humedad
int sensor_gas = A0;                              //Configuramos la entrada analógica 0 para el sensor de gas


void setup() {
  Serial.begin (9600);                            //Iniciamos la comunicación serial a 9600 baudios para la comunicación con la pantalla Nextion
  pinMode (rele_bomba, OUTPUT);                   //Definimos como SALIDA el pin conectado al relé que controla la bomba de agua
  pinMode (rele_ventilador, OUTPUT);              //Definimos como SALIDA el pin conectado al relé que controla el ventilador
  puerta_principal.attach (11);                   //Configuramos la SALIDA 11 para el servo de la puerta principal
  pinMode (led_gimnasio, OUTPUT);                 //Definimos como SALIDA el pin conectado a la luz del gimnasio
  pinMode (led_salon, OUTPUT);                    //Definimos como SALIDA el pin conectado a la luz del salon
  pinMode (led_cocina, OUTPUT);                   //Definimos como SALIDA el pin conectado a la luz de la cocina
  pinMode (led_pasillo, OUTPUT);                  //Definimos como SALIDA el pin conectado a la luz del pasillo
  pinMode (led_hab2, OUTPUT);                     //Definimos como SALIDA el pin conectado a la luz de la habitación 2
  pinMode (led_lavadora, OUTPUT);                 //Definimos como SALIDA el pin conectado a la luz del cuarto de la lavadora
  pinMode (led_wc, OUTPUT);                       //Definimos como SALIDA el pin conectado a la luz del baño
  pinMode (led_hab1, OUTPUT);                     //Definimos como SALIDA el pin conectado a la luz de la habitación 1
  pinMode (sensor_temperatura, INPUT);            //Definimos como ENTRADA el pin conectado al sensor de temperatura
  pinMode (sensor_PIR, INPUT);                    //Definimos como ENTRADA el pin conectado al sensor de presencia
  pinMode (sensor_luz, INPUT);                    //Definimos como ENTRADA el pin conectado al sensor de luz del exterior
  pinMode (sensor_puerta, INPUT);                 //Definimos como ENTRADA el pin conectado al sensor de luz de la puerta principal
  pinMode (sensor_tierra, INPUT);                 //Definimos como ENTRADA el pin conectado al sensor de humedad de la tierra
  pinMode (sensor_gas, INPUT);                    //Definimos como ENTRADA el pin conectado al sensor de gases
  
}

void loop() {
  int Vstem = analogRead (sensor_temperatura);    //Definimos una variable a la cual asignamos el valor de lectura del sensor de temperatura
  int Vspir = analogRead (sensor_PIR);            //Definimos una variable a la cual asignamos el valor de lectura del sensor de movimiento
  int Vsldr = analogRead (sensor_luz);            //Definimos una variable a la cual asignamos el valor de lectura del sensor de luz exterior
  int Vsppal = analogRead (sensor_puerta);        //Definimos una variable a la cual asignamos el valor de lectura del sensor de luz entrada
  int Vshum = analogRead (sensor_tierra);         //Definimos una variable a la cual asignamos el valor de lectura del sensor de humedad del suelo
  int Vsgas = analogRead (sensor_gas);            //Definimos una variable a la cual asignamos el valor de lectura del sensor de gas

  
  String lectura = Serial.readString();           //Definimos la variable lectura que será con la cual recogeremos el valor de la pantalla
  
  if (int(lectura[0]) == 100){
      digitalWrite (led_gimnasio, HIGH);          //Encendemos los leds del gimnasio
      digitalWrite (led_salon, HIGH);             //Encendemos los leds del salón
      digitalWrite (led_cocina, HIGH);            //Encendemos los leds de la cocina
      digitalWrite (led_pasillo, HIGH);           //Encendemos los leds del pasillo
      digitalWrite (led_hab2, HIGH);              //Encendemos los leds de la habitación 2
      digitalWrite (led_lavadora, HIGH);          //Encendemos los leds del cuarto de la lavadora
      digitalWrite (led_wc, HIGH);                //Encendemos los leds del baño
      digitalWrite (led_hab1, HIGH);              //Encendemos los leds de la habitación 1
    }
  if (int(lectura[0]) == 101){
      digitalWrite (led_gimnasio, LOW);           //Apagamos los leds del gimnasio
      digitalWrite (led_salon, LOW);              //Apagamos los leds del salón
      digitalWrite (led_cocina, LOW);             //Apagamos los leds de la cocina
      digitalWrite (led_pasillo, LOW);            //Apagamos los leds del pasillo
      digitalWrite (led_hab2, LOW);               //Apagamos los leds de la habitación 2
      digitalWrite (led_lavadora, LOW);           //Apagamos los leds del cuarto de la lavadora
      digitalWrite (led_wc, LOW);                 //Apagamos los leds del baño
      digitalWrite (led_hab1, LOW);               //Apagamos los leds de la habitación 1
    }
  if (int(lectura[0]) == 102){
      digitalWrite (led_hab1, HIGH);              //Encendemos los leds de la habitación 1
    }
  if (int(lectura[0]) == 103){
      digitalWrite (led_hab1, LOW);               //Apagamos los leds de la habitación 1
    }
  if (int(lectura[0]) == 104){
      digitalWrite (led_wc, HIGH);                //Encendemos los leds del baño
    }
  if (int(lectura[0]) == 105){
      digitalWrite (led_wc, LOW);                 //Apagamos los leds del baño
    }
  if (int(lectura[0]) == 106){
      digitalWrite (led_lavadora, HIGH);          //Encendemos los leds del cuarto de la lavadora
    }
  if (int(lectura[0]) == 107){
      digitalWrite (led_lavadora, LOW);           //Apagamos los leds del cuarto de la lavadora
    }
  if (int(lectura[0]) == 108){
      digitalWrite (led_hab2, HIGH);              //Encendemos los leds de la habitación 2
    }
  if (int(lectura[0]) == 109){
      digitalWrite (led_hab2, LOW);               //Apagamos los leds de la habitación 2
    }
  if (int(lectura[0]) == 110){
      digitalWrite (led_cocina, HIGH);            //Encendemos los leds de la cocina
    }
  if (int(lectura[0]) == 111){
      digitalWrite (led_cocina, LOW);             //Apagamos los leds de la cocina
    }
  if (int(lectura[0]) == 112){
      digitalWrite (led_pasillo, HIGH);           //Encendemos los leds del pasillo
    }
  if (int(lectura[0]) == 113){
      digitalWrite (led_pasillo, LOW);            //Apagamos los leds del pasillo
    }
  if (int(lectura[0]) == 114){
      digitalWrite (led_gimnasio, HIGH);          //Encendemos los leds del gimnasio
    }
  if (int(lectura[0]) == 115){
      digitalWrite (led_gimnasio, LOW);           //Apagamos los leds del gimnasio
    }
  if (int(lectura[0]) == 116){
      digitalWrite (led_salon, HIGH);             //Encendemos los leds del salón
    }
  if (int(lectura[0]) == 117){
      digitalWrite (led_salon, LOW);              //Apagamos los leds del salón
    }
  
  delay (2500);
  
  Serial.print ("stem.val=");                     //Enviamos datos del sensor de temperatura a la pantalla
  Serial.print (Vstem);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print ("sgas.val=");                     //Enviamos datos del sensor de gas a la pantalla
  Serial.print (Vsgas);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print ("shum.val=");                     //Enviamos datos del sensor de humedad a la pantalla
  Serial.print (Vshum);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print ("spir.val=");                     //Enviamos datos del sensor de movimiento a la pantalla
  Serial.print (Vspir);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print ("sppal.val=");                    //Enviamos datos del sensor de luz de la puerta principal a la pantalla
  Serial.print (Vsppal);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.print ("sldr.val=");                     //Enviamos datos del sensor de luz exterior a la pantalla
  Serial.print (Vsldr);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  
}

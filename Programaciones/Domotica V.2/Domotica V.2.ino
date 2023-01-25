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
 * D10: Servomotor del garaje (Valla)         (SG-90)
 * D11: Servomotor de la puerta principal     (SG-90)
 * D12: Ventilador de la habitación 1         (Noctua NF-A4x10)
 * D13: Bomba de agua de la tierra            (Bomba de agua de 12v)
 */

// LIBRERÍAS
#include <Servo.h>


//PINES UTILIZADOS
int rele_bomba = 13;                              //Configuramos la salida digital 13 para el relé que controla la bomba de agua
int rele_ventilador = 12;                         //Configuramos la salida digital 12 para el relé que controla el ventilador
Servo puerta_principal;                           //Los servos se configuran en el void setup
Servo valla_garaje;                               //Los servos se configuran en el void setup
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
int sensor_PIR = A4;                              //Configuramos la entrada analógica 4 para el sensor de temperatura
int sensor_luz = A3;                              //Configuramos la entrada analógica 3 para el sensor de temperatura
int sensor_garaje = A2;                           //Configuramos la entrada analógica 2 para el sensor de temperatura
int sensor_tierra = A1;                           //Configuramos la entrada analógica 1 para el sensor de temperatura
int sensor_gas = A0;                              //Configuramos la entrada analógica 0 para el sensor de temperatura


void setup() {
  Serial.begin (9600);                            //Iniciamos la comunicación serial a 9600 baudios para la comunicación con la pantalla Nextion
  pinMode (rele_bomba, OUTPUT);                   //Definimos como SALIDA el pin conectado al relé que controla la bomba de agua
  pinMode (rele_ventilador, OUTPUT);              //Definimos como SALIDA el pin conectado al relé que controla el ventilador
  puerta_principal.attach (11);                   //Configuramos la salida 11 para el servo de la puerta principal
  valla_garaje.attach (10);                       //Configuramos la salida 10 para el servo de la valla del garaje
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
  pinMode (sensor_garaje, INPUT);                 //Definimos como ENTRADA el pin conectado al sensor de luz del garaje
  pinMode (sensor_tierra, INPUT);                 //Definimos como ENTRADA el pin conectado al sensor de humedad de la tierra
  pinMode (sensor_gas, INPUT);                    //Definimos como ENTRADA el pin conectado al sensor de gases
  
}

void loop() {
  int Vsgas = analogRead (sensor_gas);
    Serial.print ("prueba.val=");
    Serial.print (Value);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

}



void setup() {
  Serial.begin(9600);
  pinMode (A5, INPUT);
}

void loop() {
    int Value = analogRead (A5);
    Serial.print ("prueba.val=");
    Serial.print (Value);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    if (Value < 500){
      Serial.print ("menu.pic=1");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
    if (Value > 500){
      Serial.print ("menu.pic=0");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
    delay (1000);

}

/*
Habitación 1: lh1 luz stem temperatura

Baño: lwc luz bven ventilador

Lavadora: llav luz

Habitación 2: lh2 luz

Cocina: lco luz sgas sensor gas

Jardin: pic2 fondo ljar luz bag agua shum sensor humedad

Pasillo: lpas luz bal alarma bpu puerta

Gym: lgym luz

Salon: lsal luz
*/

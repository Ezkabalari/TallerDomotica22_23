
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

*/
Habitación 1: lh1 luz stem temperatura

Baño: lwc luz bven ventilador

Lavadora: llav luz

Habitación 2: lh2 luz

Cocina: lco luz sgas sensor gas

Jardin: pic2 fondo ljar luz bag agua shum sensor humedad

Pasillo: lpas luz bal alarma bpu puerta

Gym: lgym luz

Salon: lsal luz
/*

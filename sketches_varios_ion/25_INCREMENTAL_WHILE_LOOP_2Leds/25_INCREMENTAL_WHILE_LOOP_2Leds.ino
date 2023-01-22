// Programa para modificar la intensidad de un LED for.
int LEDA=13;// Salida PWM a utilizar con el LED.
int LEDB=12;
int LEDC=10;
int LEDD=8;
void setup() {
  // Bloque de código de configuración.
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
}
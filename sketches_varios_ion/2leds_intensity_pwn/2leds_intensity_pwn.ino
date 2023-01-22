// Programa para modificar la intensidad de un ledA
int ledA = 13;
int ledB = 12;
void setup() {
  // Bloque de código de configuración.
  pinMode(ledA, OUTPUT);
  }
void loop() {
  // DAY CYCLE
  analogWrite(ledA, 50);
  analogWrite(ledB, 50);
  delay(1000);
  analogWrite(ledA, 75);
  analogWrite(ledB, 75);
  delay(1000);
  analogWrite(ledA, 100);
  analogWrite(ledB, 100);
  delay(1000);
  analogWrite(ledA, 125);
  analogWrite(ledB, 125);
  delay(1000);
  analogWrite(ledA, 150);
  analogWrite(ledB, 150);
  delay(1000);
  analogWrite(ledA, 175);
  analogWrite(ledB, 175);
  delay(1000);
  analogWrite(ledA, 200);
  analogWrite(ledB, 200);
  delay(1000);
  analogWrite(ledA, 225);
  analogWrite(ledB, 225);
  delay(1000);
  analogWrite(ledA, 250);
  analogWrite(ledB, 250);
  delay(1000);

  //Night CYCLE
  analogWrite(ledA, 250);
  analogWrite(ledB, 250);
  delay(1000);
  analogWrite(ledA, 225);
  analogWrite(ledB, 225);
  delay(1000);
  analogWrite(ledA, 200);
  analogWrite(ledB, 200);
  delay(1000);
  analogWrite(ledA, 175);
  analogWrite(ledB, 175);
  delay(1000);
  analogWrite(ledA, 150);
  analogWrite(ledB, 150);
  delay(1000);
  analogWrite(ledA, 125);
  analogWrite(ledB, 125);
  delay(1000);
  analogWrite(ledA, 100);
  analogWrite(ledB, 100);
  delay(1000);
  analogWrite(ledA, 75);
  analogWrite(ledB, 75);
  delay(1000);
  analogWrite(ledA, 50);
  analogWrite(ledB, 50);
  delay(1000);

}
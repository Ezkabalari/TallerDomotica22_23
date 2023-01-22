/*
My blink test 3 leds
*/
#define pinLEDVERDE 9 // Definir pin verde en el 8 de PWN
#define pinLEDAMARILLO 10 // Definir pin verde en el 8 de PWN
#define pinLEDROJO 11 // Definir pin verde en el 8 de PWN
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pinLEDVERDE, OUTPUT);
  pinMode(pinLEDAMARILLO, OUTPUT);
  pinMode(pinLEDROJO, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pinLEDVERDE, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(pinLEDVERDE, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  digitalWrite(pinLEDAMARILLO, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(pinLEDAMARILLO, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(pinLEDROJO, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(pinLEDROJO, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}
int del = 20;
int a = 0;

void setup() {
  pinMode(8, OUTPUT); // LED control pin is 8, a PWM capable pin
}

void loop() {
  for (a = 0 ; a < 256 ; a++) {
    analogWrite(8, a);
    delay(del);
  }
  for (a = 255 ; a >= 0 ; a--) {
    analogWrite(8, a);
    delay(del);
  }
  delay(4000);
}
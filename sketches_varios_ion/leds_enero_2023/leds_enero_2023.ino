int rojo = 13;
int amarillo = 11;
int verde = 9;
// PWN pin 1 is to control servo (yellow-orange)
int servo_control = 1;
// trigger SR04 PWN Pin 6
// echo SR04 PWN Pin 4
void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}
void loop() {
  // Sample LED blinking code
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, HIGH); 
  delay(500);              
  digitalWrite(rojo, LOW);   
  digitalWrite(amarillo, LOW); 
  digitalWrite(verde, LOW); 
  delay(500);
  // END of Sample LED blinking code
  }
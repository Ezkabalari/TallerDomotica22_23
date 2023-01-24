
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

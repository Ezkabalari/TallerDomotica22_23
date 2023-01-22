int led13 = 13;
int led12 = 12;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(led12, HIGH);
  digitalWrite(led13, HIGH);
  delay(1000);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);
  delay(1000);

}
// Woorks at 1 second interval

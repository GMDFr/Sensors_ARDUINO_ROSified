
void setup()
{
  // nothing to initialize
  Serial.begin(9600);
}

void loop()
{

  int value = analogRead(A0);
  Serial.println(value);
  delay(1000);
}

#define WATER_SENSOR 2

void setup()
{
  Serial.begin (9600);
  pinMode(WATER_SENSOR, INPUT);
}
void loop()
{
  if(digitalRead(WATER_SENSOR)==1){
    Serial.println("0");
    }else{
      Serial.println("1");
    }
  delay(500);
}

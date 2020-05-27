#define HALL_SENSOR 2

void setup()
{
    pinsInit();
    Serial.begin(9600);
}

void loop() 
{
    if(isNearMagnet())//if the hall sensor is near the magnet?
    {
        turnOnLED();
    }
    else
    {
        turnOffLED();
    }
    delay(1000);
}
void pinsInit()
{
    pinMode(HALL_SENSOR, INPUT);
}

/*If the hall sensor is near the magnet whose south pole is facing up, */
/*it will return ture, otherwise it will return false.              */
boolean isNearMagnet()
{
    int sensorValue = digitalRead(HALL_SENSOR);
    if(sensorValue == LOW)//if the sensor value is LOW?
    {
        return true;//yes,return ture
    }
    else
    {
        return false;//no,return false
    }
}
void turnOnLED()
{
    Serial.println("HIGH");
}
void turnOffLED()
{
    Serial.println("LOW");
}

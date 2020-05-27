#define FLAME_SENSOR A0 //connect SENSOR to digital pin A0

void setup()
{
    Serial.begin(9600);
    pinsInit();
}
void loop()
{
    if(isFlameDetected())
    Serial.println("Feu");
    else Serial.println("Pas de feu");;
    delay(1000);
}
    /********************************/
void pinsInit()
{
    pinMode(FLAME_SENSOR, INPUT);
}

boolean isFlameDetected()
{
    if(digitalRead(FLAME_SENSOR))
    return false;
    else return true;
}

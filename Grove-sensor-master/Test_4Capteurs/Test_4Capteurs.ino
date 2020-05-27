#define heaterSelPin 15
const int alcoholPin = A0;  // La sortie analogique du détecteur MQx est reliée au Pin analogique A0 de l'Arduino
const int mqxPin = A1;  // La sortie analogique du détecteur MQx est reliée au Pin analogique A1 de l'Arduino
const int mq5Pin = A2;  // La sortie analogique du détecteur MQ5 est reliée au Pin analogique A2 de l'Arduino
const int mq9Pin = A3;  // La sortie analogique du détecteur MQ9 est reliée au Pin analogique A2 de l'Arduino
void setup() {
    Serial.begin(9600);
    pinMode(heaterSelPin,OUTPUT);   // set the heaterSelPin as digital output.
    digitalWrite(heaterSelPin,LOW); // Start to heat the sensor
}

void loop() {
    float sensor_volt;
    float RS_air; //  Get the value of RS via in a clear air
    float sensorValue = 0;

//--- Get a average data by testing 100 times ---
    for(int x = 0 ; x < 100 ; x++)
    {
        sensorValue = sensorValue + analogRead(alcoholPin);
    }
    sensorValue = sensorValue/100.0;
//-----------------------------------------------

    sensor_volt = sensorValue/1024*5.0;
    RS_air = sensor_volt/(5.0-sensor_volt); // omit *R16
    Serial.print("sensor_volt = ");
    Serial.print(sensor_volt);
    Serial.println("V");
    Serial.print("RS_air = ");
    Serial.println(RS_air);
    Serial.print("MQ3 =");
    Serial.println(analogRead(mqxPin));
    Serial.print("MQ5 =");
    Serial.println(analogRead(mq5Pin));
    Serial.print("MQ9 =");
    Serial.println(analogRead(mq9Pin));
    delay(1000);
}

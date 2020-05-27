#include <ros.h>
#include <std_msgs/String.h>
#define heaterSelPin 15

const int alcoholPin = A0;
const int mqxPin = A1;
const int mq5Pin = A2;
const int mq9Pin = A3;
ros::NodeHandle  nh;

std_msgs::String str_msg;

ros::Publisher chatter("chatter", &str_msg);

int MQ2;
int MQ5;
int MQ9;
float Alcool;
String text;
char test[50];
float sensorValue = 0;
float sensor_volt;
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  pinMode(heaterSelPin,OUTPUT);   // set the heaterSelPin as digital output.
  digitalWrite(heaterSelPin,LOW);
}

void loop()
{
  for(int x = 0 ; x < 100 ; x++)
    {
        sensorValue = sensorValue + analogRead(alcoholPin);
    }
    sensorValue = sensorValue/100.0;

  sensor_volt = sensorValue/1024*5.0;
  Alcool = sensor_volt/(5.0-sensor_volt);
  MQ2 = analogRead(mqxPin);
  MQ5 = analogRead(mq5Pin);
  MQ9 = analogRead(mq9Pin);
  String msg = String("MQ2 = "+String(MQ2)+", Alcool = "+String(Alcool)+", MQ5 = "+String(MQ5)+", MQ9 = "+String(MQ9));
  msg.toCharArray(test, 50);
  str_msg.data = test;

  //str_msg.data.append(msg);
  //Serial.println(msg);
  chatter.publish( &str_msg );

  nh.spinOnce();
  delay(1000);
}
#include "ros.h"
#include "template_v1/Temp1.h" //import customized message
#define pin 0

float raw_voltage = 0;

//callback function declaration
void voltageCallback(const template_v1::Temp1& volt1);

ros::NodeHandle nh; //creating nodehandle
template_v1::Temp1 volt;//creating messasge object

//creating publisher and subsriber to the topic 'voltage'
ros::Publisher voltage_pub("voltage",&volt);
ros::Subscriber<template_v1::Temp1>voltage_sub("voltage",voltageCallback);

//initialize arduino
void setup()
{
  pinMode(pin, OUTPUT);
  nh.initNode();
  nh.advertise(voltage_pub);
  nh.subscribe(voltage_sub);

  //prevent program not being initialize properly
  while (!nh.connected())
 {
   nh.spinOnce();
 }

 nh.loginfo("CONNECTED");//when connected, show notification
}

//ardino main loop
void loop()
{
  volt.volt1 = analogRead(pin);//message object read data from pin
  voltage_pub.publish(&volt);//publish the read data
  nh.spinOnce();
  delay(1000);
}

//call back function
void voltageCallback(const template_v1::Temp1& volt)
{
  raw_voltage = volt.volt1;
}

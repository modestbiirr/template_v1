#include "ros/ros.h"
#include "template_v1/Temp1.h" //importing customized message


int main(int argc, char** argv){

  ros::init(argc, argv, "example_pub_cpp");//initialize ROS with node name
  ros::NodeHandle nh; //create a node handle

  /*Creatig a publisher that going to publish on topic "voltage" with buffer size 50*/
  ros::Publisher pub = nh.advertise<template_v1::Temp1>("voltage",50);

  while (ros::ok())
  {
    template_v1::Temp1 volt; //creating an message object
    volt.volt1 = 175.0;
    pub.publish(volt);//publish the message to the topic

    ros::spinOnce();//enable callback to be called
  }

  return 0;
}

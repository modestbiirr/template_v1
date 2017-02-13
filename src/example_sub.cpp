#include "ros/ros.h"
#include "template_v1/Temp1.h"//importing customized message

float g_voltage_sub = 0;

/*Callback function*/
void voltageCallback(const template_v1::Temp1& volt){
  g_voltage_sub = volt.volt1;
}

int main(int argc, char** argv){

  ros::init(argc, argv, "example_sub_cpp");//initialize ROS with node name
  ros::NodeHandle nh; //create a node handle
  /*Creatig a Subscriber that subscribe on topic "voltage" with buffer size 50.
    Also, it will call the callback function whenever a message is received*/
  ros::Subscriber sub = nh.subscribe("voltage",50,voltageCallback);

  ros::spin();//Enter loops that calling message callback asap

  return 0;
}

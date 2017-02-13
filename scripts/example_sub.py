#Python scripts must be started with the line below
#!/usr/bin/env python

import rospy
from template_v1.msg import Temp1 #import customized message

#define callback function
def callback(data):
	g_voltage_sub = data.volt1;

#define interface to voltage_sub()
def voltage_sub():

	#initialize a node with node name
	rospy.init_node('example_sub_py',anonymous=True)
	#creating a subscriber register to topic "voltage"
	#Also, whenever a message is received, call callback function
	rospy.Subscriber("voltage",Temp1,callback)

	rospy.spin()#prevent python from exit until this node is stopped

if __name__ == '__main__':
	voltage_sub()

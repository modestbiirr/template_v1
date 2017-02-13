#!/usr/bin/env python

import rospy
from template_v1.msg import Temp1 #import customized message

#define interface to voltage_pub()
def voltage_pub():

    #initialize a node with node name
    rospy.init_node('example_pub_py',anonymous = True)
    #creating a publisher register to topic voltage
    #queue size is used, in case subscriber can't receive message too fast
    pub = rospy.Publisher('voltage', Temp1, queue_size=10)
    volt_msg = Temp1() #creating a message
    rate = rospy.Rate(10) #looping in desired frequency


    while not rospy.is_shutdown():
        volt_msg.volt1 = 175
        volt_msg.volt2 = 888
        pub.publish(volt_msg)#publish the message to the topic
        rate.sleep()

if __name__ == '__main__':
    try:
        voltage_pub()
    except rospy.ROSInterruptException:
        pass

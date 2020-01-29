#! /usr/bin/env python

## Node to subscribe to a string and print the string on terminal.

import rospy
from ros_pubsub.msg import SensorInformation

# Topic callback function.
def stringListenerCallback(data):
    rospy.loginfo(' The contents of topic: %s', data.maker_name)

def stringListener():
    rospy.init_node('senor_info_subscriber' , anonymous = False)
    
    rospy.Subscriber('sensor_info' , SensorInformation, stringListenerCallback)
    
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    stringListener()

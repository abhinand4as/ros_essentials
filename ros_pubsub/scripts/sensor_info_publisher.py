#! /usr/bin/env python

## Node to publish a string topic.
import rospy
from ros_pubsub.msg import SensorInformation

def simplePublisher():
    simple_publisher = rospy.Publisher('sensor_info', SensorInformation, queue_size = 10)
    rospy.init_node('sensor_info_publisher', anonymous = False)
    rate = rospy.Rate(10)
    
    # create a SensorInformation object
    sensor_info = SensorInformation()
    sensor_info.maker_name = "SR-05"
    sensor_info.part_number = 7623
    # The string to be published on the topic.
    topic1_content = "my first ROS topic"
    
    while not rospy.is_shutdown():
    	simple_publisher.publish(sensor_info)
	rospy.loginfo('Done')
        rate.sleep()
        
if __name__== '__main__':
    try:
        simplePublisher()
    except rospy.ROSInterruptException:
        pass

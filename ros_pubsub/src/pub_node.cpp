/*
 * sub_node.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: mody
 */


#include "ros/ros.h"
#include "hrwros_msgs/custom_msg.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Pub_node");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<hrwros_msgs::custom_msg>("message", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
	hrwros_msgs::custom_msg msg;
	msg.A = 1;
	msg.B = 2;
	msg.C = 3;
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

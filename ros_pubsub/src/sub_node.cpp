#include "ros/ros.h"
#include "hrwros_msgs/custom_msg.h"

void messageCallback(const hrwros_msgs::custom_msg::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d] [%d] [%d]", msg->A , msg->B , msg->C);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("message", 1000, messageCallback);
  ros::spin();
  return 0;
}

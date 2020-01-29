#include "ros/ros.h"
#include "hrwros_msgs/custom_srv.h"

bool add(hrwros_msgs::custom_srv::Request  &req,
		hrwros_msgs::custom_srv::Response &res)
{
  res.sum = req.A + req.B + req.C;
  ROS_INFO("request: A=%d, B=%d C=%d", (int)req.A, (int)req.B, (int)req.C);
  ROS_INFO("sending back response: [%d]", (int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_3_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_3_ints", add);
  ROS_INFO("Ready to add 3 ints.");
  ros::spin();

  return 0;
}

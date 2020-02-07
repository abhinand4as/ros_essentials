#include "ros/ros.h"
#include "octomap_msgs/BoundingBoxQuery.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<octomap_msgs::BoundingBoxQuery>("add_two_ints");
  octomap_msgs::BoundingBoxQuery srv;
  geometry_msgs::Point min;
  geometry_msgs::Point max;
  min.x = 0.25;
  min.y = 0.0;
  min.z = 0.0;
  max.x = 0.15;
  max.y = 0.1;
  max.z = 0.0;
  srv.request.min = min;
  srv.request.max = max;
  if (client.call(srv))
  {
    ROS_INFO("Octomap cleared");
  }
  else
  {
    ROS_ERROR("Failed to call service");
    return 1;
  }

  return 0;
}
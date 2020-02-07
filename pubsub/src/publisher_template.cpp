#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  ros::Publisher string_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Publisher point_pub = n.advertise<geometry_msgs::Point>("point", 1000);

  ros::Rate loop_rate(10); //10 Hz

  while (ros::ok())
  {

    std_msgs::String msg;
    geometry_msgs::Point point;
    

    msg.data = "hello world";
    point.x = 1.0;
    point.y = 3.4;
    point.z = 2.5;

    ROS_INFO("%s", msg.data.c_str());

    string_pub.publish(msg);
    point_pub.publish(point);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}


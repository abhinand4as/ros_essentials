/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2020-2022, Abhinand A S
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Hamburg University nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Authors: Abhinand A S
   Desc:    Template for ROS publisher
*/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "pubsub/MsgTemplate.h"       //custom message type(/devel/include/pubsub/MsgTemplate.h)
#include "geometry_msgs/Pose.h"  
#include <geometry_msgs/PoseStamped.h>                

int main(int argc, char **argv)
{

  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  ros::Publisher string_pub = n.advertise<std_msgs::String>("pubsub/string", 1000);

  ros::Publisher point_pub = n.advertise<geometry_msgs::Point>("pubsub/point", 1000);

  ros::Publisher pose_pub = n.advertise<geometry_msgs::Pose>("pubsub/pose", 1000);

  ros::Publisher posestamped_pub = n.advertise<geometry_msgs::PoseStamped>("pubsub/posestamped", 1000);

  ros::Publisher msg_pub = n.advertise<pubsub::MsgTemplate>("pubsub/msg", 1000);

  ros::Rate loop_rate(10); //10 Hz

  while (ros::ok()) {

    //=== string message ====
    std_msgs::String string;  
    string.data = "hello world";

    //=== point message ====
    geometry_msgs::Point point;
    point.x = 1.0;
    point.y = 3.4;
    point.z = 2.5;

    //=== custom message ====
    pubsub::MsgTemplate msg;
    msg.id = 1;
    msg.data = "custom message: bye";

    //=== pose int message ====
    geometry_msgs::Pose mesh_pose;
    mesh_pose.position.x = 0.5;
    mesh_pose.position.y = 0.0;
    mesh_pose.position.z = 0.202;
    mesh_pose.orientation.w = 1.0;

    //=== posestamped message ====
    geometry_msgs::PoseStamped mesh_posestamped;
    mesh_posestamped.header.frame_id = "world";
    mesh_posestamped.pose.position.x = 0.5;
    mesh_posestamped.pose.position.y = 0.0;
    mesh_posestamped.pose.position.z = 0.202;
    mesh_posestamped.pose.orientation.w = 1.0;

    //=== publish message ====
    string_pub.publish(string);
    point_pub.publish(point);
    msg_pub.publish(msg);
    pose_pub.publish(mesh_pose);
    posestamped_pub.publish(mesh_posestamped);

    ROS_INFO_ONCE("publishing ...");

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}


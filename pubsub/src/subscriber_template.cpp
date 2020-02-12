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
   Desc:    Template for ROS subscriber
*/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

void stringCallback(const std_msgs::String::ConstPtr& msg) {
    
    ROS_INFO("String: [%s]", msg->data.c_str());
    

}

void pointCallback(const geometry_msgs::Point::ConstPtr& point) {

    ROS_INFO_STREAM("Point: x=" << point->x << "\ty=" << point->y << "\tz=" << point->z);    

}

int main(int argc, char **argv)
{
  
    ros::init(argc, argv, "subscriber");

    ros::NodeHandle n;

    ros::Subscriber string_sub = n.subscribe("pubsub/string", 1000, stringCallback);
    ros::Subscriber point_sub = n.subscribe("pubsub/point", 1000, pointCallback);

    ros::spin();

    return 0;
}
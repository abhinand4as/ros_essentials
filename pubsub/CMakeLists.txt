cmake_minimum_required(VERSION 2.8.3)
project(pubsub)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)

## Declare ROS messages and services

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build publisher and subscriber
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(publisher src/publisher_template.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

add_executable(subscriber src/subscriber_template.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})

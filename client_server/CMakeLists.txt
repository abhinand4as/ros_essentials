cmake_minimum_required(VERSION 2.8.3)
project(client_server)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Declare ROS messages and services

## Generate services in the 'srv' folder
add_service_files(
  FILES
  addTwoInts.srv
)



## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(add_two_ints_server src/server_template.cpp)
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})

add_executable(add_two_ints_client src/client_template.cpp)
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})

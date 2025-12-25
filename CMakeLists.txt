cmake_minimum_required(VERSION 3.0.2)
project(sys_time)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_filters
  livox_ros_driver2
)


## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sys_time
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(sys_time_lib
  include/sys_time/sub_and_pub.h
  src/sub_and_pub.cpp
)

# 将src目录下的main.cpp编译成可执行文件
add_executable(main.cpp src/main.cpp)

# 将新库和ros库链接起来
target_link_libraries(sys_time_lib
  ${catkin_LIBRARIES}
)

# 将可执行文件和新库链接起来
target_link_libraries(main.cpp
  sys_time_lib
  ${catkin_LIBRARIES}
)


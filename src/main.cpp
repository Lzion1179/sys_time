#include <ros/ros.h>
#include "sys_time/sub_and_pub.h"

 
int main(int argc, char **argv) {
    ros::init(argc, argv, "node");
    subscriberANDpublisher sp;
    ROS_INFO("main done! ");
    ros::spin();
}

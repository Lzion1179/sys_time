#ifndef SUB_AND_PUB_H
#define SUB_AND_PUB_H
//ros头文件
#include <ros/ros.h>
//时间同步
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>
//传感器消息
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
// 引入 Livox 消息头文件
#include <livox_ros_driver2/CustomMsg.h>
 
class subscriberANDpublisher{
public:
    subscriberANDpublisher();
    //修改回调函数
    void callback(const sensor_msgs::ImageConstPtr &image, const livox_ros_driver2::CustomMsgConstPtr &pointcloud);
 
private:
    ros::NodeHandle nh;
    ros::Publisher camera_pub;
    ros::Publisher lidar_pub;
    message_filters::Subscriber<livox_ros_driver2::CustomMsg> lidar_sub;//雷达订阅
    message_filters::Subscriber<sensor_msgs::Image> camera_sub;//相机订阅
 
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, livox_ros_driver2::CustomMsg> syncpolicy;//时间戳对齐规则
    typedef message_filters::Synchronizer<syncpolicy> Sync;
    boost::shared_ptr<Sync> sync_;//时间同步器
 
};
#endif

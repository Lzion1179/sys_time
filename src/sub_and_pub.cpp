#include "sys_time/sub_and_pub.h"
 
subscriberANDpublisher::subscriberANDpublisher()
{
    // 订阅话题（确保话题名称与你的 rosbag 一致）
    lidar_sub.subscribe(nh, "/livox/lidar", 1);
    camera_sub.subscribe(nh, "/camera/color/image_raw", 1);

    // 实例化同步器
    // 参数 10 是缓冲区大小，可以根据数据频率调整
    sync_.reset(new message_filters::Synchronizer<syncpolicy>(syncpolicy(10), camera_sub, lidar_sub));
    sync_->registerCallback(boost::bind(&subscriberANDpublisher::callback, this, _1, _2));
    camera_pub = nh.advertise<sensor_msgs::Image>("sync/img", 100);
    lidar_pub = nh.advertise<livox_ros_driver2::CustomMsg>("sync/lidar", 100);
}

// 修改回调函数实现
void subscriberANDpublisher::callback(const sensor_msgs::ImageConstPtr& image, const livox_ros_driver2::CustomMsgConstPtr& pointcloud) {
    ROS_INFO("Received synchronized message! Time diff: %f s", 
              image->header.stamp.toSec() - pointcloud->header.stamp.toSec());
    
    // 原样发布同步后的数据
    camera_pub.publish(image);
    lidar_pub.publish(pointcloud);
}
# sys_time
针对使用livox_ros_driver2录制的rosbag提供的相机雷达时间软同步功能包  

## 1. 版本要求
- Ubuntu 20.04 for ROS Noetic

## 2. 安装依赖
### 2.1 克隆Livox ROS Driver 2
```
mkdir -p systime_ws/src
cd systime_ws/src
git clone https://github.com/Livox-SDK/livox_ros_driver2.git
```

### 2.2 Livox-SDK2
#### 2.2.1 依赖
- CMake3.0.0+
- gcc4.8.0+
#### 2.2.2 编译和安装Livox-SDK2
```
cd systime_ws/src
git clone https://github.com/Livox-SDK/Livox-SDK2.git
cd ./Livox-SDK2/
mkdir build
cd build
cmake .. && make -j
sudo make install
```
Tips:移除SDK
```
sudo rm -rf /usr/local/lib/liblivox_lidar_sdk_*
sudo rm -rf /usr/local/include/livox_lidar_*
```
### 2.3 编译Livox ROS Driver2
```
cd /systime_ws/src/livox_ros_driver2
source /opt/ros/noetic/setup.sh
./build.sh ROS1
```
## 3.克隆和编译sys_time
```
cd systime_ws/src
git clone https://github.com/Lzion1179/sys_time.git
cd ..
catkin_make
```
## 4.运行
```
roscore
```
```
rosparam set use_sim_time true
rosbag play xxx.bag --clock
```
```
rosbag record -O synced.bag /sync/img /sync/lidar /livox/imu
```
```
cd /systime_ws
source devel/setup.bash
rosrun sys_time main.cpp
```
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>

void imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    static int count = 0;
    count++;
    if (count % 20 != 0)  // Only process every 20th message
        return;

    // Do something with msg
    ROS_INFO("Received IMU message: orientation x = %f, y = %f, z = %f, w = %f",
        msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w);
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    ROS_INFO("Received odometry message: position x = %f, y = %f, z = %f",
        msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.position.z);
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "odom_imu_listener");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Create a subscriber object
    ros::Subscriber odom_sub = nh.subscribe("odom", 1000, odomCallback);
    ros::Subscriber imu_sub = nh.subscribe("imu/data_raw", 1000, imuCallback);

    // Spin
    ros::spin();

    return 0;
}
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

pcl::visualization::CloudViewer viewer("Cloud Viewer");

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*cloud_msg, *cloud);
    viewer.showCloud(cloud);
}

int main (int argc, char** argv)
{
    ros::init (argc, argv, "cloud_viewer");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/rslidar_points", 1, cloud_cb);

    while (!viewer.wasStopped ())
    {
        ros::spinOnce();
    }

    return 0;
}

cmake_minimum_required(VERSION 2.8.3)
project(my_cloud_viewer)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  pcl_ros
  pcl_conversions
  sensor_msgs
)

find_package(PCL REQUIRED)

catkin_package(
        CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(my_cloud_viewer src/my_cloud_viewer.cpp)
target_link_libraries(my_cloud_viewer ${catkin_LIBRARIES} ${PCL_LIBRARIES})
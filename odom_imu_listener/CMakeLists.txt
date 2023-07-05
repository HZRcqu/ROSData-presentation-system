cmake_minimum_required(VERSION 3.0.2)
project(odom_imu_listener)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES odom_imu_listener
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(odom_imu_listener src/odom_imu_listener.cpp)
target_link_libraries(odom_imu_listener ${catkin_LIBRARIES})
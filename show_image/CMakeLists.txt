cmake_minimum_required(VERSION 2.8.3)
project(show_image)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  cv_bridge
  image_transport
  sensor_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(
        CATKIN_DEPENDS roscpp
)

include_directories(include
        ${catkin_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        )

add_executable(show_image src/show_image.cpp)

target_link_libraries(show_image
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
)
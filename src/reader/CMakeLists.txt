cmake_minimum_required(VERSION 2.8.3)
project(reader)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs

)


catkin_package()


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(listener_node src/listener_node.cpp)
target_link_libraries(listener_node ${catkin_LIBRARIES})


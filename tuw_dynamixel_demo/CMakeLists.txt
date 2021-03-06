cmake_minimum_required(VERSION 3.0.2)
project(tuw_dynamixel_demo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslint
  geometry_msgs
  trajectory_msgs
)

catkin_package()

include_directories(
  ./include/
  ${catkin_INCLUDE_DIRS}
)

# invoke linter
roslint_cpp()

add_library(demo_message_generator
  src/tuw_dynamixel_demo/demo_message_generator.cpp
  src/tuw_dynamixel_demo/demo_message_generator_trajectory.cpp
  src/tuw_dynamixel_demo/demo_message_generator_twist.cpp
)

target_link_libraries(demo_message_generator
  ${catkin_LIBRARIES}
)

add_library(demo_message_publisher
  src/tuw_dynamixel_demo/demo_message_publisher.cpp
)

target_link_libraries(demo_message_publisher
  ${catkin_LIBRAIES}
)

add_executable(demo_message_publisher_node
  src/tuw_dynamixel_demo/demo_message_publisher_node.cpp
)
target_link_libraries(demo_message_publisher_node
  demo_message_generator
  demo_message_publisher
  ${catkin_LIBRARIES}
)

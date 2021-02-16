cmake_minimum_required(VERSION 3.0.2)
project(tuw_dynamixel_demo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  roslint
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
  src/demo_message_generator.cpp
  src/demo_message_generator_joint.cpp
  src/demo_message_generator_wheel.cpp
)
target_link_libraries(demo_message_generator
  ${catkin_LIBRARIES}
)

add_executable(demo_message_publisher
  src/demo_message_publisher.cpp
  src/demo_message_publisher_main.cpp
)
target_link_libraries(demo_message_publisher
        demo_message_generator
        ${catkin_LIBRARIES}
)

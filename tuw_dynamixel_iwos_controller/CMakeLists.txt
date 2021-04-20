cmake_minimum_required(VERSION 3.0.2)
project(tuw_dynamixel_iwos_controller)

find_package(catkin REQUIRED COMPONENTS
  rospy
)

catkin_package()

catkin_python_setup()

include_directories()

catkin_install_python(PROGRAMS
  src/tuw_dynamixel/tuw_dynamixel_iwos_controller
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

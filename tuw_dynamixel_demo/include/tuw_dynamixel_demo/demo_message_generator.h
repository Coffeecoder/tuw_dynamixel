// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_H
#define SRC_MESSAGE_GENERATOR_H

#include <trajectory_msgs/JointTrajectory.h>
#include <yaml-cpp/yaml.h>

namespace tuw_dynamixel
{
class DemoMessageGenerator
{
public:
  virtual trajectory_msgs::JointTrajectory generateDemoMessage(const std::string actuator_name) = 0;
  virtual trajectory_msgs::JointTrajectory generateDemoMessage(const YAML::Node yaml_node) = 0;
private:

};
}

#endif //SRC_MESSAGE_GENERATOR_H

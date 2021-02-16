// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_H
#define SRC_MESSAGE_GENERATOR_H

#include <trajectory_msgs/JointTrajectory.h>
#include <yaml-cpp/yaml.h>
#include <memory>

namespace tuw_dynamixel
{
class DemoMessageGenerator
{
public:
  void set_message_execution_duration_in_seconds(double);
  double get_message_execution_duration_in_seconds();
  virtual std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const std::string actuator_name) = 0;
  virtual std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const YAML::Node yaml_node) = 0;
protected:
  double message_execution_duration_in_seconds;
};
}

#endif //SRC_MESSAGE_GENERATOR_H

// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_JOINT_H
#define SRC_MESSAGE_GENERATOR_JOINT_H

#include "./demo_message_generator.h"

namespace tuw_dynamixel
{
class DemoMessageGeneratorJoint : public DemoMessageGenerator
{
enum class JointMode
{
  movingLeft,
  movingRight,
};
public:
  trajectory_msgs::JointTrajectory generateDemoMessage(const std::string actuator_name);
  trajectory_msgs::JointTrajectory generateDemoMessage(const YAML::Node yaml_node);
protected:
  JointMode joint_mode_;
};
}

#endif //SRC_MESSAGE_GENERATOR_JOINT_H

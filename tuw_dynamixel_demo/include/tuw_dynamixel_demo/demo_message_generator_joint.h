// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_JOINT_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_JOINT_H

#include <cmath>
#include <memory>
#include <string>
#include "./demo_message_generator.h"

namespace tuw_dynamixel
{
class DemoMessageGeneratorJoint : public DemoMessageGenerator
{
enum class JointMode
{
  turningClockwise,
  turningCounterClockwise,
};
public:
  std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const std::string actuator_name);
  std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const YAML::Node yaml_node);
protected:
  JointMode joint_mode_;
private:
  const double ANGLE_RANGE = M_PI * 2.00 * 0.25;
};
}  // namespace tuw_dynamixel

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_JOINT_H

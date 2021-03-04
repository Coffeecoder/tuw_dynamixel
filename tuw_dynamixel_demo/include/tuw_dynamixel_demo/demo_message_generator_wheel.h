// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_WHEEL_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_WHEEL_H

#include "./demo_message_generator.h"
#include <memory>
#include <string>

namespace tuw_dynamixel
{
enum class WheelMode
{
  accelerating,
  decelerating,
};
class DemoMessageGeneratorWheel : public DemoMessageGenerator
{
public:
  std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const std::string actuator_name);
  std::shared_ptr<trajectory_msgs::JointTrajectory> generateDemoMessage(const YAML::Node yaml_node);
private:
  WheelMode wheel_mode_;
};
}  // namespace tuw_dynamixel

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_WHEEL_H

// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_TWIST_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_TWIST_H

#include <memory>
#include <string>
#include <geometry_msgs/Twist.h>
#include "./demo_message_generator.h"

namespace tuw_dynamixel
{
enum class WheelMode
{
  clockwise,
  counterClockwise,
};
class DemoMessageGeneratorTwist : public DemoMessageGenerator
{
public:
  std::shared_ptr<geometry_msgs::Twist> generateDemoMessage(const std::string actuator_name);
  std::shared_ptr<geometry_msgs::Twist> generateDemoMessage(const YAML::Node yaml_node);
private:
  WheelMode wheel_mode_;
};
}  // namespace tuw_dynamixel

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_TWIST_H

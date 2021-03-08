// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include <string>
#include "tuw_dynamixel_demo/demo_message_generator_twist.h"

std::shared_ptr<geometry_msgs::Twist> tuw_dynamixel::DemoMessageGeneratorTwist::generateDemoMessage(
  const std::string actuator_name)
{
  std::shared_ptr<geometry_msgs::Twist> twist_message =
    std::make_shared<geometry_msgs::Twist>();

  int orientation_factor = 0;
  if (wheel_mode_ != WheelMode::clockwise && wheel_mode_ != WheelMode::counterClockwise)
  {
    throw std::runtime_error("invalid state");
  }
  else if (wheel_mode_ == WheelMode::clockwise)
  {
    orientation_factor = -1;
    wheel_mode_ = WheelMode::counterClockwise;
  }
  else if (wheel_mode_ == WheelMode::counterClockwise)
  {
    orientation_factor =  1;
    wheel_mode_ = WheelMode::clockwise;
  }

  twist_message->linear.x = (orientation_factor) * 0.05;
  twist_message->linear.y = 0.00;
  twist_message->linear.z = 0.00;

  twist_message->angular.x = 0.00;
  twist_message->angular.y = 0.00;
  twist_message->angular.z = 0.00;

  return twist_message;
}

std::shared_ptr<geometry_msgs::Twist> tuw_dynamixel::DemoMessageGeneratorTwist::generateDemoMessage(
  const YAML::Node yaml_node)
{
  // TODO(eugen) implement
  return std::make_shared<geometry_msgs::Twist>();
}

// Copyright 2021 Eugen Kaltenegger

#include <cmath>
#include "../include/tuw_dynamixel_demo/demo_message_generator_joint.h"

std::shared_ptr<trajectory_msgs::JointTrajectory> tuw_dynamixel::DemoMessageGeneratorJoint::generateDemoMessage(const std::string actuator_name)
{
  // TODO
  return std::make_shared<trajectory_msgs::JointTrajectory>();
}

std::shared_ptr<trajectory_msgs::JointTrajectory>  tuw_dynamixel::DemoMessageGeneratorJoint::generateDemoMessage(const YAML::Node yaml_node)
{
  // TODO
  return std::make_shared<trajectory_msgs::JointTrajectory>();
}
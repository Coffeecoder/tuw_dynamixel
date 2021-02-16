// Copyright 2021 Eugen Kaltenegger

#include <cmath>
#include "../include/tuw_dynamixel_demo/demo_message_generator_joint.h"

std::shared_ptr<trajectory_msgs::JointTrajectory> tuw_dynamixel::DemoMessageGeneratorJoint::generateDemoMessage(const std::string actuator_name)
{
  std::shared_ptr<trajectory_msgs::JointTrajectory> joint_trajectory = std::make_shared<trajectory_msgs::JointTrajectory>();

  joint_trajectory->joint_names.push_back(actuator_name);

  int direction_modifier = 0;
  if (joint_mode_ == JointMode::movingLeft)
  {
    direction_modifier = 1;
    joint_mode_ = JointMode::movingRight;
  }
  if (joint_mode_ == JointMode::movingRight) {
    direction_modifier = -1;
    joint_mode_ = JointMode::movingLeft;
  }

  for (int i = 0; i < 3; ++i)
  {
    std::shared_ptr<trajectory_msgs::JointTrajectoryPoint> joint_trajectory_point = std::make_shared<trajectory_msgs::JointTrajectoryPoint>();
    joint_trajectory_point->positions.push_back(i * M_PI * direction_modifier * 0.25);
    joint_trajectory_point->time_from_start.fromSec(i);
  }

  return joint_trajectory;
}

std::shared_ptr<trajectory_msgs::JointTrajectory>  tuw_dynamixel::DemoMessageGeneratorJoint::generateDemoMessage(const YAML::Node yaml_node)
{
  // TODO
  return std::make_shared<trajectory_msgs::JointTrajectory>();
}
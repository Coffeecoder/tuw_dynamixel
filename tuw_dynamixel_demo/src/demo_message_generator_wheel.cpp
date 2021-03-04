// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include <string>
#include "../include/tuw_dynamixel_demo/demo_message_generator_wheel.h"

std::shared_ptr<trajectory_msgs::JointTrajectory> tuw_dynamixel::DemoMessageGeneratorWheel::generateDemoMessage(
  const std::string actuator_name)
{
  std::shared_ptr<trajectory_msgs::JointTrajectory> joint_trajectory =
    std::make_shared<trajectory_msgs::JointTrajectory>();

  joint_trajectory->joint_names.push_back(actuator_name);

  int acceleration_factor = 0;
  if (wheel_mode_ == WheelMode::accelerating)
  {
    acceleration_factor = 1;
    wheel_mode_ = WheelMode::decelerating;
  }
  if (wheel_mode_ == WheelMode::decelerating)
  {
    acceleration_factor = -1;
    wheel_mode_ = WheelMode::accelerating;
  }

  std::shared_ptr<trajectory_msgs::JointTrajectoryPoint> joint_trajectory_point_changing =
    std::make_shared<trajectory_msgs::JointTrajectoryPoint>();
  joint_trajectory_point_changing->accelerations.push_back(acceleration_factor * 0.25);
  joint_trajectory_point_changing->time_from_start.fromSec(0);
  joint_trajectory->points.push_back(*joint_trajectory_point_changing);

  std::shared_ptr<trajectory_msgs::JointTrajectoryPoint> joint_trajectory_point_constant =
    std::make_shared<trajectory_msgs::JointTrajectoryPoint>();
  joint_trajectory_point_changing->accelerations.push_back(0.0);
  joint_trajectory_point_changing->time_from_start.fromSec(this->message_execution_duration_in_seconds / 2);
  joint_trajectory->points.push_back(*joint_trajectory_point_constant);

  return joint_trajectory;
}

std::shared_ptr<trajectory_msgs::JointTrajectory> tuw_dynamixel::DemoMessageGeneratorWheel::generateDemoMessage(
  const YAML::Node yaml_node)
{
  // TODO(eugen) implement
  return std::make_shared<trajectory_msgs::JointTrajectory>();
}

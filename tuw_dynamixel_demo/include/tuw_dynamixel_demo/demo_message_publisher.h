// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_H

#include <ros/ros.h>
#include <memory>
#include <string>
#include "./demo_message_generator_trajectory.h"
#include "./demo_message_generator_twist.h"

namespace tuw_dynamixel
{
class DemoMessagePublisher
{
enum class Mode
{
  joint,
  wheel,
};
public:
  void init(
    const ros::NodeHandle& node_handle,
    const std::string& mode,
    const std::string& topic_name,
    const std::string& actuator_name,
    int message_execution_duration);
  void start();
private:
  ros::NodeHandle node_handle_;
  Mode mode_;
  std::string topic_name_;
  std::string actuator_name_;
  int message_execution_duration_;
  std::shared_ptr<tuw_dynamixel::DemoMessageGeneratorTrajectory> message_generator_trajectory_ = NULL;
  std::shared_ptr<tuw_dynamixel::DemoMessageGeneratorTwist> message_generator_twist_ = NULL;
  std::shared_ptr<ros::Publisher> publisher_;
};
}  // namespace tuw_dynamixel

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_H

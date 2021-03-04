// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_NODE_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_NODE_H

#include <ros/ros.h>
#include <memory>
#include <string>
#include "./demo_message_generator_trajectory.h"
#include "./demo_message_generator_twist.h"
#include "./demo_message_publisher.h"

void obtainParameterString(
  const ros::NodeHandle& node_handle,
  const std::string& parameter_name,
  std::string& parameter_field);
void obtainParameterInt(const ros::NodeHandle& node_handle, const std::string& parameter_name, int& parameter_field);

class DemoMessagePublisherNode
{
public:
  void init(
    const ros::NodeHandle &node_handle,
    const std::string& mode,
    const std::string& topic_name,
    const std::string& actuator_name,
    int message_execution_duration);
  void start();
private:
  std::string mode_;
  std::string topic_name_;
  std::string actuator_name_;
  int message_execution_duration_;

  ros::NodeHandle node_handle_;
  std::shared_ptr<tuw_dynamixel::DemoMessageGenerator> generator_;
  std::shared_ptr<tuw_dynamixel::DemoMessagePublisher> publisher_;
};

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_PUBLISHER_NODE_H

// Copyright 2021 Eugen Kaltenegger

#ifndef DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H
#define DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H

#include <ros/ros.h>
#include <memory>
#include "demo_message_generator.h"

namespace tuw_dynamixel
{
class DemoMessagePublisher
{
public:
  ros::NodeHandle node_handle_;
  std::string topic_name_;
  std::string actuator_name_;
  tuw_dynamixel::DemoMessageGenerator& message_generator_;
  void init(
    const ros::NodeHandle& node_handle,
    const std::string& topic_name,
    const std::string& actuator_name,
    const tuw_dynamixel::DemoMessageGenerator& demo_message_generator);
  void start();
private:
  std::shared_ptr<ros::Publisher> publisher;
};
}

#endif //DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H

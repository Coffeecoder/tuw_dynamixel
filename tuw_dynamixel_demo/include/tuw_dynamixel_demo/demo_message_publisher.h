// Copyright 2021 Eugen Kaltenegger

#ifndef DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H
#define DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H

#include <ros/ros.h>
#include <memory>

namespace tuw_dynamixel
{
class DemoMessagePublisher
{
public:
  void init();
  void start();
private:
  std::shared_ptr<ros::Publisher> publisher;
};
}

#endif //DYNAMIXEL_WS_DEMO_MESSAGE_PUBLISHER_H

// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_H
#define SRC_MESSAGE_GENERATOR_H

#include <trajectory_msgs/JointTrajectory.h>

namespace tuw_dynamixel
{
class DemoMessageGenerator
{
public:
  virtual trajectory_msgs::JointTrajectory generateDemoMessage() = 0;
private:

};
}

#endif //SRC_MESSAGE_GENERATOR_H

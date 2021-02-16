// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_WHEEL_H
#define SRC_MESSAGE_GENERATOR_WHEEL_H

#include "./demo_message_generator.h"

namespace tuw_dynamixel
{
enum class WheelMode
{
  accelerating,
  decelerating,
};
class DemoMessageGeneratorWheel : public DemoMessageGenerator
{
public:
  trajectory_msgs::JointTrajectory generateDemoMessage();
  trajectory_msgs::JointTrajectory generateDemoMessage(const std::string yaml_file_string);
private:
  WheelMode wheel_mode_;
};

}

#endif //SRC_MESSAGE_GENERATOR_WHEEL_H

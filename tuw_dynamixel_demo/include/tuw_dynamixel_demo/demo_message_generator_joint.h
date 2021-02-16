// Copyright 2021 Eugen Kaltenegger

#ifndef SRC_MESSAGE_GENERATOR_JOINT_H
#define SRC_MESSAGE_GENERATOR_JOINT_H

#include "./demo_message_generator.h"

namespace tuw_dynamixel
{
enum class JointMode
{
  movingLeft,
  movingRight,
};

class DemoMessageGeneratorJoint : public DemoMessageGenerator
{
public:
  trajectory_msgs::JointTrajectory generateDemoMessage();
protected:
  JointMode joint_mode_;
};
}

#endif //SRC_MESSAGE_GENERATOR_JOINT_H

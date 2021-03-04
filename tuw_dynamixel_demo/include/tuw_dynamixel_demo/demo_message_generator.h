// Copyright 2021 Eugen Kaltenegger

#ifndef TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_H
#define TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_H

#include <memory>
#include <string>
#include <yaml-cpp/yaml.h>

namespace tuw_dynamixel
{
class DemoMessageGenerator
{
public:
  void set_message_execution_duration_in_seconds(double);
  double get_message_execution_duration_in_seconds();
protected:
  double message_execution_duration_in_seconds;
};
}  // namespace tuw_dynamixel

#endif  // TUW_DYNAMIXEL_DEMO_DEMO_MESSAGE_GENERATOR_H

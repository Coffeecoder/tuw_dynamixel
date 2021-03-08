// Copyright 2021 Eugen Kaltenegger

#include "tuw_dynamixel_demo/demo_message_generator.h"

void tuw_dynamixel::DemoMessageGenerator::set_message_execution_duration_in_seconds(double duration_in_seconds)
{
  this->message_execution_duration_in_seconds = duration_in_seconds;
}

double tuw_dynamixel::DemoMessageGenerator::get_message_execution_duration_in_seconds()
{
  return this->message_execution_duration_in_seconds;
}

// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include <string>
#include "tuw_dynamixel_demo/demo_message_publisher_node.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tuw_dynamixel_demo");
  ros::NodeHandle node_handle;
  ros::NodeHandle param_node_handle("~");
  std::string mode;
  std::string topic_name;
  std::string actuator_name;
  int duration;

  obtainParameterString(param_node_handle, "mode", mode);
  obtainParameterString(param_node_handle, "topic", topic_name);
  obtainParameterString(param_node_handle, "actuator", actuator_name);
  obtainParameterInt(param_node_handle, "duration", duration);

  DemoMessagePublisherNode node;
  node.init(node_handle, mode, topic_name, actuator_name, duration);
  node.start();

  return 0;
}

void obtainParameterString(
  const ros::NodeHandle& node_handle,
  const std::string& parameter_name, std::string& parameter_field)
{
  if (node_handle.getParam(parameter_name, parameter_field))
  {
    ROS_INFO("obtain parameter %s: %s", parameter_name.c_str(), parameter_field.c_str());
  }
  else
  {
    ROS_WARN("failed to obtain parameter %s", parameter_name.c_str());
  }
}

void obtainParameterInt(const ros::NodeHandle& node_handle, const std::string& parameter_name, int& parameter_field)
{
  if (node_handle.getParam(parameter_name, parameter_field))
  {
    ROS_INFO("obtain parameter %s: %d", parameter_name.c_str(), parameter_field);
  }
  else
  {
    ROS_WARN("failed to obtain parameter %s", parameter_name.c_str());
  }
}

void DemoMessagePublisherNode:: init(
    const ros::NodeHandle &node_handle,
    const std::string& mode,
    const std::string& topic_name,
    const std::string& actuator_name,
    int message_execution_duration)
{
  ROS_INFO("creating demo node: ");
  ROS_INFO("  mode: %s", mode.c_str());
  ROS_INFO("  topic: %s", topic_name.c_str());
  ROS_INFO("  actuator: %s", actuator_name.c_str());

  this->node_handle_ = node_handle;
  this->mode_ = mode;
  this->topic_name_ = topic_name;
  this->actuator_name_ = actuator_name;
  this->message_execution_duration_ = message_execution_duration;

  if (this->mode_ == "joint")
  {
    this->generator_ = std::make_shared<tuw_dynamixel::DemoMessageGeneratorTrajectory>();
  }
  if (this->mode_ == "wheel")
  {
    this->generator_ = std::make_shared<tuw_dynamixel::DemoMessageGeneratorTwist>();
  }
  this->generator_->set_message_execution_duration_in_seconds(this->message_execution_duration_);
  this->publisher_ = std::make_shared<tuw_dynamixel::DemoMessagePublisher>();
  this->publisher_->init(
    this->node_handle_,
    this->mode_,
    this->topic_name_,
    this->actuator_name_,
    this->message_execution_duration_);
}

void DemoMessagePublisherNode::start()
{
  this->publisher_->start();
}

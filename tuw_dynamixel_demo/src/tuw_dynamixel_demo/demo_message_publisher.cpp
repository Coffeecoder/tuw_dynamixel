// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include <string>
#include <trajectory_msgs/JointTrajectory.h>
#include "tuw_dynamixel_demo/demo_message_publisher.h"

void tuw_dynamixel::DemoMessagePublisher::init(
    const ros::NodeHandle& node_handle,
    const std::string& mode,
    const std::string& topic_name,
    const std::string& actuator_name,
    int message_execution_duration)
{
  this->node_handle_ = node_handle;
  this->topic_name_ = topic_name;
  this->actuator_name_ = actuator_name;
  this->message_execution_duration_ = message_execution_duration;

  if (mode != "joint" && mode != "wheel")
  {
    throw std::runtime_error("invalid operation " + mode);
  }
  else if (mode == "joint")
  {
    this->mode_ = Mode::joint;
    this->message_generator_trajectory_ = std::make_shared<tuw_dynamixel::DemoMessageGeneratorTrajectory>();
    this->message_generator_trajectory_->set_message_execution_duration_in_seconds(this->message_execution_duration_);

    this->publisher_ = std::make_shared<ros::Publisher>
      (this->node_handle_.advertise<trajectory_msgs::JointTrajectory>(this->topic_name_, 100));
  }
  else if (mode == "wheel")
  {
    this->mode_ = Mode::wheel;
    this->message_generator_twist_ = std::make_shared<tuw_dynamixel::DemoMessageGeneratorTwist>();
    this->message_generator_twist_->set_message_execution_duration_in_seconds(this->message_execution_duration_);

    this->publisher_ = std::make_shared<ros::Publisher>
      (this->node_handle_.advertise<geometry_msgs::Twist>(this->topic_name_, 100));
  }

  for (int loop_counter = 0; this->publisher_->getNumSubscribers() < 1; ++loop_counter)
  {
    if (loop_counter % 100 == 0)
    {
      ROS_INFO("no subscribers for this publisher jet, waiting for subscribers ...");
    }

    ros::Rate loop_rate(100);
    loop_rate.sleep();
  }

}

void tuw_dynamixel::DemoMessagePublisher::start()
{
  ROS_INFO("starting demo publisher (100 messages will be published)");
  int message_counter = 0;
  ros::Rate loop_rate(1.00 / this->message_execution_duration_);
  while (ros::ok() && message_counter < 100)
  {
    ROS_INFO("published %3d demo message", message_counter);

    if (this->mode_ != Mode::joint && this->mode_ != Mode::wheel)
    {
      throw std::runtime_error("invalid operation mode");
    }
    else if (this->mode_ == Mode::joint)
    {
      auto message =
        this->message_generator_trajectory_->generateDemoMessage(this->actuator_name_);
      this->publisher_->publish(*message);
    }
    else if (this->mode_ == Mode::wheel)
    {
      auto message =
        this->message_generator_twist_->generateDemoMessage(this->actuator_name_);
      this->publisher_->publish(*message);
    }

    ros::spinOnce();
    loop_rate.sleep();
    message_counter++;
  }
}

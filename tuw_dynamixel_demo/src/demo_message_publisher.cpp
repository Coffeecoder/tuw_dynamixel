// Copyright 2021 Eugen Kaltenegger

#include <trajectory_msgs/JointTrajectory.h>
#include "../include/tuw_dynamixel_demo/demo_message_publisher.h"

void tuw_dynamixel::DemoMessagePublisher::init(
    const ros::NodeHandle& node_handle,
    const std::string& topic_name,
    const std::string& actuator_name,
    std::shared_ptr<tuw_dynamixel::DemoMessageGenerator> message_generator) {
  this->node_handle_ = node_handle;
  this->topic_name_ = topic_name;
  this->actuator_name_ = actuator_name;
  this->message_generator_ = message_generator;

  this->publisher_ = std::make_shared<ros::Publisher>(this->node_handle_.advertise<trajectory_msgs::JointTrajectory>(this->topic_name_, 100));
}

void tuw_dynamixel::DemoMessagePublisher::start() {
  ROS_INFO("starting demo publisher (100 messages will be published)");
  int message_counter = 0;
  ros::Rate loop_rate(1 / this->message_generator_->get_message_execution_duration_in_seconds());
  while (ros::ok() && message_counter < 100) {
    ROS_INFO("published %3d demo message", message_counter++);
    std::shared_ptr<trajectory_msgs::JointTrajectory> message = this->message_generator_->generateDemoMessage(this->actuator_name_);
    this->publisher_->publish(*message);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

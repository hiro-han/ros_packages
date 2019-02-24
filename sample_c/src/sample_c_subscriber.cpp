#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"

void chatterCallback(const sample_c::sample_message &msg) {
  ROS_INFO("I heard: message = [%s], count = [%d]", msg.message.c_str(), msg.count);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "sample_subscriber");

  ros::NodeHandle n;

  ros::Subscriber subscriber = n.subscribe("sample_topic", 1000, chatterCallback);

  ros::spin();

  return 0;
}

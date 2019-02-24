#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sample_c/sample_message.h"

#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "sample_publisher");

  ros::NodeHandle n;

  ros::Publisher publisher = n.advertise<sample_c::sample_message>("sample_topic", 1000);

  ros::Rate loop_rate(2);

  int count = 0;
  while (ros::ok()) {

    std::stringstream ss;
    ss << "hello world " << count;
    ROS_INFO("message = %s, count = %d", ss.str().c_str(), count);

    sample_c::sample_message msg;

    msg.message = ss.str();
    msg.count = count;

    publisher.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}

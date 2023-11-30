#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "okayestcontroller";

// For Block okayestcontroller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Sub_okayestcontroller_142;

// For Block okayestcontroller/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Sub_okayestcontroller_144;

// For Block okayestcontroller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Pub_okayestcontroller_136;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}


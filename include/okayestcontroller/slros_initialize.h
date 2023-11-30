#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "okayestcontroller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block okayestcontroller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Sub_okayestcontroller_142;

// For Block okayestcontroller/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Sub_okayestcontroller_144;

// For Block okayestcontroller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_okayestcontroller_std_msgs_Float64> Pub_okayestcontroller_136;

void slros_node_init(int argc, char** argv);

#endif

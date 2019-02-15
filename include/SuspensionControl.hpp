#ifndef SUSPENSION_CONTROL_SUSPENSIONCONTROL_HPP
#define SUSPENSION_CONTROL_SUSPENSIONCONTROL_HPP

#include <ros/ros.h>
#include "three_one_msgs/report.h"

namespace suspension_control {

    class SuspensionControl {
    public:
        SuspensionControl();

    private:
        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        ros::Subscriber ecu_sub_;
        void ecuCb(three_one_msgs::report msg);


    };

}

#endif //SUSPENSION_CONTROL_SUSPENSIONCONTROL_HPP
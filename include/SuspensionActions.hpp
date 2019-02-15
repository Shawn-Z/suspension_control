#ifndef SUSPENSION_CONTROL_SUSPENSIONACTIONS_HPP
#define SUSPENSION_CONTROL_SUSPENSIONACTIONS_HPP

#include "three_one_msgs/control_suspension.h"
#include "ThreeOne.hpp"

namespace suspension_control {
    class SuspensionActions {
    public:
        SuspensionActions();
        void suspensionInit();
        void suspensionDamping();
        void suspensionStiff();
        void suspensionKeep();
        void oneLegAct(three_one_control::cylinder_select p_cylinder, three_one_control::suspension_up_down p_act);
        void shaftAct(three_one_control::suspension_select p_shaft, three_one_control::suspension_up_down p_act);
        void upDown(three_one_control::suspension_up_down p_act);
        void roll(three_one_control::suspension_roll p_act);
        void pitch(three_one_control::suspension_pitch p_act);
        void upWall(uint8_t p_step);
        void downWall(uint8_t p_step);
        three_one_msgs::control_suspension suspension;
    };
}

#endif //SUSPENSION_CONTROL_SUSPENSIONACTIONS_HPP

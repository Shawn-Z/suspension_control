#include "SuspensionActions.hpp"

namespace suspension_control {

    SuspensionActions::SuspensionActions() {
        this->suspensionInit();
    }

    void SuspensionActions::suspensionInit() {
        this->suspensionDamping();
    }

    void SuspensionActions::suspensionDamping() {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)three_one_control::suspension_up_down::keep;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::off;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::not_fixed;
    }

    void SuspensionActions::suspensionStiff() {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)three_one_control::suspension_up_down::keep;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::off;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::suspensionKeep() {
        this->suspensionDamping();
    }

    void SuspensionActions::oneLegAct(three_one_control::cylinder_select p_cylinder, three_one_control::suspension_up_down p_act) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)p_cylinder;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)p_act;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::single;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::shaftAct(three_one_control::suspension_select p_shaft, three_one_control::suspension_up_down p_act) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)p_shaft;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)p_act;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::upWall(uint8_t p_step) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = p_step;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)three_one_control::suspension_up_down::keep;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::up_vertical_wall;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::downWall(uint8_t p_step) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = p_step;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)three_one_control::suspension_up_down::keep;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::down_vertical_wall;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::upDown(three_one_control::suspension_up_down p_act) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::up_down;
        this->suspension.suspension_work_mode_detail = (uint8_t)p_act;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::roll(three_one_control::suspension_roll p_act) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::roll;
        this->suspension.suspension_work_mode_detail = (uint8_t)p_act;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }

    void SuspensionActions::pitch(three_one_control::suspension_pitch p_act) {
        this->suspension.priority = 0;
        this->suspension.cylinder_select = (uint8_t)three_one_control::cylinder_select::none;
        this->suspension.suspension_select = (uint8_t)three_one_control::suspension_select::none;
        this->suspension.suspension_work_mode = (uint8_t)three_one_control::suspension_work_mode::pitch;
        this->suspension.suspension_work_mode_detail = (uint8_t)p_act;
        this->suspension.suspension_cylinder_select_mode = (uint8_t)three_one_control::suspension_cylinder_select_mode::all;
        this->suspension.suspension_cylinder_motor_control = (uint8_t)three_one_control::suspension_cylinder_motor_control::on;
        this->suspension.vertical_wall_mode = (uint8_t)three_one_control::vertical_wall_mode::normal_driving;
        this->suspension.fix_two_chamber_valve = (uint8_t)three_one_control::fix_two_chamber_valve::fixed;
    }
}
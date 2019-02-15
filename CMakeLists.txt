cmake_minimum_required(VERSION 2.8.3)
project(suspension_control)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

set(catkin_deps
        roscpp
        three_one_msgs
        )

find_package(catkin REQUIRED
        COMPONENTS
        rosparam_handler
        dynamic_reconfigure
        ${catkin_deps}
        )

# generate_ros_parameter_files(config/ecu_communication.params)

catkin_package(
        INCLUDE_DIRS include
        CATKIN_DEPENDS ${catkin_deps}
        #  CATKIN_DEPENDS other_catkin_pkg
        #  DEPENDS system_lib
)

include_directories(
        include
#        include/shawn
#        test
        ${catkin_INCLUDE_DIRS}
)

add_executable(suspension_control
        #src/SuspensionControl.cpp
        src/SuspensionControl.cpp include/SuspensionControl.hpp src/SuspensionActions.cpp include/SuspensionActions.hpp)

#add_dependencies(suspension_control
##        ${PROJECT_NAME}_gencfg
#        )

target_link_libraries(suspension_control
        ${catkin_LIBRARIES}
        glog
        )
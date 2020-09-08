#ifndef MOVE_H
#define MOVE_H

#include <ros/ros.h>
#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

class Move{
private:
    int init_argc;
    char** init_argv;

    double current_altitude;

    ros::Subscriber position_sub;
    ros::Subscriber attitude_sub;
    ros::Publisher cmd_pub;

public:
    Move(int argc, char** argv);
    void move_to_target_location(double target_latitude, double target_longitude);
    void position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr &msg);
    //일단 먼저 방위각을 따라서 전진하다가 타켓좌표와 current 좌표가 가까우면 멈추게


};


#endif

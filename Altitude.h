#ifndef BEBOP_POINT_TO_POINT_ALTITUDE_H
#define BEBOP_POINT_TO_POINT_ALTITUDE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <math.h>

//원하는 드론의 고도로 이동하기위한 클래스

class Altitude
{
private:
    int init_argc;
    char** init_argv;

    ros::Subscriber altitude_sub;
    ros::Publisher cmd_pub;

    double current_altitude;

public:
    Altitude(int argc, char** argv);
    void move_to_target_altitude(double target_altitude);
    void altitude_callback(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg);
};


#endif //BEBOP_POINT_TO_POINT_ALTITUDE_H

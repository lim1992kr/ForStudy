#ifndef BEBOP_POINT_TO_POINT_BEARING_H
#define BEBOP_POINT_TO_POINT_BEARING_H

#include <ros/ros.h>
#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

//원하는 자세를 바라보게 만들기 위한 함수

class Bearing {

/* 변수
 *  argc, argv
 *  bebop lat / lng
 *  target lat / lng
 *  sub -> bebop lat/lng
 *  sub -> bebop yaw
 *  pub -> bebop cmd_vel
 */
/* fucntion
 * con
 * move_to_target_bearing
 * rad -> degree
 * degree -> rad
 * bebop lat/lng callback
 * bebop yaw callback
 */

private:
    int init_argc;
    char** init_argv;

    ros::Subscriber position_sub;
    ros::Subscriber attitude_sub;
    ros::Publisher cmd_pub;

    double current_latitude;
    double current_longitude;
    double current_yaw;

public:
    Bearing(int argc, char** argv);
    void move_to_target_bearing(double target_latitude, double target_longitude);

    void position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg);
    void attitude_callback(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg);

    double radian_to_degree(double radian);
    double degree_to_radian(double degree);

};


#endif //BEBOP_POINT_TO_POINT_BEARING_H

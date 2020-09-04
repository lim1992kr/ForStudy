#include "Bearing.h"

#define PI 3.14159265

Bearing::Bearing(int argc, char **argv)
{
    this->init_argc = argc;
    this->init_argv = argv;
}

void Bearing::position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr &msg)
{
    this->current_latitude = msg->latitude; //위도 
    this->current_longitude = msg->longitude;   //경도 
}

void Bearing::attitude_callback(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr &msg)
{   
    this->current_yaw = msg->yaw; // yaw값 
}

double Bearing::radian_to_degree(double radian)
{
    return radian * 180 / PI;
}

double Bearing::degree_to_radian(double degree)
{
    return degree * PI / 180;
}

void Bearing::move_to_target_bearing(double target_latitude, double target_longitude)
{
    ros::init(init_argc, init_argv, "move_to_target_bearing_node");
    ros::NodeHandle nh;

    this->position_sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, &Bearing::position_callback, this);
    this->attitude_sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 1, &Bearing::attitude_callback, this);
    this->cmd_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    while(true)
    {
        try
        {
            ros::spinOnce();
        }
        catch (...)
        {
            ROS_ERROR("Spin Error");
        }

        // 두 지점 사이의 방위각을 계산한다.
        double current_latitude_radian = degree_to_radian(this->current_latitude);
        double current_longitude_radian = degree_to_radian(this->current_longitude);
        double target_latitude_radian = degree_to_radian(target_latitude);
        double target_longitude_radian = degree_to_radian(target_longitude);

        double longitudinal_difference_radian = degree_to_radian(target_longitude - this->current_longitude);

        double bearing_between_points_radian = (atan2(sin(longitudinal_difference_radian) * target_latitude_radian, (cos(current_latitude_radian) * sin(target_latitude_radian) - sin(current_latitude_radian) * cos(target_latitude_radian) * cos(longitudinal_difference_radian))));
        double bearing_between_points = radian_to_degree(bearing_between_points_radian);

        // 비밥의 헤드가 있는 방향을 산출하고
        double current_bearing = radian_to_degree(this->current_yaw);
        if(current_bearing < 0)
            current_bearing = 360 - abs(current_bearing);
        // 어디로 회전해야 하느지 판단

        double target_bearing = bearing_between_points;
        if(target_longitude < current_longitude)
            target_bearing = 360 - target_bearing;

        ROS_INFO("target bearing = %f", target_bearing);
        // 목표까지 이동을하고
        // 목표에 도달했으면 정지
    }
}

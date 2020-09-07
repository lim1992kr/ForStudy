#include "move.h"
#include "Altitude.h"
#include "Bearing.h"

Move::Move(int argc, char** argv)
{
    this->init_argc = argc;
    this->init_argv = argv;

}

void Move::position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr &msg)
{   
    this->current_altitude = msg->altitude;
}

void half_tar(double target_latitude, double target_longitude)
{
    double range_lat= (target_latitude - current_latitude())/2;
    double range_log= (target_longitude - current_longitude())/2;


    
}

void Move::move_to_target_location(double target_latitude, double target_longitude)
{
    ros::init(init_argc, init_argv, "move_to_target_location_node");
    ros::NodeHandle nh;

    this->cmd_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    while (ros::ok())
    {
        try
        {
            ros::spinOnce();
        }
        catch (...)
        {
            ROS_ERROR("spin error!");
        }
        //드론이 목표 좌표로 잘 향하고 있는 경우 or 이상한곳으로 가게되는경우.
        
        double current_latitude = get_current_latitude();
        double current_longitude = get_current_longitude();
        target_latitude
        target_longitude

         
        
        target_line()

    }

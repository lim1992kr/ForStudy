#include "move.h"
#include "Altitude.h"
#include "Bearing.h"

#define DEADLINE 0.1

Move::Move(int argc, char** argv)
{
    this->init_argc = argc;
    this->init_argv = argv;

}

void Move::position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr &msg)
{   
    this->current_altitude = msg->altitude;
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
        double distance_latitude = target_latitude - Bearing::current_latitude
        double distance_longitude = target_longitude - Bearing::current_longitude

        if( -DEADLINE< distance_latitude && distance_latitude <DEADLINE || -DEADLINE< distance_longitude && distance_longitude <DEADLINE)
            geometry_msgs::Twist move_msg;
            move_msg.linear.x = move_msg.linear.y = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;
            move_pub.publish(move_msg);   

        } 
        else{    
            geometry_msgs::Twist move_msg;
            move_msg.linear.x = 0.5;
            move_msg.linear.y = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;
            move_pub.publish(move_msg);     
        }
        //드론이 목표 좌표로 잘 향하고 있는 경우 or 이상한곳으로 가게되는경우.
        
     


    }

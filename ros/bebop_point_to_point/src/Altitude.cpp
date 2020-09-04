#include "Altitude.h"

#define DEADLINE 0.1
#define LINEARSPEED 0.3

Altitude::Altitude(int argc, char **argv)//초기화 
{
    this->init_argc = argc;
    this->init_argv = argv;
}

void Altitude::altitude_callback(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr &msg)
{   //토픽으로 받아온 고도값 
    this->current_altitude = msg->altitude;
}

void Altitude::move_to_target_altitude(double target_altitude)//타겟링크로 이동하기
{   
    ros::init(init_argc, init_argv, "move_to_target_altitude_node");
    ros::NodeHandle nh;

    this->altitude_sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AltitudeChanged", 1, &Altitude::altitude_callback, this);
    this->cmd_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    while(ros::ok())
    {
        try
        {
            ros::spinOnce();
        }
        catch (...)
        {
            ROS_ERROR("spin error!");
        }
        // 드론이 상승을 해야하는 경우 or 하강해야 해야 하는 경우 or 정지 하는 경우
        if(target_altitude - this->current_altitude > DEADLINE)
        {
            ROS_INFO("going up : %f", target_altitude - current_altitude);
            geometry_msgs::Twist twist;
            twist.linear.x = twist.linear.y = 0;
            twist.angular.x = twist.angular.y = twist.angular.z = 0;
            twist.linear.z = LINEARSPEED;

            cmd_pub.publish(twist);
        }
        else if(target_altitude - this->current_altitude < -DEADLINE)
        {
            ROS_INFO("going down : %f", target_altitude - current_altitude);
            geometry_msgs::Twist twist;
            twist.linear.x = twist.linear.y = 0;
            twist.angular.x = twist.angular.y = twist.angular.z = 0;
            twist.linear.z = -LINEARSPEED;

            cmd_pub.publish(twist);
        }

        else
        {
            ROS_INFO("stop", target_altitude - current_altitude);
            geometry_msgs::Twist twist;
            twist.linear.x = twist.linear.y = twist.linear.z = 0;
            twist.angular.x = twist.angular.y = twist.angular.z = 0;

            cmd_pub.publish(twist);
            break;
        }
    }
}
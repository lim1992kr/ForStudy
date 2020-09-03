#include "MissionPlanner.h"

#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>

#include <termio.h>
#include <stdio.h>


MissionPlanner::MissionPlanner(int argc, char** argv)
{
    ros::init(argc, argv,"missionplanner");
    nh = new ros::NodeHandle();
    //new c++ 문법 

    takeoff_pub = nh->advertise<std_msgs::Empty>("/bebop/takeoff",1);
    land_pub = nh->advertise<std_msgs::Empty>("/bebop/land",1);
    move_pub = nh->advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);
}

int getch()
{
    int ch;

    struct termios buf,save;
    tcgetattr(0,&save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0,TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

void MissionPlanner::publish()
{
    input_data = getch();   

    if(input_data == 'Q' ||input_data == 'q') 
    {
        std_msgs::Empty msg;
        takeoff_pub.publish(msg);
    }
    else if(input_data == 'Z'||input_data == 'Z')
    {
        std_msgs::Empty msg;
        land_pub.publish(msg);
    }
    else if(input_data == 'w'||input_data == 'W') //w입력 
    {
        geometry_msgs::Twist move_msg;
        
        move_msg.linear.x = 0.5;
        move_msg.linear.y = 0;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;

        move_pub.publish(move_msg);
    }
    else if (input_data == 'x'||input_data == 'X') //x가 눌렸을때 
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = -0.5;
        move_msg.linear.y = move_msg.linear.z = 0;
        move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;
        move_pub.publish(move_msg);
    }
    else if (input_data == 115 && input_data == 107)  //s나 k가 눌렸을때
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = move_msg.linear.y  = move_msg.linear.z = 0;
        move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

        move_pub.publish(move_msg);
    }
    else if (input_data == 'a'||input_data == 'A')  //a가 눌렸을때
    {
        geometry_msgs::Twist move_msg;
        
        move_msg.linear.x = 0;
        move_msg.linear.y = 0.5;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;
        move_pub.publish(move_msg);
    }

    else if (input_data == 'd'||input_data == 'D')  //d가 눌렸을때
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = 0;
        move_msg.linear.y = -0.5;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;
        move_pub.publish(move_msg);
    }

    else if (input_data == 'u'||input_data == 'U')  //u가 눌렸을때
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = 0;
        move_msg.linear.y = 0;
        move_msg.linear.z = 0.5;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;
        move_pub.publish(move_msg);
    }

    else if (input_data == 'm'||input_data == 'M')  //m가 눌렸을때
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = 0;
        move_msg.linear.y = 0;
        move_msg.linear.z = -0.5;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0;
        move_pub.publish(move_msg);
    }

    else if (input_data =='h'||input_data == 'H' )  //h가 눌렸을때
    {
        geometry_msgs::Twist move_msg;

        move_msg.linear.x = 0;
        move_msg.linear.y = 0;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = 0.3;
        move_pub.publish(move_msg);
    }

    else if (input_data == 'k'||input_data == 'K')  //k가 눌렸을때
    {
        geometry_msgs::Twist move_msg;    

        move_msg.linear.x = 0;
        move_msg.linear.y = 0;
        move_msg.linear.z = 0;
        move_msg.angular.x = 0;
        move_msg.angular.y = 0;
        move_msg.angular.z = -0.3;
        move_pub.publish(move_msg);
    }
	
}

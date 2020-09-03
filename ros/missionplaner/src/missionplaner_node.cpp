#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <iostream>
#include <stdio.h>
#include <termio.h> //getcher 구현을 위해서


using std::cout;
using std::endl;

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

void Publisher()
{


    bool is_takeoff = false;
    while(ros::ok())
    {
        int input_data = getch();   
/*
        if(input_data == '32') //space bar입력 
        {
            geometry_msgs::Twist move_msg; 
            if(is_takeoff == false)
            {
                std_msgs::Empty msg;
                takeoff_pub.publish(msg);
                is_takeoff = !is_takeoff;
            }else{
                std_msgs::Empty msg;
                land_pub.publish(msg);
               is_takeoff = !is_takeoff;
            }       
        }
*/		
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
        ros::spinOnce;
        /*
            while(ros::ok)                                      
                for sub in ros::subVector                      
                    if sub.topic.isChanged()
                        sub.callback(sub.topic.value)

                ==
            while(ros::ok)
                ros::spinOnce;
        */ 
	}
}


void position_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr&  msg)
{
    cout << "altitude : " << msg->altitude << endl;
    cout << "latitude : " << msg->latitude << endl;
    cout << "longitude : " << msg->longitude << endl;


//    ROS_INFO("%f",msg->altitude);
//    ROS_INFO("%f",msg->latitude);
//    ROS_INFO("%f",msg->longitude);
}

void altitude_callback(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr&  msg)
{
    cout << "altitude : " << msg->altitude << endl;

//    ROS_INFO("%f",msg->altitude);

}

void attitude_callback(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr&  msg)
{
    cout << "roll : " << msg->roll << endl;
    cout << "pitch : " << msg->pitch << endl;
    cout << "yaw : " << msg->yaw << endl;

//    ROS_INFO("%f",msg->roll);
//    ROS_INFO("%f",msg->pitch);
//    ROS_INFO("%f",msg->yaw);
}



int main(int argc, char** argv)
{   
    ros::init(argc, argv, "missionplaner_node");     //pkg name 
    ros::NodeHandle nh;

    ros::Subscriber positionSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, position_callback);
    
    ros::Subscriber altitudeSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AltitudeChanged", 1, altitude_callback);
    
    ros::Subscriber attitudeSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 1, attitude_callback);
    
    ros::spin();  
	//->Subscriber 를 체크하고 값이 변경되면 콜백함수를 불러와준다. 그외에 많은기능도 있다.  
	//인터럽트 같은거?

	Publisher();


    return 0;
}

/*
//위치정보 topic : /bebop/states/ardrone3/PilotingState/PositionChanged
	type :bebop_msgs/Ardrone3PilotingStatePositionChanged

	# Latitude position in decimal degrees (500.0 if not available)
	float64 latitude
	# Longitude position in decimal degrees (500.0 if not available)
	float64 longitude
	# Altitude in meters (from GPS)
	float64 altitude

//고도정보 topic : /bebop/states/ardrone3/PilotingState/AltitudeChanged 
	type :  bebop_msgs/Ardrone3PilotingStateAltitudeChanged

	# Altitude in meters
	float64 altitude

//방향정보 topic : /bebop/states/ardrone3/PilotingState/AttitudeChanged 
	type : bebop_msgs/Ardrone3PilotingStateAttitudeChanged

	# roll value (in radian)
	float32 roll
	# Pitch value (in radian)
	float32 pitch
	# Yaw value (in radian)
	float32 yaw

/bebop/cmd_vel 
geometry_msgs/Twist
*/
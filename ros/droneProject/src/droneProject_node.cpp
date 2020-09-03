#include <ros/ros.h>
#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <mysql/mysql.h>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

const char* host = "localhost";
const char* user = "root";
const char* pw = "0000";
const char* db = "Chinook";

int counter = 1;

MYSQL* connection = NULL;
MYSQL conn;
MYSQL_ROW sql_row;
MYSQL_RES* sql_result;

void altitude_callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr&  msg)
{
   
   ROS_INFO("%f",msg->altitude);
   ROS_INFO("%f",msg->latitude);
   ROS_INFO("%f",msg->longitude);

    if(connection == NULL) //error
        std::cout << "Connection Error" << mysql_error(&conn) << std::endl;
    else
    {
        std::cout <<"Connection Seccess" << std::endl;

        ostringstream counterString;
        counterString << counter;
        
        ostringstream altitude;
        altitude << msg->altitude;
        
        ostringstream latitude;
        latitude << msg-> latitude; 
        
        ostringstream longitude;
        longitude << msg->longitude;

        string query = "insert into Gps value ( "+ counterString.str() + ", " + altitude.str() + ", "+latitude.str()+","+longitude.str()+")";      //(276,\"BTS\")
        int state = 0;
        state = mysql_query(connection, query.c_str());
        // query.c_str() --> const char* 형을 변환해줘서 사용한다,S
        //str() 
        if(state == 0)
        {
            std::cout << "Secuess" << std::endl;
        }
        else
        {
           std::cout << "Error" << std::endl;
        }   
      
    }
    ROS_INFO("OK!");
}



int main(int argc, char** argv)
{   
    mysql_init(&conn);

    ros::init(argc, argv, "droneProject");
    ros::NodeHandle nh;
    connection = mysql_real_connect(&conn, host, user, pw, db, 3306,(const char*)NULL,0);
    ros::Subscriber sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, altitude_callback);
    
    mysql_close(connection);
    
    ros::spin();

    return 0;
}
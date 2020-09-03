#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H
#include <ros/ros.h>

class MissionPlanner{

private:
    ros::NodeHandle* nh;

    ros::Publisher takeoff_pub;
    ros::Publisher land_pub; 
    ros::Publisher move_pub;

    int input_data; 

public: 
    MissionPlanner(int argc, char** argv);
    void publish();
    //void init();
};

#endif


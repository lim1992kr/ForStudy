#include "MissionPlanner.h"

int main(int argc, char** argv)
{
    MissionPlanner missionPlanner(argc,argv);
    //missionPlanner.init();

    while(1)
    {
        missionPlanner.publish();
    }
    return 0;
}
#include "Altitude.h"
#include "Bearing.h"
#include <iostream>

int main(int argc, char** argv)
{
    double target_altitude = 2; // 고도 
    double target_latitude = 48.8790319;    //위도
    double target_longitude = 2.3680586;    //경도 

    Altitude altitude = Altitude(argc, argv);
    Bearing bearing = Bearing(argc, argv);

    altitude.move_to_target_altitude(target_altitude);
    bearing.move_to_target_bearing(target_latitude,target_longitude);
    

    std::cout <<"finished" << std::endl;

    return 0;
}

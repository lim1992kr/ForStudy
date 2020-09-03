
#include "03_class.h"



Vehicle::Vehicle(int wheelCount)
{
    this->wheelCount = wheelCount;
    this->velocity = 0;
}
string Vehicle::alert(int wheelCount, double velocity)
{
   if(wheelCount == 2 )
        cout << "따르릉" << endl; 
    if(wheelCount == 4 )
        cout << "빵빵" << endl; 
    if(wheelCount == 4 && velocity > 100)
        cout << "삐뽀삐뽀" << endl;         
}
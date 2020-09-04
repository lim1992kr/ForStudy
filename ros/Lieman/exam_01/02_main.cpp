#include <iostream>
#include "03_class.h"


void test001() {
    Vehicle myVehicle = Vehicle(2,150,0.0,0.0);    // myVehicle(wheelCount, velocity, x, y)

    std::cout << myVehicle.wheelCount << std::endl;
    std::cout << myVehicle.velocity << std::endl;
    myVehicle.alert();

   
   
    // myVehicle.alert();

// alert(4, 200) (this === myVehicle)
//  if (4 == 2)
//
//
//
//
//
//
//
//
//   
}
void test002(){
    Vehicle bycycle = Vehicle(2, 25, 0.0, 0.0);
    Vehicle car = Vehicle(4, 150, 1.0, 1.0);

    bycycle.alert();
    car.alert();
    bycycle.location();
    car.location();
}
void test003(int x, int y){
    /*      * * * * * * *
            *           *
            *           *
            *   O       *
            *           *
            * * * * * * * 
    */
    char location[5][5] = {};

    for(int i = 0 ;i < 5; ++i)
        for(int j = 0 ;j < 5; ++j)
            location[i][j] = ' '; 
    location[x-1][y-1] = '0';    

    cout << "*******" << endl;
        for(int i = 0 ;i < 5; ++i){
            cout << '*';
            for(int j = 0 ;j < 5; ++j){
                cout << location[i][j]; 
            }
            cout << '*'<<endl;
        }
    cout << "*******" << endl;
/*
*******
*0    *
*     *
*     *
*     *
*     *
*******
test003(1,1);

*******
* 0   *
*     *
*     *
*     *
*     *
*******
test003(2,1);

*******
*     *
* 0   *
*     *
*     *
*     *
*******
test003(2,2);
*/
}




int main()
{    
    Drone bebop = Drone(2,3);
    while(1){
       
        bebop.display();
        cout << "이동방향을 입력하세요" << endl;
        bebop.move();
    }
    return 0;
}

#include <iostream>
#include "03_class.h"

int main()
{    
    Drone bebop = Drone(2,3,"Dr.Ringo");
    while(1){
       
        bebop.display();
        cout << "이동방향을 입력하세요" << endl;
        bebop.move();
    }
    return 0;
}


#include "03_class.h"



Vehicle::Vehicle(int wheelCount,double velocity, double x, double y)
{
    this->wheelCount = wheelCount;
    this->velocity = velocity;
    this->x = x;
    this->y = y;
}
void Vehicle::alert(/*Vehicle* this, */)
{ 
    if(this->wheelCount == 2)
        std::cout << "따르릉" <<endl;
        
    if(this->wheelCount == 4)
        std::cout << "빵빵" <<endl;  
}
void Vehicle::location()
{
    if(this->wheelCount ==4 &&this->velocity > 120)
     cout << "(" << this->x << "," << this->y << ")" <<endl;     
    else if(this->wheelCount ==2 &&this->velocity > 30)
     cout << "(" << this->x << "," << this->y << ")" <<endl;     
}

Drone::Drone(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Drone::display() 
{
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

void Drone::move()
{
    this->commend = getch();
   
    if (this->commend == 'w' && 'W')
        this->x -= 1; 
    else if (this->commend == 'a' && 'A') 
        this->y -= 1;
    else if (this->commend == 's' && 'S') 
        this->x += 1;
    else if (this->commend == 'd' && 'D') 
        this->y += 1;
}


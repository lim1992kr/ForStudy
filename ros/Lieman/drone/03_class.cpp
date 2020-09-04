#include "03_class.h"

Drone::Drone(int x, int y, string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}
void Drone::display() 
{
    char location[5][5] = {};

    for(int i = 0 ;i < 5; ++i)
        for(int j = 0 ;j < 5; ++j)
            location[i][j] = ' '; 
    location[x-1][y-1] = '0';    

    cout <<  name << endl;
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
int Drone::getch()
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
    this->commend = this->getch();
   
    if (this->commend == 'w' && 'W')
        this->x -= 1; 
    else if (this->commend == 'a' && 'A') 
        this->y -= 1;
    else if (this->commend == 's' && 'S') 
        this->x += 1;
    else if (this->commend == 'd' && 'D') 
        this->y += 1;
}


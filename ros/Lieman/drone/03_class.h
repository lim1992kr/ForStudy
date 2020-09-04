#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <termio.h> //getcher 구현을 위해서

using std::string;
using std::cout;
using std::endl;

class Drone{
public:
    int x;
    int y;        
    char commend;
    string name;

    Drone(int x, int y, string name);
    void move();
    void display(); 
    int getch();
};

#endif
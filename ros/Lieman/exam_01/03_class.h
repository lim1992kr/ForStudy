#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <termio.h> //getcher 구현을 위해서

using std::string;
using std::cout;
using std::endl;

class Vehicle{
public:
    int wheelCount;
    double velocity;
    double x;
    double y; 
  

    Vehicle(int wheelCount,double velocity, double x, double y);
    void alert();
    void location();
};

class Drone{
public:
    int x;
    int y;        
    char commend;

    Drone(int x, int y);
    void move();
    void display(); 
  
};
    int getch(); 
#endif
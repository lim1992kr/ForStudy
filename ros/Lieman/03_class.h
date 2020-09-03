#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Vehicle{
private:
    int wheelCount;
    double velocity;


public:
    Vehicle(int wheelCount);
    string alert(int wheelCount, double velocity);


};

#endif
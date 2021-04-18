#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public :
    int id;
    string name;
    Calculator(double x=0, double y=0);
    ~Calculator();

    double getX();
    
private :
    double _x, _y;
};

#endif
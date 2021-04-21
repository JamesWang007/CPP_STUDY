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
    Calculator(double = 0, double = 0);
    ~Calculator();

    double getX();
    void screen(int, int, int = 3);
    
private :
    double _x, _y;
};

#endif
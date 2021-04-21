#include "Calculator.h"


Calculator::Calculator(double x, double y)
{
    this -> _x = x;
    this -> _y = y;
}

Calculator::~Calculator()
{
}


double Calculator::getX()
{
    return this->_x;
}


void Calculator::screen(int a, int b, int c)
{
    cout << "abc: " << a << endl << b << endl << c << endl;
}

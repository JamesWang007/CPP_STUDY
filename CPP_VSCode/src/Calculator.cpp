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

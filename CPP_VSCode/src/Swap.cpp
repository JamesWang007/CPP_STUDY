#include "Swap.h"

Swap::Swap(int a, int b)
{
    this->_a = a;
    this->_b = b;
}

Swap::~Swap()
{
}


void Swap::run()
{
    int temp;
    temp = _a;
    _a = _b;
    _b = temp;
}

void Swap::printInfo()
{
    cout << " _a = " << _a << endl;
    cout << " _b = " << _b << endl;
}
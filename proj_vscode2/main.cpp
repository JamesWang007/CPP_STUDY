#include "swap.h"
#include <iostream>
using namespace std;

template <typename T>
void do_swap(T&& x, T&& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    Swap swap;
    int a = 10; 
    int b = 20;
    cout << "a = " << a << "; b = " << b << endl;
    swap.do_swap(a, b);
    //do_swap(a, b);
    cout << "a = " << a << "; b = " << b << endl;
    cout << "main" << endl;
    return 0 ;
}
#ifndef FUNCTION_POINTER_H_INCLUDED
#define FUNCTION_POINTER_H_INCLUDED

#include <iostream>

using namespace std;


typedef int (*F_PTR)(int);

int Fabnacci(int n)
{
    return 2*n;
}




void Func()
{
    int N = 3;
    int (*f_ptr1)(int) = Fabnacci;
    cout << f_ptr1(N) << endl;

    F_PTR f_ptr2 = [](int x){ return 2*x; };
    cout << f_ptr2(N) << endl;

    return;
}




#endif // FUNCTION_POINTER_H_INCLUDED

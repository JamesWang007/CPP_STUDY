#ifndef H1_H_INCLUDED
#define H1_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;


void H1()
{
    int pi(3.14);
    int pi2{3.14};
    vector<int> v_num(2, 3);
    vector<int> v_num2{2,3};

    cout << v_num << endl;
    cout << v_num2 << endl;

    cout << "Hello this is H1 function." << endl;
    return ;
}



#endif // H1_H_INCLUDED

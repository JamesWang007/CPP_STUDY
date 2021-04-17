/*
    函数指针
    Lambda 练习
*/

#include <iostream>
#include "h1.h"
#include "FunctionPointer.h"
using namespace std;

class Student{
public :
    string name;
    int id;
    void Greeting();
};

void Student::Greeting()
{
    cout << "Hi! I am " << this->name << endl;
    return;
}

typedef int (*F_PTR) (int);





int main()
{
//    int(*f_ptr)(int);
//
//    Student st1;
//    st1.name = "james";
//    st1.Greeting();
//    int y = 5;
//
//
//
//    auto Mul = [](int x){return 2*x;};  // lambda expression
//    f_ptr = [](int x) {return 2*x;};
//    cout << [&y](int x){y++; return 2*x+y;}(10) << endl;
//    cout << y << endl;
//
    H1();
//
//    cout << "hello world" << endl;

    Func();

    return 0;

}

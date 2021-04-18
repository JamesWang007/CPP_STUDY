#pragma once

#include <iostream>
using namespace std;

class Swap
{
private:
    /* data */
    int _a;
    int _b;

public:
    Swap(int a, int b);
    ~Swap();

    void run();
    void printInfo();
};

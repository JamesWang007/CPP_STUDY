#pragma once
#include <iostream>
using namespace std;

class Swap
{
public:
    Swap() {}
    ~Swap() {}
    template <typename T>
    void do_swap(T &&, T &&);

private:
};
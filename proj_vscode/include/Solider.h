#pragma once
#include <string>
#include "Gun.h"
using namespace std;

class Solider
{
private:
    string _name;
    Gun* _ptr_gun;
public:
    Solider(string name);
    ~Solider();
    void addBulletToGun(int num);
    void fire();

};
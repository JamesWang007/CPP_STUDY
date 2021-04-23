#pragma once
#include <string>
#include <iostream>
using namespace std;

class Gun
{
private:
    string _type;
    int _bullet_count;
public:
    Gun(string type);
    void addBullet(int num);
    void shoot();
};
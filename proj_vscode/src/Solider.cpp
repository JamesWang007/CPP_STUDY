#include "Solider.h"
Solider::Solider(string name) : _name(name)
{
    this->_ptr_gun = new Gun("AK47");
}

Solider::~Solider()
{
    delete (this->_ptr_gun);
}

void Solider::addBulletToGun(int num)
{
    try
    {
        this->_ptr_gun->addBullet(num);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Solider::addBulletToGun exception" << '\n';
        throw e;
    }
}

void Solider::fire()
{
    try
    {
        this->_ptr_gun->shoot();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
}
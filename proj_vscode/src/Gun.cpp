#include "Gun.h"

Gun::Gun(string type) : _type(type), _bullet_count(0)
{
}

void Gun::addBullet(int num)
{
    try
    {
        this->_bullet_count += num;
        if(this->_bullet_count >= 30)
        {
            this->_bullet_count = 30;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "void Gun::addBullet(int num)" << '\n';
        throw e;
    }
    
}

void Gun::shoot()
{
    try
    {
        if (this->_bullet_count > 0)
        {
            this->_bullet_count -= 1;
            cout << "shoot: " << this->_bullet_count << " bullet left." << endl;
        }
        else
        {
            cerr << "void Gun::shoot()" << '\n';
            throw exception();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
    
}
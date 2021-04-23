#include <iostream>
using namespace std;
//#include "STL_TEST.h"
#include "Gun.h"
#include "Solider.h"
#include "utils.h"

int main()
{
    //STL_TEST s1;
    // ShowTime();
    // cout << "hello world" << endl;

    try
    {
        int n = 30;
        int shoot_times = 25;

        Solider s1("Sanduo Xu");
        s1.addBulletToGun(n);
        for (auto i = 0; i < shoot_times; i++)
        {
            s1.fire();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

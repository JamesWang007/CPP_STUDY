#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
#include "Calculator.h"
#include "Swap.h"
#include "utils.h"

void screen(int a, int b, int c=3)
{
    cout << "abc: " << a << b << c << endl;
}

void screen(int= 1, int = 2, int);


int main(int argc, char **argv)
{
    try
    {
        // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
        // for (const string& word : msg)
        // {
        //     cout << word << " ";
        // }
        // cout << endl;


        //Calculator c_obj(1,21);
        // cout << c_obj.getX() << endl;
        //c_obj.screen(4, 5);

        // Swap mySwap(2, 3);
        // mySwap.printInfo();

        // mySwap.run();
        // mySwap.printInfo();

        //screen ();

        // Utils.h
        Func_Utils();
        Func_LRvlaues();
        // system("pause");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


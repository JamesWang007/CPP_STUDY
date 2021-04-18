#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Calculator.h"
#include "Swap.h"

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


        Calculator c_obj(1,21);
        cout << c_obj.getX() << endl;

        Swap mySwap(2, 3);
        mySwap.printInfo();

        mySwap.run();
        mySwap.printInfo();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 

    return 0;
}


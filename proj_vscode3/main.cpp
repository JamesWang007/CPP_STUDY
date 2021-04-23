#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define N 20
/**
 * @brief 
 * some tools
 */
int *rand_int(int num)
{
    int *res_int_arr = new int[num];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < num; i++)
    {
        *(res_int_arr + i) = rand() % 100;
    }
    return res_int_arr;
}

/**
 * @brief 
 * initiate an int array
 */
void rand_init_arr(int arr[], int size)
{
    try
    {
        if (size <= 0)
        {
            throw "size is <= 0";
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " " << endl;
        }
    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void show_vec_val(T &&vec)
{
    try
    {
        for (auto i = vec.begin(); i < vec.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void show_arr_val(T &&arr, int size)
{
    try
    {
        if (size <= 0)
        {
            throw "n is <= 0!";
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * @brief 
 * practise of array
 */
void func_array_pure()
{
    // practise init of array
    int arr1[4] = {1, 2, 3};
    cout << "way 1: ";
    show_arr_val(arr1, 3);

    int *arr2 = new int[N]{1, 2, 3}; // dynamic generation
    show_arr_val(arr2, N);
}

/**
 * @brief 
 * practise of vector
 */
void func_vect()
{
    // generate random numbers
    srand((unsigned)time(nullptr));
    int num = rand() % 20;
    cout << "generate num = " << num << endl;
    vector<double> val(N, 1.0);
    //val.reserve(20);
    cout << "show vector val: ";
    show_vec_val(val);

    int *array = rand_int(num);
    int array2[] = {1, 2, 3};
    vector<double> val2(array, array + num);
    show_vec_val(val2);
    free(array);

    int array3[] = {1, 2, 3};
    std::vector<int> values(array3, array3 + 2); //values 将保存{1,2}
    show_vec_val(values);
    std::vector<int> value1{1, 2, 3, 4, 5};
    show_vec_val(value1);
    std::vector<int> value2(std::begin(value1),
                            std::begin(value1) + 3); //value2保存{1,2,3}
    show_vec_val(value2);
}

void func_vect2()
{
    try
    {
        vector<double> vect(10, 1);

        // for (int i = 0; i < 5; i++)
        // {
        //     vect.push_back(1);
        //     int size = vect.size();
        //     int capacity = vect.capacity();
        //     cout << "size = " << size << endl;
        //     cout << "capacity = " << capacity << endl;
        // }
        // {
        //     vect.shrink_to_fit();
        //     int size = vect.size();
        //     int capacity = vect.capacity();
        //     cout << "size = " << size << endl;
        //     cout << "capacity = " << capacity << endl;
        // }

        {
            vect.assign(4, 10);
            //cout << vect.at(3);
        }
        {
            //vect.erase(vect.begin() + 2);
            vect.emplace(vect.begin() + 2, 3.14);
            vect.front() ++;
            vect.back() ++;
            for(auto &v : vect)
            {
                cout << v << " ";
            }
            cout << endl;
        }

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * @brief 
 * array
 * @return int 
 */
void func_array()
{
    try
    {
        array<string, 5> words{"one","two","three","four","five"};
        cout << get<3>(words) << endl;
        cout << *(words.data() + 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

int main()
{
    cout << "hello world" << endl;
    //func_array_pure();
    //func_vect();
    func_vect2();
    //func_array();
    //system("pause");
    return 0;
}

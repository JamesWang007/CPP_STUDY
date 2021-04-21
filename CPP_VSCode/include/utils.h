#ifndef UTILS
#define UTILS

#include <iostream>
using namespace std;

void Func_Utils()
{
    cout << "Hi! Welcole to use this Utils." << endl;
}


/**
 * @brief 
 * lvalue, rvalue,
 * auto &
 * auto &&
 * 
 * 
 * 
 * 
 * 
 */
void inter_func_test(double &);
void inter_func_test(double & v)      // const allow non_lvalue
{
    cout << v << endl;
};

void inter_func_test(double const & v)      // const allow non_lvalue
{
    cout << v << endl;
};

void Func_LRvlaues()
{
    int a = 0;
    ++a = 3;
    const int *i_ptr = &a;
    // a++;             // okay
    // (*i_ptr)++;      // error, read-only location
    decltype(*i_ptr) x = a;         // lvalue
    decltype(&i_ptr) y = &i_ptr;    // rvalue

    cout << *i_ptr << endl;
    double d_a = 3.14;
    //void inter_func_test(double & v);
    inter_func_test(d_a);   // okay
    //inter_func_test(a);     // error7
    void inter_func_test(double const &);
    inter_func_test( a );    //okay, unless declare inter_func_test(const double & v);
    inter_func_test( 7 );    // okay

    int b = 1;
    i_ptr = &b;
    cout << *i_ptr << endl;

    int * const kI_p = &a; 
    // kI_p = &b; // error, not a lvalue

    int *b_i_ptr = new (int);
    *b_i_ptr = b;
    cout << b_i_ptr << endl;
    free(b_i_ptr);
}

class cs
{
    public:
        cs(int i): i_(i)  { cout << "cs(" << i <<") constructor!" << endl; }
        ~cs() { cout << "cs destructor,i(" << i_ << ")" << endl; }

        cs& operator=(const cs& other)
        {
            i_ = other.i_;
            cout << "cs operator=()" << endl;
            return *this;
        }

        int get_i() const { return i_; }
        void change(int i)  { i_ = i; }

    private:
        int i_;
};

cs get_cs()
{
    static int i = 0;
    return cs(i++);
}

int Func_main()
{
     // 合法
    (get_cs() = cs(2)).change(323);
    get_cs() = cs(2);// operator=()
    get_cs().change(32);

   // cs& ref = get_cs();

    return 0;
}




#endif
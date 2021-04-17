#include <iostream>
using namespace std;

struct MyStruct 
{

	string name; // 默认 公有变量
	int id;
	public : 
		MyStruct() 
		{
			cout << "this is mystruct" << endl;
		}
		
};

void (*pF01)(int);

void aaa()
{
	return;
}

void (*pF02())() // 返回函数指针的函数f
{
	return aaa;
}

void Func01(const int t) 
{
	cout << "this is " << t << endl;
}

void ctrl_c_is_pressed(int signo)
{
	cout << "小朋友，你是否有很多问号？" << endl;
}

// signal就是一个返回函数指针的函数
void(*signal(int signo, void(*func)(int)))(int)
{
	func(signo);
	return func;
}

int main()
{
	pF01 = Func01;

	pF01(10);
	(*pF01)(10);

	MyStruct st1, str_ptr = {};
	st1.name = "james";

	int SIGINT = 1;

	auto ctrl_c_handler = signal(SIGINT, ctrl_c_is_pressed);  // 

	cout << "hello world" << endl;
	
	getchar();
	return 0;
}




#include <iostream>
using namespace std;

struct MyStruct 
{

	string name; // Ĭ�� ���б���
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

void (*pF02())() // ���غ���ָ��ĺ���f
{
	return aaa;
}

void Func01(const int t) 
{
	cout << "this is " << t << endl;
}

void ctrl_c_is_pressed(int signo)
{
	cout << "С���ѣ����Ƿ��кܶ��ʺţ�" << endl;
}

// signal����һ�����غ���ָ��ĺ���
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




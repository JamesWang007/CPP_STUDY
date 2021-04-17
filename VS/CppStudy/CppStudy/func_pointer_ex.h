#pragma once
#include <iostream>
using namespace std;

typedef int(*F_PTR) (int);

int Fabnacci(int n)
{
	return 2 * n;
}

void FuncPtrRun()
{
	int N = 3;
	int(*f_ptr1)(int) = Fabnacci;
	cout << f_ptr1(N) << endl;

	F_PTR f_ptr2 = [](int x) { 
		int a,b;  
		
		return 2 * x; 
	};

	cout << f_ptr2(N) << endl;
	return;
}




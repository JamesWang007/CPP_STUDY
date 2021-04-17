#pragma once
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;



void FuncIniRun()
{
	int pi(3.14);
	int pi2(3.1415);
	vector<int> v_num(4, 3);
	vector<int> v_num2{ 2, 3 };

	for (auto i = 0 ; i < v_num.size(); i ++)
	{
		cout << v_num[i] << " ";
	}
	cout << endl;

	for (auto it = v_num2.begin(); it < v_num2.end(); it++)
	{
		cout << (*it);
	}
	cout << endl;
	cout << "hello this is FuncIniRun" << endl;
	return;
}
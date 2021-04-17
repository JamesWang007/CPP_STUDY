#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fun(LPVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
		cout << "A Thread Fun Display!" << endl;
	return 0L;
}

int FuncMulThread()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
		cout << "Main Thread Display!" << endl;
	return 0;
}

int FuncMulThread2()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
	{
		cout << "Main Thread Display!" << endl;
		Sleep(500);
	}

	return 0;
}


int FuncMulThread3()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
	{
		//cout << "Main Thread Display!" << endl;
		cout << "Main Thread Display!\n";
		Sleep(500);
	}

	return 0;
}


HANDLE hMutex = NULL;//互斥量
int FuncMulThread4()
{
	//创建一个子线程
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, "screen");
	//关闭线程句柄
	CloseHandle(hThread);
	//主线程的执行路径
	for (int i = 0; i < 10; i++)
	{
		//请求获得一个互斥量锁
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Main Thread Display!" << endl;
		Sleep(100);
		//释放互斥量锁
		ReleaseMutex(hMutex);
	}
	return 0;
}
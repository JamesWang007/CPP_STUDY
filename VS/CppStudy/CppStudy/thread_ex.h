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


HANDLE hMutex = NULL;//������
int FuncMulThread4()
{
	//����һ�����߳�
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, "screen");
	//�ر��߳̾��
	CloseHandle(hThread);
	//���̵߳�ִ��·��
	for (int i = 0; i < 10; i++)
	{
		//������һ����������
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Main Thread Display!" << endl;
		Sleep(100);
		//�ͷŻ�������
		ReleaseMutex(hMutex);
	}
	return 0;
}
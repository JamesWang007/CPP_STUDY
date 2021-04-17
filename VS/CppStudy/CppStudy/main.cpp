#include <iostream>
using namespace std;
#include "func_pointer_ex.h"
#include "initializer_ex.h"
#include "thread_ex.h"
#include "StlAlgorithmPractise.h"

void FuncCurrentInfo()
{
	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
	return;
}

int main()
{

	//FuncIniRun();			////initializer_ex.h
	//FuncPtrRun();			//func_pointer_ex.h
	//FuncCurrentInfo();		
	//FuncMulThread();		//thread_ex.h
	//FuncMulThread2();		//thread_ex.h
	//FuncMulThread3();		//thread_ex.h
	//FuncMulThread4();		//thread_ex.h

	/* region : STL Algorithm practise */
	StlAlgorithmPractise sap_obj;
	sap_obj.TestRun();

	StlAlgorithmPractise const kSap_obj;
	kSap_obj.getData();

	/* end region */
	

	/* class practise*/
	/* end region*/

	getchar();
	return 0;
}


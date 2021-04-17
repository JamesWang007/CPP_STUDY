#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#ifndef N
#define N 10
#endif

class StlAlgorithmPractise
{
private:
	mutable char *data;
	mutable char* _name = new char[N] {"James"};
	unsigned _id = 1234;
	

public:
	StlAlgorithmPractise();
	~StlAlgorithmPractise();
	
	char *getData() const;
	void setName(const char* name) ;
	int getId();
	void setId(unsigned int id);
	void TestRun();
	const int kVar = 12;
};




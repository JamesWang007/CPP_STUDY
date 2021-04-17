#include "StlAlgorithmPractise.h"



StlAlgorithmPractise::StlAlgorithmPractise() 
{
	this->data = new char[N]{ "data" };
}


StlAlgorithmPractise::~StlAlgorithmPractise()
{
	delete (this->data);
}


char *StlAlgorithmPractise::getData() const {
	strcpy_s(this->data, N, "abcd");
	return this->data;
}


void StlAlgorithmPractise::setName(const char* name) 
{
	strcpy_s(this->_name, N, name);
}


int StlAlgorithmPractise::getId()
{
	return this->_id;
}


void StlAlgorithmPractise::setId(unsigned int id) 
{
	this->_id = id;
}


void StlAlgorithmPractise::TestRun()
{
	this->setName("hai");
	cout << getData() << endl;
	char *c_str = new char[N] {"c_string"};
	string s = c_str;
	cout << s << endl;
}


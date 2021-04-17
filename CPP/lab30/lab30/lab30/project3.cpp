#include "activity.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Student
{
private:
	int studentId;
	string studentName;
public:
	Student(int i1, string s1)
	{
		studentId = i1;
		studentName = s1;
	}
	string getName()
	{
		return studentName;
	}
};



class Course
{
private:
	string courseName;
	int numUnits;
	vector<Student> vs;
public:
	Course(string s1, int i1)
	{
		courseName = s1;
		numUnits = i1;
	}
	int getUnits()
	{
		return numUnits;
	}
	string getCourseName() {
		return courseName;
	}
	vector<Student>* getvs()
	{
		return &vs;
	}
};



int main()
{
	int option, numUnits, studentId;
	string courseName, studentName;
	vector<Course> courselist;
	vector<Student> studentlist;

	while (true)
	{
		cout << "1) Add a new course" << endl;
		cout << "2) Add a new student" << endl;
		cout << "3) Display all the courses" << endl;
		cout << "4) Display all the students within a course" << endl;
		cout << "5) Remove a course (Project 4 will implement this feature)" << endl;
		cout << "6) Remove a student within a course (Project 4 will implement this feature)" << endl;
		cout << "7) Exit" << endl;
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			cout << "Enter the new course name." << endl;
			getline(cin, courseName);

			bool is_exist = false;
			for (int i = 0; i < courselist.size(); i++)
			{
				if (courselist[i].getCourseName() == courseName)
				{
					cout << "Course already exists!" << endl;
					is_exist = true;
					break;
				}
			}
			if (is_exist)
			{
				break;
			}

			for (vector<Course>::iterator it = courselist.begin(); it < courselist.end(); it++)
			{
				if (it->getCourseName() == courseName)
				{
					is_exist = true;
				}
			}

			cout << "Enter the number of units." << endl;
			cin >> numUnits;
			cin.ignore();


			Course course(courseName, numUnits);
			courselist.push_back(course);
		}
		else if (option == 2)
		{
			cout << "Enter the course name." << endl;
			getline(cin, courseName);

			int index_course = -1;
			for (int i = 0; i < courselist.size(); i++)
			{
				if (courselist[i].getCourseName() == courseName)
				{
					index_course = i;
				}
			}
			if (index_course < 0)
			{
				cout << "No such a course!" << endl;
				continue;
			}

			cout << "Enter the students ID #." << endl;
			cin >> studentId;
			cin.ignore();
			cout << "Enter the students name." << endl;
			getline(cin, studentName);

			bool is_exist = false;
			for (int i = 0; i < studentlist.size(); i++)
			{
				if (studentlist[i].getName() == studentName)
				{
					cout << "Student name already exists!" << endl;
					is_exist = true;
					break;
				}
			}
			if (is_exist)
			{
				continue;
			}

			Student student(studentId, studentName);
			studentlist.push_back(student);

			courselist[index_course].getvs()->push_back(student); 

			cout << "Adding student" << endl;
		}
		else if (option == 3)
		{
			for (int i = 0; i < courselist.size(); i++)
			{
				cout << courselist[i].getCourseName() << endl;
			}
		}
		else if (option == 4)
		{
			cout << "Enter the course name." << endl;
			getline(cin, courseName);
			int index_course = -1;
			for (int i = 0; i < courselist.size(); i++)
			{
				if (courselist[i].getCourseName() == courseName)
				{
					index_course = i;
				}
			}
			if (index_course < 0)
			{
				cout << "No such a course!" << endl;
				continue;
			}
			for (int i = 0; i < courselist[index_course].getvs()->size(); i++)
			{
				cout << (*(courselist[index_course].getvs()))[i].getName() << endl;
			}
		}
		else if (option == 7)
		{
			break;
		}
		
	}

	return 0;
}



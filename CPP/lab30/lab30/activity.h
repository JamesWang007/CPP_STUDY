#include <iostream>
#include <vector>
#include <string>
#using namespace std;

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
};

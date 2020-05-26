#include "Student.h"
#include <iostream>
Student::Student(int _fn, const char* _program, int _group, int _year, const char* _name)
{
	fn = fn;
	program = new char[strlen(_program) + 1];
	strcpy(program,_program);
	group = _group;
	year = _year;
	name = new char[strlen(_name) + 1];
	strcpy(name,_name);
	status = 'E';
	averageGrade = 2;
	enrolledCapacity = 4;
	enrolledCurrent = 0;
	gradedCapacity = 4;
	gradedCurrent = 0;

	//Course** enrolledCourses; // Всички записани дисциплини на студента на които не е положил изпит
	//Course** gradedCourses;
}

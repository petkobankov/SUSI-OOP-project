#include "Student.h"
#include <iostream>
Student::Student(int _fn, const char* _program, int _group, int _year, const char* _name)
{
	fn = _fn;
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
	enrolledCourses = new Course * [enrolledCapacity];
	for (int i = 0; i < enrolledCapacity; i++) {
		enrolledCourses[i] = nullptr;
	}
	gradedCourses = new Course * [gradedCapacity];
	for (int i = 0; i < gradedCapacity; i++) {
		gradedCourses[i] = nullptr;
	}
}

int Student::getFn() const
{
	return fn;
}

bool Student::advance()
{
	if (year >= 4)
		return false;
	year++;
	return true;
}

bool Student::changeGroup(int _group)
{
	group = group;
	return true;
}

bool Student::changeYear(int _year)
{
	if (_year != year + 1)
		return false;

	return true;
}

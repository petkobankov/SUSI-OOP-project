#pragma once
#include "Student.h"
#include "Course.h"
#include "Program.h"
class SusiController {
	int studentsCapacity;
	int studentsCurrent;
	Student** students;
	int findStudentByFn(int _fn)const;
public:
	SusiController();
	bool enroll(int _fn, const char* _program, int _group, const char* _name);
	bool advance(int _fn);
	bool change(int _fn, const char* option, const char* value);
	
};

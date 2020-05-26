#pragma once
#include "Student.h"
#include "Course.h"
#include "Program.h"
class SusiController {
	int studentsCapacity;
	int studentsCurrent;
	Student** students;
public:
	SusiController();
	bool enroll(int _fn, const char* _program, int _group, const char* _name);
};

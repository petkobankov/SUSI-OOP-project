#pragma once
#include "Student.h"
#include "Course.h"
#include "Program.h"
class SusiController {
	int studentsCapacity;
	int studentsCurrent;
	Student** students;
	int programsCapacity;
	int programsCurrent;
	Program** programs;
	bool changeProgram(int _fn, const char* _newProgram);
	int findStudentByFn(int _fn)const;
	int findProgramByName(const char* programName)const;
public:
	SusiController();
	bool enroll(int _fn, const char* _program, int _group, const char* _name);
	bool advance(int _fn);
	bool change(int _fn, const char* option, const char* value);
	bool graduate(int _fn);
	bool interrupt(int _fn);
	bool resume(int _fn);
	bool print(int _fn);
	bool printall(const char* programName, int _year);
	bool enrollin(int fn, const char* course);
	bool addgrade(int _fn, const char* _course, double _grade);
	bool protocol(const char* course)const;
	bool report(int _fn)const;
};

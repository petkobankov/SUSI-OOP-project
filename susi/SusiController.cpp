#include "SusiController.h"
#include <cstring>
#include <iostream>
int SusiController::findStudentByFn(int _fn) const
{
	int id = -1;
	for (int i = 0; i < studentsCurrent; i++) {
		if (students[i]->getFn() == _fn)
			id = i;
	}
	return id;
}

bool SusiController::enroll(int _fn, const char* _program, int _group, const char* _name)
{
	if (studentsCurrent == studentsCapacity)
		;//resizeStudents();
	students[studentsCurrent++] = new Student(_fn,_program,_group,1,_name);
	return true;
}

bool SusiController::advance(int _fn)
{
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->advance();
}

bool SusiController::change(int _fn, const char* option, const char* value)
{
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	if (strcmp(option, "group") == 0)
		return students[id]->changeGroup(atoi(value));
	if (strcmp(option, "program") == 0)
		return students[id]->changeProgram(value);
	if (strcmp(option, "year") == 0)
		return students[id]->changeYear(atoi(value));
	return false;
}

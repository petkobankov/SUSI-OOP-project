#include "SusiController.h"
#include <cstring>
#include <iostream>
bool SusiController::changeProgram(int _fn, const char* _newProgram)
{
	int id = findProgramByName(_newProgram);
	if (id < 0)
		return false;

	for (int i = 0; i < programsCurrent; i++) {

	}
	return true;
}
int SusiController::findStudentByFn(int _fn) const
{
	for (int i = 0; i < studentsCurrent; i++) {
		if (students[i]->getFn() == _fn)
			return i;
	}
	return -1;
}

int SusiController::findProgramByName(const char* programName) const
{
	for (int i = 0; i < programsCurrent; i++) {
		if (programs[i]->hasTheSameName(programName))
			return i;
	}
	return -1;
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
		return changeProgram(_fn,value);
	if (strcmp(option, "year") == 0)
		return students[id]->changeYear(atoi(value));
	return false;
}

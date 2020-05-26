#include "SusiController.h"

bool SusiController::enroll(int _fn, const char* _program, int _group, const char* _name)
{
	if (studentsCurrent == studentsCapacity)
		;//resizeStudents();
	students[studentsCurrent++] = new Student(_fn,_program,_group,1,_name);
	return true;
}

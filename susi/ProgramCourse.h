#pragma once
#include "Course.h"
class ProgramCourse: public Course {
	int listCapacity;
	int listCurrent;
	int* listOfEnrolled;
public:
	bool addFn(int _fn);
	bool protocol()const;
};
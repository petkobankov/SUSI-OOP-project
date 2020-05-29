#pragma once
#include "Course.h"
class ProgramCourse: public Course {
	int listCapacity;
	int listCurrent;
	int* listOfEnrolled;

	void free();
	void copyFrom(const ProgramCourse& other);
public:
	ProgramCourse();
	ProgramCourse(const ProgramCourse& other);
	ProgramCourse& operator=(const ProgramCourse& other);
	~ProgramCourse();

	ProgramCourse(const char* _name, bool _isMandatory, int neededYear);
	bool addFn(int _fn);
	bool protocol()const;
};
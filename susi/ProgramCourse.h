#pragma once
#include "Course.h"
class ProgramCourse: public Course {
	int listCapacity;
	int listCurrent;
	int* listOfEnrolled;
	bool resizeList();

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

	int getListCapacity()const;
	int getListCurrent()const;
	const int* getListOfEnrolled()const;
};
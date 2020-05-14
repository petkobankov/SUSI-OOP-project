#pragma once
#include "Course.h"
class Grade {
	double grade;
	Course* gradedCourse;
	static double sumOfGrades;
	static int count;
public:
	Grade();
};
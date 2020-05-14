#pragma once
#include "Course.h";
#include "Grade.h"
class EnrolledCourse : public Course {
	Grade* grade;
};
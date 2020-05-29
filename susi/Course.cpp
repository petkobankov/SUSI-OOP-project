#include "Course.h"
#include <cstring>
#include <iostream>
bool Course::isMandatory() const
{
	return mandatory;
}

const char* Course::getName() const
{
	return name;
}

int Course::getNeededYear() const
{
	return neededYear;
}

bool Course::hasTheSameName(const char* _name) const
{
	if (strcmp(name, _name) == 0)
		return true;
	return false;
}

bool Course::setGrade(double _grade)
{
	if (_grade < 2 || _grade >6)
		return false;
	grade = _grade;
	return true;
}

bool Course::print() const
{
	std::cout << name << ", grade: " << grade << std::endl;
	return true;
}

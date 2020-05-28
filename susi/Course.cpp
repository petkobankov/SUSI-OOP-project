#include "Course.h"
#include <cstring>
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

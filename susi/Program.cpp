#include "Program.h"

bool Program::hasTheSameName(const char* _name) const
{
	if (strcmp(name, _name) == 0)
		return true;
	return false;
}

const char** Program::listOfCourseNames(int _year,int& _limit) const
{
	char** coursesList = new char* [coursesCurrent];
	int counter = 0;
	int id = 0;
	while (counter < coursesCurrent) {
		if (courses[counter]->getNeededYear() <= _year) {
			coursesList[id] = new char[strlen(courses[counter]->getName()) + 1];
			strcpy(coursesList[id], courses[counter]->getName());
			id++;
		}
		counter++;
	}
	_limit = id;
	return coursesList;
}

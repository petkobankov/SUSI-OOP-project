#include "Program.h"
#include <iostream>

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
	return (const char**)coursesList;
}

bool Program::enrollStudent(const char* _courseName, int _fn)
{
	for (int i = 0; i < coursesCurrent; i++) {
		if (courses[i]->hasTheSameName(_courseName))
			return courses[i]->addFn(_fn);
	}
	return false;
}

bool Program::protocol(const char* _courseName) const
{
	for (int i = 0; i < coursesCurrent; i++) {
		if (courses[i]->hasTheSameName(_courseName)) {
			std::cout << "For program: " << name << std::endl;
			return courses[i]->protocol();
		}
	}
	return false;
}

const Course& Program::getCourseByName(const char* _courseName)
{
	//Търси дали има курс с такова име в специалността, ако не дава грешка, ако да връща референция 
	for (int i = 0; i < coursesCurrent; i++) {
		if (courses[i]->hasTheSameName(_courseName)) 
			return *courses[i];
	}
	throw false;
}

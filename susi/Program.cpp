#include "Program.h"
#include <iostream>

void Program::free()
{
	delete[] name;
	for (int i = 0; i < coursesCapacity; i++) {
		delete courses[i];
	}
	delete[] courses;
}

void Program::copyFrom(const Program& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	coursesCapacity = other.coursesCapacity;
	coursesCurrent = other.coursesCurrent;
	courses = new ProgramCourse*[coursesCapacity];
	for (int i = 0; i < coursesCapacity; i++) {
		if (other.courses[i] == nullptr)
			courses[i] = nullptr;
		else
			courses[i] = new ProgramCourse(*other.courses[i]);
	}
}

bool Program::resizeCourse()
{
	ProgramCourse** tempCourses = new ProgramCourse * [coursesCapacity*=2];
	for (int i = 0; i < coursesCapacity; i++) {
		tempCourses[i] = nullptr;
	}
	for (int i = 0; i < coursesCurrent; i++) {
		tempCourses[i] = courses[i];
	}
	delete[] courses;
	courses = tempCourses;
	return true;
}

Program::Program()
{
	name = new char[1];
	name[0] = '\0';
	coursesCapacity = 4;
	coursesCurrent = 0;
	courses = new ProgramCourse * [coursesCapacity];
	for (int i = 0; i < coursesCapacity; i++) {
		courses[i] = nullptr;
	}
}

Program::Program(const Program& other)
{
	copyFrom(other);
}

Program& Program::operator=(const Program& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Program::~Program()
{
	free();
}

Program::Program(const char* _name)
{
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
	coursesCapacity = 4;
	coursesCurrent = 0;
	courses = new ProgramCourse * [coursesCapacity];
	for (int i = 0; i < coursesCapacity; i++) {
		courses[i] = nullptr;
	}
}

bool Program::addCourse(const char* _courseName, bool _isMandatory, int neededYear)
{
	if (coursesCapacity == coursesCurrent)
		resizeCourse();
	courses[coursesCurrent++] = new ProgramCourse(_courseName, _isMandatory, neededYear);
	return true;
}

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

const char* Program::getName() const
{
	return name;
}

int Program::getCoursesCapacity() const
{
	return coursesCapacity;
}

int Program::getCoursesCurrent() const
{
	return coursesCurrent;
}

int Program::getListCapacity(int _id) const
{
	if (_id < coursesCurrent)
		return -1;
	return courses[_id]->getListCapacity();
}

int Program::getListCurrent(int _id) const
{
	if (_id < coursesCurrent)
		return -1;
	return courses[_id]->getListCurrent();
}

const int* Program::getListOfEnrolled(int _id) const
{
	if (_id < coursesCurrent)
		return nullptr;
	return courses[_id]->getListOfEnrolled();
}

bool Program::save(std::ofstream& outfile)
{
	int nameLen = strlen(name);
	outfile.write((const char*)&nameLen, sizeof(int));
	outfile.write((const char*)name, nameLen);
	outfile.write((const char*)&coursesCapacity, sizeof(int));
	outfile.write((const char*)&coursesCurrent, sizeof(int));
	for (int i = 0; i < coursesCurrent; i++) {
		courses[i]->save(outfile);
	}
	return true;
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

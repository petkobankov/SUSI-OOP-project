#include "Course.h"
#include <cstring>
#include <iostream>
void Course::free()
{
	delete[] name;
}
void Course::copyFrom(const Course& other)
{
	mandatory = other.mandatory;
	neededYear = other.neededYear;
	grade = other.grade;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
Course::Course()
{
	mandatory = true;
	neededYear = 1;
	grade = 2;
	name = new char[1];
	name[0] = '\0';
}
Course::Course(const Course& other)
{
	copyFrom(other);
}
Course& Course::operator=(const Course& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Course::~Course()
{
	free();
}
Course::Course(const char* _name, bool _isMandatory, int _neededYear, double _grade)
{
	mandatory = _isMandatory;
	neededYear = _neededYear;
	grade = _grade;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}
Course::Course(const char* _name, bool _isMandatory, int _neededYear)
{
	mandatory = _isMandatory;
	neededYear = _neededYear;
	grade = 2;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}
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

double Course::getGrade()
{
	return grade;
}

bool Course::print() const
{
	std::cout << name << ", grade: " << grade << std::endl;
	return true;
}

bool Course::save(std::ofstream& outfile)
{
	int nameLen = strlen(name);
	outfile.write((const char*)&nameLen, sizeof(int));
	outfile.write((const char*)name, nameLen);
	outfile.write((const char*)&mandatory, sizeof(bool));
	outfile.write((const char*)&neededYear, sizeof(int));
	outfile.write((const char*)&grade, sizeof(double));
	return true;
}

bool Course::open(std::ifstream& infile)
{
	free();
	int nameLen;
	infile.read((char*)&nameLen, sizeof(int));
	name = new char[nameLen + 1];
	char* _name = new char[nameLen + 1];
	infile.read(_name, nameLen);
	_name[nameLen] = '\0';
	strcpy(name, _name);
	infile.read((char*)&mandatory, sizeof(bool));
	infile.read((char*)&neededYear, sizeof(int));
	infile.read((char*)&grade, sizeof(double));
	return true;
}

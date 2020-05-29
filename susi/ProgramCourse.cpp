#include "ProgramCourse.h"
#include <iostream>

void ProgramCourse::free()
{
	delete[] listOfEnrolled;
}

void ProgramCourse::copyFrom(const ProgramCourse& other)
{
	listCapacity = other.listCapacity;
	listCurrent = other.listCurrent;
	listOfEnrolled = new int[listCapacity];
	for (int i = 0; i < listCapacity; i++) {
		listOfEnrolled[i] = other.listOfEnrolled[i];
	}
}

ProgramCourse::ProgramCourse(): Course()
{
	listCapacity = 4;
	listCurrent = 0;
	listOfEnrolled = new int[listCapacity];
	for (int i = 0; i < listCapacity; i++) {
		listOfEnrolled[i] = -1;
	}
}

ProgramCourse::ProgramCourse(const ProgramCourse& other)
{
	copyFrom(other);
}

ProgramCourse& ProgramCourse::operator=(const ProgramCourse& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ProgramCourse::~ProgramCourse()
{
	free();
}

ProgramCourse::ProgramCourse(const char* _name, bool _isMandatory, int _neededYear): Course(_name,_isMandatory,_neededYear)
{
}

bool ProgramCourse::addFn(int _fn)
{
	//������ � ������� ��� �������� �������� ����������� ����� �� ��� �������. ������ �� ����, �� �� ������������ �� �� ��������� � ��������� ��� ���� �� ����� �� � ����� ����������� �� ���������.
	if (listCurrent == listCapacity)
		;//resizeList();
	if (listCurrent == 0) {
		listOfEnrolled[listCurrent++] = _fn;
		return true;
	}
	for (int i = listCurrent-1; i >=0; i--) {
		if (_fn > listOfEnrolled[i]) {
			listOfEnrolled[i + 1] = _fn;
			listCurrent++;
			return true;
		}
		else {
			listOfEnrolled[i + 1] = listOfEnrolled[i];
		}
	}
	listOfEnrolled[0] = _fn;
	listCurrent++;
	return true;
}

bool ProgramCourse::protocol() const
{
	for (int i = 0; i < listCurrent; i++) {
		if(i!= listCurrent-1)
			std::cout << listOfEnrolled[i] << ", ";
		else
			std::cout << listOfEnrolled[i] << std::endl;
	}
	return true;
}

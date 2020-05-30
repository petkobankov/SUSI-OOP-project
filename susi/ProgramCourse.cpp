#include "ProgramCourse.h"
#include <iostream>

bool ProgramCourse::resizeList()
{
	int* tempList = new int [listCapacity *= 2];
	for (int i = 0; i < listCapacity; i++) {
		tempList[i] = -1;
	}
	for (int i = 0; i < listCurrent; i++) {
		tempList[i] = listOfEnrolled[i];
	}
	delete[] listOfEnrolled;
	listOfEnrolled = tempList;
	return true;
}

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
	listCapacity = 4;
	listCurrent = 0;
	listOfEnrolled = new int[listCapacity];
	for (int i = 0; i < listCapacity; i++) {
		listOfEnrolled[i] = -1;
	}
}

bool ProgramCourse::addFn(int _fn)
{
	//Добавя в списъка със записани студенти факултетния номер на нов студент. Добавя се така, че по подразбиране да са подредени в нарастващ ред така че после да е лесно извеждането на протоколи.
	if (listCurrent == listCapacity)
		resizeList();
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

int ProgramCourse::getListCapacity() const
{
	return listCapacity;
}

int ProgramCourse::getListCurrent() const
{
	return listCurrent;
}

const int* ProgramCourse::getListOfEnrolled() const
{
	return listOfEnrolled;
}

bool ProgramCourse::save(std::ofstream& outfile)
{
	Course::save(outfile);
	outfile.write((const char*)&listCapacity, sizeof(int));
	outfile.write((const char*)&listCurrent, sizeof(int));
	for (int i = 0; i < listCurrent; i++) {
		outfile.write((const char*)&listOfEnrolled[i], sizeof(int));
	}
	return true;
}

bool ProgramCourse::open(std::ifstream& infile)
{
	Course::open(infile);
	free();
	infile.read((char*)&listCapacity, sizeof(int));
	infile.read((char*)&listCurrent, sizeof(int));
	int sizeOfList = listCapacity * sizeof(int);
	listOfEnrolled=new int[listCapacity];
	for (int i = 0; i < listCapacity; i++) {
		listOfEnrolled[i] = -1;
	}
	for (int i = 0; i < listCurrent; i++) {
		infile.read((char*)&listOfEnrolled[i], sizeof(int));
	}

	return true;
}

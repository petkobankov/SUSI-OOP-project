#include "Student.h"
#include <iostream>
using namespace std;
void Student::free()
{
	delete[] name;
	delete[] program;
	for (int i = 0; i < enrolledCapacity; i++) {
		delete currentCourses[i];
	}
	delete[] currentCourses;
	for (int i = 0; i < gradedCapacity; i++) {
		delete gradedCourses[i];
	}
	delete[] gradedCourses;

}
void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	isGradauted = other.isGradauted;
	isInterrupted = other.isInterrupted;
	fn = other.fn;
	group = other.group;
	year = other.year;
	program = new char[strlen(other.program) + 1];
	strcpy(program,other.program);
	averageGrade = other.averageGrade;
	enrolledCapacity = other.enrolledCapacity;
	enrolledCurrent = other.enrolledCurrent;
	gradedCapacity = other.gradedCapacity;
	gradedCurrent = other.gradedCurrent;
	currentCourses = new Course * [enrolledCapacity];
	for (int i = 0; i < enrolledCapacity; i++) {
		if (other.currentCourses[i] == nullptr)
			currentCourses[i] = nullptr;
		else
			currentCourses[i] = new Course(*other.currentCourses[i]);
	}
	gradedCourses = new Course * [gradedCapacity];
	for (int i = 0; i < gradedCapacity; i++) {
		if (other.gradedCourses[i] == nullptr)
			gradedCourses[i] = nullptr;
		else
			gradedCourses[i] = new Course(*other.gradedCourses[i]);
	}

}
bool Student::updateAverageGrade()
{
	double sum = 0;
	int count = enrolledCurrent+gradedCurrent;
	for (int i = 0; i < gradedCurrent; i++) {
		sum += gradedCourses[i]->getGrade();
	}
	for (int i = 0; i < enrolledCurrent; i++) {
		sum += currentCourses[i]->getGrade();
	}
	averageGrade = sum / count;
	return true;
}
bool Student::resizeEnrolled()
{
	Course** tempCourses = new Course * [enrolledCapacity*=2];
	for (int i = 0; i < enrolledCapacity; i++) {
		tempCourses[i] = nullptr;
	}
	for (int i = 0; i < enrolledCurrent; i++) {
		tempCourses[i] = currentCourses[i];
	}
	delete[] currentCourses;
	currentCourses = tempCourses;
	return true;
}
bool Student::resizeGraded()
{
	Course** tempCourses = new Course * [gradedCapacity*=2];
	for (int i = 0; i < gradedCapacity; i++) {
		tempCourses[i] = nullptr;
	}
	for (int i = 0; i < gradedCurrent; i++) {
		tempCourses[i] = gradedCourses[i];
	}
	delete[] gradedCourses;
	gradedCourses = tempCourses;
	return true;
}
Student::Student()
{
	fn = -1;
	isGradauted = false;
	isInterrupted = false;
	program = new char[1];
	program[0] = '\0';
	group = -1;
	year = -1;
	name = new char[1];
	name[0] = '\0';
	averageGrade = 2;
	enrolledCapacity = 4;
	enrolledCurrent = 0;
	gradedCapacity = 4;
	gradedCurrent = 0;
	currentCourses = new Course * [enrolledCapacity];
	for (int i = 0; i < enrolledCapacity; i++) {
		currentCourses[i] = nullptr;
	}
	gradedCourses = new Course * [gradedCapacity];
	for (int i = 0; i < gradedCapacity; i++) {
		gradedCourses[i] = nullptr;
	}
}
Student::Student(const Student& other)
{
	copyFrom(other);
}
Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Student::~Student()
{
	free();
}
Student::Student(int _fn, const char* _program, int _group, int _year, const char* _name)
{
	fn = _fn;
	isGradauted = false;
	isInterrupted = false;
	program = new char[strlen(_program) + 1];
	strcpy(program,_program);
	group = _group;
	year = _year;
	name = new char[strlen(_name) + 1];
	strcpy(name,_name);
	averageGrade = 2;
	enrolledCapacity = 4;
	enrolledCurrent = 0;
	gradedCapacity = 4;
	gradedCurrent = 0;
	currentCourses = new Course * [enrolledCapacity];
	for (int i = 0; i < enrolledCapacity; i++) {
		currentCourses[i] = nullptr;
	}
	gradedCourses = new Course * [gradedCapacity];
	for (int i = 0; i < gradedCapacity; i++) {
		gradedCourses[i] = nullptr;
	}
}

int Student::getFn() const
{
	return fn;
}

bool Student::advance()
{
	//Студента продължава следващия курс
	return changeYear(year+1);
}

bool Student::changeGroup(int _group)
{
	//Сменя групата на студента
	if (isInterrupted)
		return false;
	group = _group;
	return true;
}

bool Student::changeYear(int _year)
{
	if (isInterrupted)
		return false;
	if (_year != year + 1)
		return false;
	int counter = 0;
	for (int i = 0; i < enrolledCurrent; i++) {
		if (currentCourses[i]->isMandatory())
			counter++;
	}
	if (counter > 2)
		return false;
	if (year >= 4)
		return false;
	year++;
	return true;
}

int Student::getStudentYear() const
{
	return year;
}

bool Student::graduate()
{
	//Отбелязва студента като завършил
	if (isInterrupted)
		return false;
	if (isGradauted)
		return true;
	if (enrolledCurrent != 0)
		return false;
	isGradauted = true;
	return true;
}

bool Student::interrupt()
{
	isInterrupted = true;
	return true;
}

bool Student::resume()
{
	isInterrupted = false;
	return true;
}

bool Student::print() const
{
	cout << "Information for student \"" << name << "\"" << endl;
	if (isGradauted)
		cout << "He has graduated" << endl;
	else
		cout << "He hasn't graduated" << endl;
	if (isInterrupted)
		cout << "He has interrupted" << endl;
	else
		cout << "He hasn't interrupted" << endl;
	cout << "Fn, group, year and program are as follows: " << fn << ", " << group << ", " << year << ", " << program << endl;
	cout << "Average grade so far: " << averageGrade << endl;
	return true;
}

bool Student::isForProgramYear(const char* _programName, int _year) const
{
	if (strcmp(program, _programName) != 0)
		return false;
	if (year != _year)
		return false;
	return true;
}

const char* Student::getProgram() const
{
	return program;
}

bool Student::enrollin(const Course& _courseForEnroll)
{
	if (_courseForEnroll.getNeededYear() > year)
		return false;
	if (enrolledCapacity == enrolledCurrent)
		resizeEnrolled();
	currentCourses[enrolledCurrent++] = new Course(_courseForEnroll);
	updateAverageGrade();
	return true;
}

bool Student::addgrade(const char* _course, double _grade)
{
	for (int i = 0; i < enrolledCurrent; i++) {
		if (currentCourses[i]->hasTheSameName(_course)) {
			if (!currentCourses[i]->setGrade(_grade))
				return false;
			updateAverageGrade();
			if (_grade < 3) //Ако оценката е под 3 няма да местим курса при успешно оценените
				return true;
			if (gradedCapacity == gradedCurrent) 
				resizeGraded();
			gradedCourses[gradedCurrent++] = currentCourses[i]; //оценката е >= 3 затова я местим при масива с оценени

			for (int j = i; j < enrolledCurrent - 1; j++) { //и я махаме от масива за текущи курсове
				currentCourses[i] = currentCourses[j + 1];
			}
			currentCourses[enrolledCurrent - 1] = nullptr;
			enrolledCurrent--;
			return true;
		}
	}
	return false;
}

bool Student::report() const
{
	cout << "Successful courses: " << endl;
	for (int i = 0; i < gradedCurrent; i++) {
		gradedCourses[i]->print();
	}
	cout << endl;
	cout << "Unsuccessful courses: " << endl;
	for (int i = 0; i < enrolledCurrent; i++) {
		currentCourses[i]->print();
	}
	cout << endl;
	cout << "Student overall grade: " << averageGrade << endl;
	return true;
}


bool Student::changeProgram(const char** _courseList, int _limit, const char* _newProgramName)
{
	//Сменя специалността на студента ако е минал всички изпити за специалността, която иска да бъде
	if (isInterrupted)
		return false;
	for (int i = 0; i < enrolledCurrent; i++) {
		for (int j = 0; j < _limit; j++) {
			if (currentCourses[i]->hasTheSameName(_courseList[j]))
				return false;
		}
	}
	delete[] program;
	program = new char[strlen(_newProgramName) + 1];
	strcpy(program, _newProgramName);
	return true;
}

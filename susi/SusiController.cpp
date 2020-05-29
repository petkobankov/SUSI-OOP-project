#include "SusiController.h"
#include <cstring>
#include <iostream>
bool SusiController::changeProgram(int _fn, const char* _newProgram)
{
	//Помощна функция която взима имената на учебните дисцпилини, които са за курса който е студента или за по-малки курсове и ги праща на обекта студент който ще използва инфомрацията да сфери дали може да се прехвърли
	int studentId = findStudentByFn(_fn);
	int programId = findProgramByName(_newProgram);
	if (programId < 0)
		return false;
	int limit=-1;
	int studentYear = students[studentId]->getStudentYear();
	students[studentId]->changeProgram(
		programs[programId]->listOfCourseNames(studentYear,limit),
		limit,
		_newProgram
		);
}
int SusiController::findStudentByFn(int _fn) const
{
	//Помощна функция за намиране на номер на студент в масива със студенти с даден факултетен номер
	for (int i = 0; i < studentsCurrent; i++) {
		if (students[i]->getFn() == _fn)
			return i;
	}
	return -1;
}

int SusiController::findProgramByName(const char* programName) const
{
	//Помощна функция за намиране на специалност по име
	for (int i = 0; i < programsCurrent; i++) {
		if (programs[i]->hasTheSameName(programName))
			return i;
	}
	return -1;
}

bool SusiController::enroll(int _fn, const char* _program, int _group, const char* _name)
{
	//Записване на нов студент в университета
	if (studentsCurrent == studentsCapacity)
		;//resizeStudents();
	students[studentsCurrent++] = new Student(_fn,_program,_group,1,_name);
	return true;
}

bool SusiController::advance(int _fn)
{
	//Записва студента в следващ курс
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->advance();
}

bool SusiController::change(int _fn, const char* option, const char* value)
{
	//Прехвърля студента с даден факултетен номер в нова специялност/група/курс
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	if (strcmp(option, "group") == 0)
		return students[id]->changeGroup(atoi(value));
	if (strcmp(option, "program") == 0)
		return changeProgram(_fn,value);
	if (strcmp(option, "year") == 0)
		return students[id]->changeYear(atoi(value));
	return false;
}

bool SusiController::graduate(int _fn)
{
	//Ако съществува такъв студент извикваме функцията му за завършване
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->graduate();
}

bool SusiController::interrupt(int _fn)
{
	//Маркира студент като прекъснал
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->interrupt();
}

bool SusiController::resume(int _fn)
{
	//Маха маркировката като прекъснал
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->resume();
}

bool SusiController::print(int _fn)
{
	//Извежда справка за студент
	int id = findStudentByFn(_fn);
	if (id < 0)
		return false;
	return students[id]->print();
}

bool SusiController::printall(const char* _programName, int _year)
{
	for (int i = 0; i < studentsCurrent; i++) {
		if (students[i]->isForProgramYear(_programName, _year))
			students[i]->print();
	}
	return true;
}

bool SusiController::enrollin(int _fn, const char* _courseName)
{
	int studentId = findStudentByFn(_fn);
	if (studentId < 0)
		return false;
	const char* studentProgram = students[studentId]->getProgram();
	int programId = findProgramByName(studentProgram);
	if (programId < 0)
		return false;
	try{
	const Course & foundCourse = programs[programId]->getCourseByName(_courseName);
	if (!programs[programId]->enrollStudent(_courseName, _fn))
		return false;
	return students[studentId]->enrollin(foundCourse);
	}
	catch (bool error) {
		return error;
	}
	return true;
}

bool SusiController::addgrade(int _fn, const char* _course, double _grade)
{
	int studentId = findStudentByFn(_fn);
	if (studentId < 0)
		return false;
	return students[studentId]->addgrade(_course, _grade);
}

bool SusiController::protocol(const char* _course) const
{
	for (int i = 0; i < programsCurrent; i++) {
		programs[i]->protocol(_course);
	}
	return true;
}

bool SusiController::report(int _fn) const
{
	int studentId = findStudentByFn(_fn);
	if (studentId < 0)
		return false;
	return students[studentId]->report();
}

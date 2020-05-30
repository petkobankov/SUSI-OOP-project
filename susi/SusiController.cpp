#include "SusiController.h"
#include <cstring>
#include <iostream>
#include <fstream>
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

bool SusiController::resizeStudents()
{
	Student** tempStudents = new Student * [studentsCapacity*=2];
	for (int i = 0; i < studentsCapacity; i++) {
		tempStudents[i] = nullptr;
	}
	for (int i = 0; i < studentsCurrent; i++) {
		tempStudents[i] = students[i];
	}
	delete[] students;
	students = tempStudents;
	return true;
}

bool SusiController::resizePrograms()
{
	Program** tempPrograms = new Program * [programsCapacity*=2];
	for (int i = 0; i < programsCapacity; i++) {
		tempPrograms[i] = nullptr;
	}
	for (int i = 0; i < programsCurrent; i++) {
		tempPrograms[i] = programs[i];
	}
	delete[] programs;
	programs = tempPrograms;
	return true;
}

void SusiController::free()
{
	for (int i = 0; i < studentsCapacity; i++) {
		delete students[i];
	}
	delete[] students;
	for (int i = 0; i < programsCapacity; i++) {
		delete programs[i];
	}
	delete[] programs;
	delete[] location;
}

void SusiController::copyFrom(const SusiController& other)
{
	studentsCapacity = other.studentsCapacity;
	studentsCurrent = other.studentsCurrent;
	students = new Student * [studentsCapacity];
	for (int i = 0; i < studentsCapacity; i++) {
		if (other.students[i] == nullptr)
			students[i] = nullptr;
		else
			students[i] = new Student(*other.students[i]);
	}
	programsCapacity = other.programsCapacity;
	programsCurrent = other.programsCurrent;
	programs = new Program * [programsCapacity];
	for (int i = 0; i < programsCapacity; i++) {
		if (other.programs[i] == nullptr)
			programs[i] = nullptr;
		else
			programs[i] = new Program(*other.programs[i]);
	}
}

const char* SusiController::getFileName(const char* _location) const
{
	char* temp = new char[strlen(_location) + 1];
	strcpy(temp, _location);
	char* fileName = strrchr(temp, '\\');
	if (fileName == nullptr)
		throw "Error reading file";
	if (strrchr(fileName+1, '\"') != nullptr) {
		fileName[strlen(fileName) - 1] = '\0';
	}
	return fileName+1;
}

SusiController::SusiController()
{
	studentsCapacity = 4;
	studentsCurrent = 0;
	students = new Student * [studentsCapacity];
	for (int i = 0; i < studentsCapacity; i++) {
		students[i] = nullptr;
	}
	programsCapacity = 4;
	programsCurrent = 0;
	programs = new Program * [programsCapacity];
	for (int i = 0; i < programsCapacity; i++) {
		programs[i] = nullptr;
	}
	location = new char[1];
	location[0] = '\0';
}

SusiController::SusiController(const SusiController& other)
{
	copyFrom(other);
}

SusiController& SusiController::operator=(const SusiController& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

SusiController::~SusiController()
{
	free();
}

bool SusiController::enroll(int _fn, const char* _program, int _group, const char* _name)
{
	//Записване на нов студент в университета
	if (studentsCurrent == studentsCapacity)
		resizeStudents();
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
	if (!students[studentId]->enrollin(foundCourse))
		return false;
	return programs[programId]->enrollStudent(_courseName, _fn);
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

bool SusiController::addProgram(const char* _name)
{
	if (programsCapacity == programsCurrent)
		resizePrograms();
	programs[programsCurrent++] = new Program(_name);
	return true;
}

bool SusiController::addCourseForProgram(const char* _programName,const char* _courseName, bool _isMandatory, int _neededYear)
{
	int programId = findProgramByName(_programName);
	if (programId < 0)
		return false;
	return programs[programId]->addCourse(_courseName,_isMandatory, _neededYear);
}

bool SusiController::saveas(const char* _location)
{
	delete[] location;
	location = new char[strlen(_location) + 1];
	strcpy(location, _location);
	const char* fileName = getFileName(_location);
	std::ofstream outfile(_location,std::ios::out|std::ios::binary|std::ios::trunc);
	
	outfile.write((const char*)&programsCapacity, sizeof(int));
	outfile.write((const char*)&programsCurrent, sizeof(int));
	outfile.write((const char*)&studentsCapacity, sizeof(int));
	outfile.write((const char*)&studentsCurrent, sizeof(int));
	for (int i = 0; i < programsCurrent; i++) {
		programs[i]->save(outfile);
	}
	for (int i = 0; i < studentsCurrent; i++) {
		students[i]->save(outfile);
	}
	outfile.close();
	std::cout << "Successfully saved " << fileName << std::endl;
	return true;
}

bool SusiController::open(const char* _location)
{
	delete[] location;
	location = new char[strlen(_location) + 1];
	strcpy(location, _location);
	const char* fileName = getFileName(_location);
	std::cout << "Successfully opened " << fileName << std::endl;
	return true;
}

bool SusiController::close()
{
	if (!isLoaded())
		throw "No file is opened!";
	const char* fileName = getFileName(location);
	std::cout << "Successfully closed " << fileName << std::endl;
	delete[] location;
	location = new char[1];
	location[0] = '\0';
	
	return true;
}

bool SusiController::save()
{
	if (!isLoaded())
		throw "No file is opened!";
	return saveas(location);
}

const bool SusiController::isLoaded() const
{
	return (bool)location[0];
}

bool SusiController::help()const
{
	using namespace std;
	cout << "The following commands are supported: " << endl;
	cout << "open <file>" << "    " << "opens <file>" << endl;
	cout << "close" << "    " << "closes currently opened file" << endl;
	cout << "save" << "    " << "saves the currently open file" << endl;
	cout << "saveas <file>" << "    " << "saves the currently open file in <file>" << endl;
	cout << "help" << "    " << "prints this information" << endl;
	cout << "exit" << "    " << "exists the program" << endl;
	cout << "enroll <fn><program><group><name>" << "    " << "enrolls student with name <name> in first year in program <program> in group <group> and with faculty number <fn>" << endl;
	cout << "advance <fn>" << "    " << "takes the student to the next year" << endl;
	cout << "change <fn><option><value>" << "    " << "<option> can be either 'program', 'group' or 'year'. Transfers student with faculty number <fn> in a new program, group or year specified with <value>" << endl;
	cout << "graduate <fn>" << "    " << "marks the student with faculty number <fn> as graduated" << endl;
	cout << "interrupt <fn>" << "    " << "marks the student with faculty number <fn> as interrupted. Interrupted students can't take exams, enrol in courses or change program, group or year" << endl;
	cout << "resume <fn>" << "    " << "restores student rights to the student with faculty number <fn>" << endl;
	cout << "print <fn>" << "    " << "prints out a reference for the student with faculty number <fn>" << endl;
	cout << "printall <program><year>" << "    " << "prints out a reference for all students in program <program> and year <year>" << endl;
	cout << "enrollin <fn><course>" << "    " << "enrolls the student with faculty number <fn> in course <course>" << endl;
	cout << "addgrade <fn><course><grade>" << "    " << "Adds a grade <grade> in course <course> for student with faculty number <fn>. You can only add a grade if a student is enrolled in that course." << endl;
	cout << "protocol <course>" << "    " << "Prints out all the faculty numbers of students enrolled for course <course>. There is a different protocol for each program." << endl;
	cout << "report <fn>" << "    " << "Prints out academic reference for grades of student with faculty number <fn>" << endl;
	cout << "addprogram <program>" << "    " << "Adds a program <program> in the system" << endl;
	cout << "addcourse <program><course><mandatory><year>" << "    " << "Adds a course <course> for program <program> which can be either mandatory or not <mandatory> (true/false) for year <year>" << endl;
	return true;
}

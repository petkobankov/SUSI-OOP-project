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
	return students[studentId]->changeProgram(
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
	Student** tempStudents = new Student * [studentsCapacity *= 2];
	for (int i = 0; i < studentsCapacity; i++) {
		if(i>=studentsCurrent)
			tempStudents[i] = nullptr;
		else 
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
	for (int i = 0; i < programsCapacity; i++) {
		delete programs[i];
	}
	delete[] programs;
	for (int i = 0; i < studentsCapacity; i++) {
		delete students[i];
	}
	delete[] students;
	
	
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
	int locationLen = strlen(_location);
	if (locationLen < 2)
		throw "Error reading file";
	char* temp = new char[strlen(_location) + 1];
	strcpy(temp, _location);
	char* fileName = strrchr(temp, '\\');
	if (fileName == nullptr)
		return _location;
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
	delete[] location;
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
	
	int locationLen = strlen(_location);
	char* tempLocation = new char[locationLen + 1];
	strcpy(tempLocation, _location);
	if (tempLocation[0] == '\"') {
		for (int i = 0; i < locationLen; i++) {
			tempLocation[i] = tempLocation[i + 1];
		}
		locationLen--;
		if(tempLocation[locationLen-1]=='\"')
			locationLen--;
	}
		 
	tempLocation[locationLen] = '\0';
	delete[] location;
	location = tempLocation;
	const char* fileName = getFileName(location);
	std::ofstream outfile(location,std::ios::out|std::ios::binary);

	if (!outfile.is_open()){
		outfile.close();
		throw "Error saving file";
	}
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
	int locationLen = strlen(_location);
	location = new char[locationLen + 1];
	strcpy(location, _location);
	location[locationLen] = '\0';
	const char* fileName = getFileName(_location);
	if (strstr(fileName, ".susi") == nullptr)
		throw "Invalid file type. Only \".susi\" files are accepted.";
	std::ifstream infile(location,std::ios::in|std::ios::binary);
	if (!infile.is_open()) {
		//Това е когато няма такъв файл. Тогава се създава нов на негово място, който е празен.
		std::ofstream outfile(location, std::ios::out | std::ios::binary);
		outfile.close();
		infile.close();
		std::cout << "File does not exist, but one was succesfully created and ready for use" << std::endl;
		return true;
	}

	infile.seekg(0, std::ios::beg);
	free();
	infile.read((char*)&programsCapacity, sizeof(int));
	infile.read((char*)&programsCurrent, sizeof(int));
	infile.read((char*)&studentsCapacity, sizeof(int));
	infile.read((char*)&studentsCurrent, sizeof(int));
	programs = new Program * [programsCapacity];
	for (int i = 0; i < programsCapacity; i++) {
		if(i>=programsCurrent)
			programs[i] = nullptr;
		else {
			programs[i] = new Program();
			programs[i]->open(infile);
		}		
	}
	students = new Student * [studentsCapacity];
	for (int i = 0; i < studentsCapacity; i++) {
		if (i >= studentsCurrent)
			students[i] = nullptr;
		else {
			students[i] = new Student();
			students[i]->open(infile);
		}
		
	}
	infile.close();
	std::cout << "Successfully opened " << fileName << std::endl;
	return true;
}

bool SusiController::close()
{
	if (!isLoaded()) {
		return true;
	}
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
	std::cout << "The following commands are supported: " << endl;
	std::cout << "open <file>" << "    " << "opens <file>" << endl;
	std::cout << "close" << "    " << "closes currently opened file" << endl;
	std::cout << "save" << "    " << "saves the currently open file" << endl;
	std::cout << "saveas <file>" << "    " << "saves the currently open file in <file>" << endl;
	std::cout << "help" << "    " << "prints this information" << endl;
	std::cout << "exit" << "    " << "exists the program" << endl;
	std::cout << "enroll <fn><program><group><name>" << "    " << "enrolls student with name <name> in first year in program <program> in group <group> and with faculty number <fn>" << endl;
	std::cout << "advance <fn>" << "    " << "takes the student to the next year" << endl;
	std::cout << "change <fn><option><value>" << "    " << "<option> can be either 'program', 'group' or 'year'. Transfers student with faculty number <fn> in a new program, group or year specified with <value>" << endl;
	std::cout << "graduate <fn>" << "    " << "marks the student with faculty number <fn> as graduated" << endl;
	std::cout << "interrupt <fn>" << "    " << "marks the student with faculty number <fn> as interrupted. Interrupted students can't take exams, enrol in courses or change program, group or year" << endl;
	std::cout << "resume <fn>" << "    " << "restores student rights to the student with faculty number <fn>" << endl;
	std::cout << "print <fn>" << "    " << "prints out a reference for the student with faculty number <fn>" << endl;
	std::cout << "printall <program><year>" << "    " << "prints out a reference for all students in program <program> and year <year>" << endl;
	std::cout << "enrollin <fn><course>" << "    " << "enrolls the student with faculty number <fn> in course <course>" << endl;
	std::cout << "addgrade <fn><course><grade>" << "    " << "Adds a grade <grade> in course <course> for student with faculty number <fn>. You can only add a grade if a student is enrolled in that course." << endl;
	std::cout << "protocol <course>" << "    " << "Prints out all the faculty numbers of students enrolled for course <course>. There is a different protocol for each program." << endl;
	std::cout << "report <fn>" << "    " << "Prints out academic reference for grades of student with faculty number <fn>" << endl;
	std::cout << "addprogram <program>" << "    " << "Adds a program <program> in the system" << endl;
	std::cout << "addcourse <program><course><mandatory><year>" << "    " << "Adds a course <course> for program <program> which can be either mandatory or not <mandatory> (true/false) for year <year>" << endl;
	return true;
}

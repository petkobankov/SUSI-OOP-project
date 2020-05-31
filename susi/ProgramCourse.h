/**
 * \class ProgramCourse
 *
 * \brief Учебна дисциплина за специалност
 *
 * \note Този клас има информацията като всяка друга учебна дисциплина, само че пази факултетните номера на студентите записани.
 *
 */
#pragma once
#include "Course.h"
class ProgramCourse: public Course {
	int listCapacity;
	int listCurrent;
	int* listOfEnrolled;
	bool resizeList();

	void free();
	void copyFrom(const ProgramCourse& other);
public:
	ProgramCourse();
	ProgramCourse(const ProgramCourse& other);
	ProgramCourse& operator=(const ProgramCourse& other);
	~ProgramCourse();

	ProgramCourse(const char* _name, bool _isMandatory, int neededYear);
	bool addFn(int _fn);
	bool protocol()const;
	bool save(std::ofstream& outfile);
	bool open(std::ifstream& infile);
};
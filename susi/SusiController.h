/**
 * \class SusiController
 *
 * \brief Система
 *
 * \note Този клас е главен. Той има контрол над всичко и пази информация за всичко. Конзолата комуникира с другите класове чрез него.
 *
 */
#pragma once
#include "Student.h"
#include "Course.h"
#include "Program.h"
class SusiController {
	int studentsCapacity;
	int studentsCurrent;
	int programsCapacity;
	int programsCurrent;
	char* location;
	Program** programs;
	Student** students;

	bool changeProgram(int _fn, const char* _newProgram);
	int findStudentByFn(int _fn)const;
	int findProgramByName(const char* programName)const;
	bool resizeStudents();
	bool resizePrograms();

	void free();
	void copyFrom(const SusiController& other);
	const char* getFileName(const char* _location)const;
public:
	SusiController();
	SusiController(const SusiController& other);
	SusiController& operator=(const SusiController& other);
	~SusiController();

	bool enroll(int _fn, const char* _program, int _group, const char* _name);
	bool advance(int _fn);
	bool change(int _fn, const char* option, const char* value);
	bool graduate(int _fn);
	bool interrupt(int _fn);
	bool resume(int _fn);
	bool print(int _fn);
	bool printall(const char* programName, int _year);
	bool enrollin(int fn, const char* course);
	bool addgrade(int _fn, const char* _course, double _grade);
	bool protocol(const char* course)const;
	bool report(int _fn)const;
	bool addProgram(const char* name);
	bool addCourseForProgram(const char* _programName,const char* _courseName, bool _isMandatory, int neededYear);
	bool saveas(const char* _location);
	bool open(const char* _location);
	bool close();
	bool save();
	bool help()const;
	const bool isLoaded()const;
};

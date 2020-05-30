#pragma once
#include "Course.h"
#include <cstring>
#include "ProgramCourse.h"
#include <fstream>
class Program {  // специалност
    char* name;
    int coursesCapacity;
    int coursesCurrent;
    ProgramCourse** courses;

    void free();
    void copyFrom(const Program& other);
    bool resizeCourse();
public:
    Program();
    Program(const Program& other);
    Program& operator=(const Program& other);
    ~Program();

    Program(const char* _name);
    bool addCourse(const char* _courseName, bool _isMandatory, int neededYear);
    bool hasTheSameName(const char* _name)const;
    const char** listOfCourseNames(int _year, int& _limit)const;
    const Course& getCourseByName(const char* _courseName);
    bool enrollStudent(const char* _courseName, int _fn);
    bool protocol(const char* _courseName)const;
    const char* getName()const;
    int getCoursesCapacity()const;
    int getCoursesCurrent()const;
    int getListCapacity(int _id)const;
    int getListCurrent(int _id)const;
    const int* getListOfEnrolled(int _id)const;
    bool save(std::ofstream& f);
};
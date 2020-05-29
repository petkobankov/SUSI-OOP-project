#pragma once
#include "Course.h"
#include <cstring>
#include "ProgramCourse.h"
class Program {  // специалност
    char* name;
    int coursesCapacity;
    int coursesCurrent;
    ProgramCourse** courses;
public:
    bool hasTheSameName(const char* _name)const;
    const char** listOfCourseNames(int _year, int& _limit)const;
    const Course& getCourseByName(const char* _courseName);
    bool enrollStudent(const char* _courseName, int _fn);
    bool protocol(const char* _courseName)const;
};
#pragma once
#include "Course.h"
#include <cstring>
class Program {  // специалност
    char* name;
    int coursesCapacity;
    int coursesCurrent;
    Course** courses;
public:
    bool hasTheSameName(const char* _name)const;
    const char** listOfCourseNames(int _year, int& _limit)const;
};
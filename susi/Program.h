#pragma once
#include "Course.h"
#include <cstring>
class Program {  // �����������
    char* name;
    Course** courses;
public:
    bool hasTheSameName(const char* _name)const;
};
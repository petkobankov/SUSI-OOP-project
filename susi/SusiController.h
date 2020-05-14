#pragma once
#include "Student.h"
#include "Course.h"
#include "Program.h"
class SusiController {
    Student* students;
    Course* courses;
    Program* programs; 
public:
    bool enroll(int fn, const char* programName, int group, const char* studentName);
    bool advance(int fn);
    bool change(int fn, const char* option, int value);
    bool change(int fn, const char* option, const char* value);
    bool graduate(int fn);
    bool interrupt(int fn);
    bool resume(int fn);
    bool print(int fn);
    bool printall(const char* programName, int year);
    bool enrollin(int fn, const char* courseName);
    bool addgrade(int fn, const char* courseName, double grade);
    bool protocol(const char* courseName);
    bool report(int fn);
}

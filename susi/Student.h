#pragma once
#include "Course.h"
class Student {
    char* name; // ���
    bool isGradauted;
    bool isInterrupted;
    int fn; // ���������� �����
    int group; // �����
    int year;//������ ������� ����
    char* program; // �����������
    double averageGrade; // ������ ����� �� ���������� �� �������
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    Course** currentCourses; // ������ �������� ���������� �� �������� �� ����� �� � ������� �����
    Course** gradedCourses; // ������ �������� ���������� �� �������� �� ����� � ������� ������� �����
public:
    Student(int _fn,const char* _program,int _group, int year,const char* _name);
    int getFn()const;
    bool advance();
    bool changeGroup(int _group);
    bool changeYear(int _year);
    bool changeProgram(const char** _courseList, int _limit,const char* _newProgramName);
    int getStudentYear()const;
    bool graduate();
    bool interrupt();
    bool resume();
    bool print()const;
    bool isForProgramYear(const char* _programName, int _year)const;
    /*bool addGrade(double grade,const Course& course);
    bool addCourse(const Course& course);
    bool printProtocols()const;*/
};
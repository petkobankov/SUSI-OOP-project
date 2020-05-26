#pragma once
#include "Course.h"
class Student {
    char* name; // ���
    int fn; // ���������� �����
    int group; // �����
    int year;//������ ������� ����
    char* program; // �����������
    char status; //������ (E - �������, A - ���������, G - ��������)
    double averageGrade; // ������ ����� �� ���������� �� �������
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    Course** enrolledCourses; // ������ �������� ���������� �� �������� �� ����� �� � ������� �����
    Course** gradedCourses; // ������ �������� ���������� �� �������� �� ����� � ������� ����� � ��� ������
public:
    Student(int _fn,const char* _program,int _group, int year,const char* _name);
    int getFn()const;
    bool advance();
    bool changeGroup(int _group);
    bool changeYear(int _year);
    /*bool addGrade(double grade,const Course& course);
    bool addCourse(const Course& course);
    bool printProtocols()const;*/
};
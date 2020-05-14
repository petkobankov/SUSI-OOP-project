#pragma once
#include "Grade.h"
#include "EnrolledCourse.h"
class Student {
    char* name; // ���
    int fn; // ���������� �����
    int group; // �����
    int year;//������ ������� ����
    const Program* program; // �����������
    char status[10]; //������ (�������, ���������, ��������)
    const EnrolledCourse* enrolledCoursses;
public:
    bool addGrade(double grade,const Course& course);
    bool addCourse(const Course& course);
    bool printProtocols()const;
};
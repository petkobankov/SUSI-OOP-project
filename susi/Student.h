/**
 * \class Student
 *
 * \brief �������
 *
 * \note ���� ����� ���� ���������� ����� �� ����� �������.
 *
 */
#pragma once
#include "Course.h"
class Student {
    /// ���
    char* name; 
    ///���� � ��������
    bool isGradauted;
    ///���� � ���������
    bool isInterrupted;
    /// ���������� �����
    int fn; 
    /// �����
    int group; 
    ///������ ������� ����
    int year;
    /// �����������
    char* program; 
    /// ������ ����� �� ���������� �� �������
    double averageGrade; 
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    /// ������ �������� ���������� �� �������� �� ����� �� � ������� �����
    Course** currentCourses; 
    /// ������ �������� ���������� �� �������� �� ����� � ������� ������� �����
    Course** gradedCourses; 

    void free();
    void copyFrom(const Student& other);
    ///�������� �� ������ �� ������ ���� ���������� ��� ������ �� ����������
    bool updateAverageGrade();
    bool resizeEnrolled();
    bool resizeGraded();
public:
    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    Student(int _fn,const char* _program,int _group, int year,const char* _name);
    ///�������� ���������� ��������� ����
    bool advance();
    ///����� ������� �� ��������
    bool changeGroup(int _group);
    ///����� ����� �� ��������
    bool changeYear(int _year);
    ///����� ���������� �� ��������
    bool changeProgram(const char** _courseList, int _limit,const char* _newProgramName);
    ///������� �������� ���� ��������
    bool graduate();
    ///������� �������� ���� ���������
    bool interrupt();
    ///����� ������������ ����� �� ��������
    bool resume();
    ///������� ���������� �� �������� ���� ���, ���������� ����� ...
    bool print()const;
    bool isForProgramYear(const char* _programName, int _year)const;
    ///������� �������� � ������ ����������
    bool enrollin(const Course& _courseForEnroll);
    ///������� ������ ����������
    bool addgrade(const char* _course, double _grade);
    ///���������� ������� �� ��������
    bool report()const;

    const char* getName()const;
    bool getIsGratuated()const;
    bool getIsInterrupted()const;
    int getGroup()const;
    double getAverageGrade()const;
    int getEnrolledCapacity()const;
    int getEnrolledCurrent()const;
    int getGradedCapacity()const;
    int getGradedCurrent()const;
    int getFn()const;
    int getStudentYear()const;
    const char* getProgram()const;

    bool save(std::ofstream& outfile);
    bool open(std::ifstream& infile);

};
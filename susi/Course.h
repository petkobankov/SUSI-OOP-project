#pragma once
#include <fstream>
class Course {//�������� ����������
    char* name; //��� �� �������� ����������
    bool mandatory; //true - ������������ false - ���������
    int neededYear; //� ��� ���� ���� �� ���� ��������
    double grade; // 2 by default

    void free();
    void copyFrom(const Course& other);
public:
    Course();
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();

    Course(const char* _name, bool _isMandatory, int _neededYear, double _grade);
    Course(const char* _name, bool _isMandatory, int _neededYear);
    bool isMandatory()const;
    const char* getName()const;
    int getNeededYear()const;
    bool hasTheSameName(const char* name)const;
    bool setGrade(double _grade);
    double getGrade();
    bool print()const;
    bool save(std::ofstream& outfile);
    bool open(std::ifstream& infile);
};
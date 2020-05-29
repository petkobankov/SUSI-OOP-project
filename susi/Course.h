#pragma once
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

    bool isMandatory()const;
    const char* getName()const;
    int getNeededYear()const;
    bool hasTheSameName(const char* name)const;
    bool setGrade(double _grade);
    bool print()const;
};
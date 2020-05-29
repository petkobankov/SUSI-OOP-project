#pragma once
class Course {//Учебната дисциплина
    char* name; //Име на учебната дисциплина
    bool mandatory; //true - задължителна false - избираема
    int neededYear; //в кой курс може да бъде записана
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
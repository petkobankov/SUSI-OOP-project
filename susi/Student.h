#pragma once
#include "Course.h"
class Student {
    char* name; // Име
    int fn; // Факултетен номер
    int group; // Група
    int year;//Текущо записан курс
    char* program; // специалност
    char status; //Статус (E - записан, A - прекъснал, G - завършил)
    double averageGrade; // Среден успех от следването до момента
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    Course** enrolledCourses; // Всички записани дисциплини на студента на които не е положил изпит
    Course** gradedCourses; // Всички записани дисциплини на студента на които е положил изпит и има оценка
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
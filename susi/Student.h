#pragma once
#include "Grade.h"
#include "EnrolledCourse.h"
class Student {
    char* name; // Име
    int fn; // Факултетен номер
    int group; // Група
    int year;//Текущо записан курс
    const Program* program; // специалност
    char status[10]; //Статус (записан, прекъснал, завършил)
    const EnrolledCourse* enrolledCoursses;
public:
    bool addGrade(double grade,const Course& course);
    bool addCourse(const Course& course);
    bool printProtocols()const;
};
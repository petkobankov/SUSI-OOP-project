#pragma once
#include "Course.h"
class Student {
    char* name; // Име
    bool isGradauted;
    bool isInterrupted;
    int fn; // Факултетен номер
    int group; // Група
    int year;//Текущо записан курс
    char* program; // специалност
    double averageGrade; // Среден успех от следването до момента
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    Course** currentCourses; // Всички записани дисциплини на студента на които не е положил изпит
    Course** gradedCourses; // Всички записани дисциплини на студента на които е положил успешно изпит

    void free();
    void copyFrom(const Student& other);
    bool updateAverageGrade();
    bool resizeEnrolled();
    bool resizeGraded();
public:
    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    Student(int _fn,const char* _program,int _group, int year,const char* _name);
    bool advance();
    bool changeGroup(int _group);
    bool changeYear(int _year);
    bool changeProgram(const char** _courseList, int _limit,const char* _newProgramName);
    bool graduate();
    bool interrupt();
    bool resume();
    bool print()const;
    bool isForProgramYear(const char* _programName, int _year)const;
    bool enrollin(const Course& _courseForEnroll);
    bool addgrade(const char* _course, double _grade);
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

    const char* getECourseName(int _id)const;
    bool getECourseType(int _id)const;
    int getECourseYear(int _id)const;
    double getECourseGrade(int _id)const;
    const char* getGCourseName(int _id)const;
    bool getGCourseType(int _id)const;
    int getGCourseYear(int _id)const;
    double getGCourseGrade(int _id)const;
};
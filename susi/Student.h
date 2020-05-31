/**
 * \class Student
 *
 * \brief Студент
 *
 * \note Клас който пази информация нужна за всеки студент.
 *
 */
#pragma once
#include "Course.h"
class Student {
    /// Име
    char* name; 
    ///Дали е завършил
    bool isGradauted;
    ///Дали е прекъснал
    bool isInterrupted;
    /// Факултетен номер
    int fn; 
    /// Група
    int group; 
    ///Текущо записан курс
    int year;
    /// Специалност
    char* program; 
    /// Среден успех от следването до момента
    double averageGrade; 
    int enrolledCapacity;
    int enrolledCurrent;
    int gradedCapacity;
    int gradedCurrent;
    /// Всички записани дисциплини на студента на които не е положил изпит
    Course** currentCourses; 
    /// Всички записани дисциплини на студента на които е положил успешно изпит
    Course** gradedCourses; 

    void free();
    void copyFrom(const Student& other);
    ///Използва се когато се добави нова дисциплина или оценка за дисциплина
    bool updateAverageGrade();
    bool resizeEnrolled();
    bool resizeGraded();
public:
    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    Student(int _fn,const char* _program,int _group, int year,const char* _name);
    ///Студента продължава следващия курс
    bool advance();
    ///Сменя групата на студента
    bool changeGroup(int _group);
    ///Сменя курса на студента
    bool changeYear(int _year);
    ///Сменя програмата на студента
    bool changeProgram(const char** _courseList, int _limit,const char* _newProgramName);
    ///Маркира студента като завършил
    bool graduate();
    ///Маркира студента като прекъснал
    bool interrupt();
    ///Връща студентските права на студента
    bool resume();
    ///Изписва информация за студента като име, факултетен номер ...
    bool print()const;
    bool isForProgramYear(const char* _programName, int _year)const;
    ///Записва студента в дадена дисциплина
    bool enrollin(const Course& _courseForEnroll);
    ///Оценява дадена дисциплина
    bool addgrade(const char* _course, double _grade);
    ///Академична справка за студента
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
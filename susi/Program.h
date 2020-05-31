/**
 * \class Program
 *
 * \brief Специалност
 *
 * \note В този клас се използва ProgramCourse който работи като Course, обаче в него са запазени факултетните номера за записаните студенти.
 *
 */
#pragma once
#include "Course.h"
#include <cstring>
#include "ProgramCourse.h"
#include <fstream>
class Program {  
    char* name;
    int coursesCapacity;
    int coursesCurrent;
    ProgramCourse** courses;

    void free();
    void copyFrom(const Program& other);
    bool resizeCourse();
public:
    Program();
    Program(const Program& other);
    Program& operator=(const Program& other);
    ~Program();

    Program(const char* _name);
    ///Добавяне на нов курс за тази специалност.
    bool addCourse(const char* _courseName, bool _isMandatory, int neededYear);
    bool hasTheSameName(const char* _name)const;
    ///Помощна функция нужна когато студент сменя своята специалност и трябва да провери дали е минал изпитите за специалността която иска да бъде.
    const char** listOfCourseNames(int _year, int& _limit)const;
    ///По подадено име на курс връща референция към този курс. Ако такъв не се намери се съобщава.
    const Course& getCourseByName(const char* _courseName);
    ///Записва студент за дадена дисциплина
    bool enrollStudent(const char* _courseName, int _fn);
    ///Извежда факултетните номера за дадена дисциплина
    bool protocol(const char* _courseName)const;
    const char* getName()const;
    ///Помощна функция за запазване във файл
    bool save(std::ofstream& outfile);
    ///Помощна функция за отваряне на файл
    bool open(std::ifstream& infile);
};
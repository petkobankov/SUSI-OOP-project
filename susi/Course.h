/**
 * \class Course
 *
 * \brief Учебна дисциплина
 *
 * \note Записва данни за взети изпити или просто ако студент е записал дадена дисциплина. Има наследник ProgramCourse който е специяно само за клас Program. Course се използва главно от Student.
 *
 */
#pragma once
#include <fstream>
class Course {
    ///Име на учебната дисциплина
    char* name; 
    ///true - задължителна false - избираема
    bool mandatory; 
    ///в кой курс може да бъде записана
    int neededYear; 
    /// 2 by default
    double grade; 

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
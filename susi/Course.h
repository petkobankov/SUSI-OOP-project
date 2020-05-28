#pragma once
class Course {//Учебната дисциплина
    char* name; //Име на учебната дисциплина
    bool mandatory; //true - задължителна false - избираема
    int neededYear; //в кой курс може да бъде записана
    double grade;
public:
    bool isMandatory()const;
    const char* getName()const;
    int getNeededYear()const;
    bool hasTheSameName(const char* name)const;
};
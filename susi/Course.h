#pragma once
class Course {//�������� ����������
    char* name; //��� �� �������� ����������
    bool mandatory; //true - ������������ false - ���������
    int neededYear; //� ��� ���� ���� �� ���� ��������
    double grade;
public:
    bool isMandatory()const;
    const char* getName()const;
    int getNeededYear()const;
    bool hasTheSameName(const char* name)const;
};
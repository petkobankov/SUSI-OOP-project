#pragma once
class Course {//�������� ����������
    char* name; //��� �� �������� ����������
    bool mandatory; //true - ������������ false - ���������
    int neededYear; //� ��� ���� ���� �� ���� ��������
    double grade;
public:
    bool isMandatory()const;
};
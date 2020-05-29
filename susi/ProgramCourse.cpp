#include "ProgramCourse.h"
#include <iostream>

bool ProgramCourse::addFn(int _fn)
{
	//������ � ������� ��� �������� �������� ����������� ����� �� ��� �������. ������ �� ����, �� �� ������������ �� �� ��������� � ��������� ��� ���� �� ����� �� � ����� ����������� �� ���������.
	if (listCurrent == listCapacity)
		;//resizeList();
	if (listCurrent == 0) {
		listOfEnrolled[listCurrent++] = _fn;
		return true;
	}
	for (int i = listCurrent-1; i >=0; i--) {
		if (_fn > listOfEnrolled[i]) {
			listOfEnrolled[i + 1] = _fn;
			listCurrent++;
			return true;
		}
		else {
			listOfEnrolled[i + 1] = listOfEnrolled[i];
		}
	}
	listOfEnrolled[0] = _fn;
	listCurrent++;
	return true;
}

bool ProgramCourse::protocol() const
{
	for (int i = 0; i < listCurrent; i++) {
		if(i!= listCurrent-1)
			std::cout << listOfEnrolled[i] << ", ";
		else
			std::cout << listOfEnrolled[i] << std::endl;
	}
	return true;
}

using namespace std;
#include <iostream>
#include "SusiController.h"

int main()
{
    SusiController sys;
    sys.addProgram("Computer Science");
    sys.addCourseForProgram("Computer Science","Object oriented programing",true,1);
    sys.addCourseForProgram("Computer Science", "DIS", true, 1);
    sys.addCourseForProgram("Computer Science", "EAI", true, 1);
    sys.addCourseForProgram("Computer Science", "OOP praktikum", false, 1);
    sys.addCourseForProgram("Computer Science", "Dizain i analiz na algoritmi", true, 2);
    sys.addProgram("Software Engineering");
    sys.addCourseForProgram("Software Engineering", "DIS", true, 1);
    sys.addCourseForProgram("Software Engineering", "EAI", true, 1);
    sys.addProgram("Maths");
    sys.addProgram("Informatics");
    sys.addProgram("Maths 2");

    sys.enroll(81854, "Computer Science", 7, "Petko");
    sys.enroll(823, "Computer Science", 2, "Ivan");
    sys.enroll(123, "Computer Science", 1, "Ivana");
    sys.enroll(22254, "Computer Science", 7, "Gosho");
    sys.enroll(354, "Computer Science", 3, "Petur");
    sys.enroll(8124, "Computer Science", 3, "Pavel");
    sys.enroll(1, "Computer Science", 3, "Dido");

    sys.enroll(3542, "Software Engineering", 4, "Ivan");
    sys.enroll(12, "Informatics", 1, "Konstantin");
    sys.enroll(13, "Maths", 1, "Kristina");

    sys.print(81854);
    //sys.printall("Computer Science",1);
}


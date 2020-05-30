using namespace std;
#include <iostream>
#include "SusiController.h"
const int LENGTH = 13;
int main()
{
    

    
    char command[LENGTH];

    cin >> command;
    SusiController sys;
    sys.addProgram("ComputerScience");
    sys.addCourseForProgram("ComputerScience", "OOP", true, 1);
    sys.addCourseForProgram("ComputerScience", "DIS", true, 1);
    sys.addCourseForProgram("ComputerScience", "EAI", true, 1);
    sys.addCourseForProgram("ComputerScience", "OOP-praktikum", false, 1);
    sys.addCourseForProgram("ComputerScience", "Dizain-i-analiz-na-algoritmi", true, 2);

    sys.addProgram("SoftwareEngineering");
    sys.addCourseForProgram("SoftwareEngineering", "DIS", true, 1);
    sys.addCourseForProgram("SoftwareEngineering", "EAI", true, 1);

    sys.addProgram("Maths");
    sys.addProgram("Informatics");
    sys.addProgram("Maths2");

    sys.enroll(81854, "ComputerScience", 7, "Petko");
    sys.enroll(823, "ComputerScience", 2, "Ivan");
    sys.enroll(123, "ComputerScience", 1, "Ivana");
    sys.enroll(22254, "ComputerScience", 7, "Gosho");
    sys.enroll(354, "ComputerScience", 3, "Petur");
    sys.enroll(8124, "ComputerScience", 3, "Pavel");
    sys.enroll(1, "ComputerScience", 3, "Dido");

    sys.enroll(3542, "SoftwareEngineering", 4, "Ivan");
    sys.enroll(12, "Informatics", 1, "Konstantin");
    sys.enroll(13, "Maths", 1, "Kristina");

    sys.print(81854);
    //sys.printall("Computer Science",1);

    sys.enrollin(81854, "Object oriented programing");
    sys.enrollin(81854, "DIS");
    sys.enrollin(81854, "OOP praktikum");
    sys.enrollin(81854, "Dizain i analiz na algoritmi");

    sys.addgrade(81854,"DIS",3.4);

    sys.protocol("DIS");

    sys.report(81854);
    while (strcmp(command, "exit") != 0) {

        if (strcmp(command, "open") == 0) {
            char location[1024];
            cin.getline(location,1024);
            try {
                if (!sys.open(location))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            
        }
        else if (strcmp(command, "close") == 0) {
            try {
                if (!sys.close())
                    cout << "Something went wrong" << endl;
                
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "save") == 0) {
            try {
                if (!sys.save())
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "saveas") == 0) {
            char location[1024];
            cin.getline(location, 1024);
            try {
                if (!sys.saveas(location))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "help") == 0) {
            try {
                if (!sys.help())
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "enroll") == 0) {
            int fn;
            char program[1024];
            int group;
            char name[1024];

            cin >> fn;
            cin >> program;
            cin >> group;
            cin >> name;
            try {
                if (!sys.enroll(fn,program,group,name))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "advance") == 0) {
            int fn;
            cin >> fn;
            try {
                if (!sys.advance(fn))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "change") == 0) {
            int fn;
            char option[1024];
            char value[1024];

            cin >> fn;
            cin >> option;
            cin >> value;
            try {
                if (!sys.change(fn, option, value))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "graduate") == 0) {
            int fn;
           
            cin >> fn;
            
            try {
                if (!sys.graduate(fn))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "interrupt") == 0) {
        int fn;

        cin >> fn;

        try {
            if (!sys.interrupt(fn))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "resume") == 0) {
        int fn;

        cin >> fn;

        try {
            if (!sys.resume(fn))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "print") == 0) {
        int fn;

        cin >> fn;

        try {
            if (!sys.print(fn))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "printall") == 0) {
        char program[1024];
        int year;
        cin >> program;
        cin >> year;

        try {
            if (!sys.printall(program,year))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "enrollin") == 0) {
        char course[1024];
        int fn;
        cin >> fn;
        cin >> course;

        try {
            if (!sys.enrollin(fn, course))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "addgrade") == 0) {
        char course[1024];
        int fn;
        double grade;
        cin >> fn;
        cin >> course;
        cin >> grade;

        try {
            if (!sys.addgrade(fn, course,grade))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "protocol") == 0) {
        char course[1024];
        cin >> course;

        try {
            if (!sys.protocol(course))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "report") == 0) {
        int fn;
        cin >> fn;

        try {
            if (!sys.report(fn))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "addprogram") == 0) {
        char program[1024];
        cin >> program;

        try {
            if (!sys.addProgram(program))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "addcourse") == 0) {
        //<program><course><mandatory><year>
        char program[1024];
        char course[1024];
        char mandatory[1024];
        bool isMandatory;
        int year;
        cin >> program;
        cin >> course;
        cin >> mandatory;
        cin >> year;
        if (strcmp(mandatory, "true") == 0) {
            isMandatory = true;
        }
        else {
            isMandatory = false;
        }

        try {
            if (!sys.addCourseForProgram(program,course,isMandatory,year))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else {
            cout << "Invalid command" << endl;
        }
        cout << endl;
        cin >> command;

    }
    cout << "Exiting the program..." << endl;
}


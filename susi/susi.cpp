using namespace std;
#include <iostream>
#include "SusiController.h"
#include "Course.h"
#include "Program.h"
#include "ProgramCourse.h"
#include "Student.h"
const int LENGTH = 13;
int main()
{
    char command[LENGTH];
    SusiController* sys=new SusiController();
    /*sys->addProgram("ComputerScience");
    sys->addProgram("SoftwareEngineering");
    sys->enroll(1, "ComputerScience", 7, "Petko");
    sys->enroll(2, "SoftwareEngineering", 2, "Pavel");
    sys->enroll(3, "ComputerScience", 7, "Ivan");
    sys->enroll(4, "SoftwareEngineering", 1, "Krisi");

    sys->addCourseForProgram("ComputerScience", "Program1", true, 1);
    sys->addCourseForProgram("ComputerScience", "Program2", true, 2);
    sys->addCourseForProgram("ComputerScience", "Program3", true, 3);
    sys->addCourseForProgram("ComputerScience", "Program4", true, 4);
    sys->addCourseForProgram("ComputerScience", "FreeP", false, 1);
    sys->addCourseForProgram("SoftwareEngineering", "ProgramX", true, 1);
    sys->addCourseForProgram("SoftwareEngineering", "Program1", true, 1);

    sys->enrollin(1, "Program1");
    sys->enrollin(2, "Program1");
    sys->enrollin(3, "Program1");
    sys->enrollin(4, "Program1");

    sys->addgrade(3, "Program1", 5);
    sys->addgrade(1, "Program1", 4);
    sys->addgrade(4, "Program1", 6);
    sys->addgrade(2, "Program1", 3);*/
    
    
    cin >> command;
    while (strcmp(command, "exit") != 0) {

        if (strcmp(command, "open") == 0) {
            char location[1024];
            cin.ignore();
            cin.getline(location,1024);
            try {
                if (!sys->close())
                    cout << "Something went wrong" << endl;
                if (!sys->open(location))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
            
        }
        else if (strcmp(command, "close") == 0) {
            try {
                if (!sys->close())
                    cout << "Something went wrong" << endl;
                delete sys;
                sys = new SusiController();
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "save") == 0) {
            try {
                if (!sys->save())
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "saveas") == 0) {
            char location[1024];
            cin.ignore();
            cin.getline(location, 1024);
            try {
                if (!sys->saveas(location))
                    cout << "Something went wrong" << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;
            }
        }
        else if (strcmp(command, "help") == 0) {
            try {
                if (!sys->help())
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
                if (!sys->enroll(fn,program,group,name))
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
                if (!sys->advance(fn))
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
                if (!sys->change(fn, option, value))
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
                if (!sys->graduate(fn))
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
            if (!sys->interrupt(fn))
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
            if (!sys->resume(fn))
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
            if (!sys->print(fn))
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
            if (!sys->printall(program,year))
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
            if (!sys->enrollin(fn, course))
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
            if (!sys->addgrade(fn, course,grade))
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
            if (!sys->protocol(course))
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
            if (!sys->report(fn))
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
            if (!sys->addProgram(program))
                cout << "Something went wrong" << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        }
        else if (strcmp(command, "addcourse") == 0) {
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
            if (!sys->addCourseForProgram(program,course,isMandatory,year))
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
    delete sys;
}


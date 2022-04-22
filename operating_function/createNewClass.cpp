//Created by DInh Quang Hieu 
//Started 17/03/2022
//Edited 22/03/2022
//Edited 23/03/2022
//Edited 25/03/2022
//Edited 27/03/2022
//Add student to list class new

#include <cstring>
#include <fstream>
#include "operating_function/structure.h"
using namespace std;

void createClassList(School& HCMUS, string classID_x, string filename) {
    Class* newClass = new Class();
    newClass->classID = classID_x;
    ifstream fin; fin.open(filename);
    while (!fin.eof()) {
        Student* newStudent = new Student();
        fin >> newStudent->No >> newStudent->studentID >> newStudent->firstName >> newStudent->lastName >> newStudent->dateOfBirth >> newStudent->socialID ;
        newClass->addNewStudent(newStudent);
    }
    HCMUS.allClasses.addNewClass(newClass);
}

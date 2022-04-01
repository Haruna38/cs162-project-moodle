//
//  database_function.cpp
//  structure
//
//  Created by Hoang The Anh on 01/04/2022.
//

#include "database_function.hpp"
#include "structure.h"
#include "general_function.hpp"
#include "fstream"
using namespace std;

void saveDatabase(School mySchool) {
    ofstream fout1;
    fout1.open("school_database.txt", ios::app);
    fout1 << mySchool.allClasses.numberofClasses << "\n";
    Class* classPointer = mySchool.allClasses.monitor;
    while (classPointer->nextClass != NULL) {
        classPointer = classPointer->nextClass;
        fout1 << classPointer->classID << "\n";
        string classIDStr = classPointer->classID + ".txt";
        ofstream fout2; fout2.open(classIDStr, ios::app);
        fout2 << classPointer->sizeOfClass << "\n";
        Student* studentPointer = classPointer->monitor;
        while (studentPointer->nextStudent != NULL) {
            studentPointer = studentPointer->nextStudent;
            fout2 << studentPointer->studentID << "\n";
            string studentIDStr = to_string(studentPointer->studentID) + ".txt";
            ofstream fout3; fout3.open(studentIDStr, ios::app);
            fout3 << studentPointer->No << "\n" << studentPointer->studentID << "\n" << studentPointer->firstName << "\n" << studentPointer->lastName << "\n" << studentPointer->gender
            << "\n" << studentPointer->dateOfBirth << "\n" << studentPointer->socialID << "\n" << studentPointer->myCourses.sizeofList << "\n";
            enrolledCourse* enrolledCoursePointer = studentPointer->myCourses.monitor;
            while (enrolledCoursePointer->nextEnrolledCourse != NULL) {
                enrolledCoursePointer = enrolledCoursePointer->nextEnrolledCourse;
                fout3 << enrolledCoursePointer->courseID << "\n";
            }
            fout3.close();
        }
        fout2.close();
    }
    fout1 << mySchool.allCourses.sizeofCourses << "\n";
    Course* coursePointer = mySchool.allCourses.monitor;
    while (coursePointer->nextCourse != NULL) {
        coursePointer = coursePointer->nextCourse;
        fout1 << coursePointer->courseID << "\n";
        string courseIDStr = coursePointer->courseID + ".txt";
        ofstream fout2; fout2.open(courseIDStr, ios::app);
        fout2 << coursePointer->courseName << "\n" << coursePointer->teacherName << "\n" << coursePointer->numberofCredit << "\n" << coursePointer->maxStudent << "\n" << coursePointer->day[0] << " " << coursePointer->day[1] << "\n" << coursePointer->session[0] << " " << coursePointer->session[1] << "\n" << coursePointer->schoolyear << "\n" << coursePointer->semester << "\n" << coursePointer->courseClass.sizeOfClass << "\n";
        Student* studentPointer = coursePointer->courseClass.monitor;
        while (studentPointer->nextStudent != NULL) {
            studentPointer = studentPointer->nextStudent;
            fout2 << studentPointer->studentID << "\n";
        }
        fout2.close();
    }
    fout1.close();
}

void loadData(School& mySchool) {
    //luoi qua nen lam sau
};

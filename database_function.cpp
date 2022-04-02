//
//  database_function.cpp
//  structure
//
//  Created by Hoang The Anh on 01/04/2022.
//  Edited by Hoang The Anh on 02/04/2022.

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
        exportScore(coursePointer);
        fout2 << "Score_" + coursePointer->courseID + "_" + to_string(coursePointer->schoolyear) + "_" + to_string(coursePointer->semester) + ".csv\n";
        fout2.close();
    }
    fout1.close();
}

void loadDatabase(School& mySchool) {
    ifstream fin_school;
    fin_school.open("myschool.txt");
    fin_school >> mySchool.allClasses.numberofClasses;
    for (int i = 0; i < mySchool.allClasses.numberofClasses; i++) {
        Class* aClass = new Class();
        fin_school >> aClass->classID;
        ifstream fin_class; fin_class.open((string)(aClass->classID + ".txt"));
        fin_class >> aClass->sizeOfClass;
        for (int j = 0; j < aClass->sizeOfClass; j++) {
            Student* aStudent = new Student();
            fin_class >> aStudent->studentID;
            ifstream fin_student; fin_student.open((string)(to_string(aStudent->studentID) + ".txt"));
            fin_student >> aStudent->No;
            fin_student.ignore();
            getline(fin_student, aStudent->firstName);
            getline(fin_student, aStudent->lastName);
            fin_student >> aStudent->gender >> aStudent->dateOfBirth >> aStudent->socialID >> aStudent->myCourses.sizeofList;
            for (int k = 0; k < aStudent->myCourses.sizeofList; k++) {
                string* anEnrolledCourseID = new string;
                fin_student >> (*(anEnrolledCourseID));
                aStudent->myCourses.addNewEnrolledCourse(anEnrolledCourseID);
            }
            aClass->addNewStudent(aStudent);
            fin_student.close();
        }
        mySchool.allClasses.addNewClass(aClass);
        fin_class.close();
    }
    fin_school >> mySchool.allCourses.sizeofCourses;
    for (int i = 0; i < mySchool.allCourses.sizeofCourses; i++) {
        Course* aCourse = new Course();
        fin_school >> aCourse->courseID;
        ifstream fin_course; fin_course.open(aCourse->courseID + ".txt");
        getline(fin_course, aCourse->courseName);
        getline(fin_course, aCourse->teacherName);
        fin_course >> aCourse->numberofCredit >> aCourse->maxStudent >> aCourse->day[0] >> aCourse->day[1] >> aCourse->session[0] >> aCourse->session[1] >> aCourse->schoolyear >> aCourse->semester;
        fin_course >> aCourse->courseClass.sizeOfClass;
        for (int j = 0; j < aCourse->courseClass.sizeOfClass; j++) {
            Student* aStudent = new Student();
            fin_course >> aStudent->studentID;
            aCourse->courseClass.addStudentToCourse(aStudent);
        }
        string scoreBoardfile; fin_course >> scoreBoardfile;
        importScore(aCourse, scoreBoardfile);
        fin_course.close();
    }
    fin_school.close();
};

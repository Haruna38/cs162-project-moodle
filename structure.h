//
//  structure.h
//  structure
//
//  Created by Hoang The Anh on 17/03/2022.
//  Edited by Hoang The Anh on 19/03/2022.
//  Edited by Hoang The Anh on 21/03/2022.
//  Edited by Hoang The Anh on 22/03/2022.
//  Edited by Hoang The Anh on 24/03/2022.
//  Edited by Hoang The Anh on 30/03/2022.
//  Edited by Hoang The Anh on 02/04/2022.

#ifndef structure_h
#define structure_h

#pragma once

#include <string>
#include <cstring>
using namespace std;

struct enrolledCourse{
    string* courseID;
    enrolledCourse* nextEnrolledCourse;
    enrolledCourse(string* courseID_x) {
        courseID = courseID_x;
        nextEnrolledCourse = NULL;
    }
};

struct enrolledCourses {
    int sizeofList;
    enrolledCourse* monitor;
    enrolledCourses() {
        sizeofList = 0;
        monitor = NULL;
    }
    void addNewEnrolledCourse(string* courseID_x) {
        ++sizeofList;
        enrolledCourse* newCourse = new enrolledCourse(courseID_x);
        newCourse->nextEnrolledCourse = monitor->nextEnrolledCourse;
        monitor->nextEnrolledCourse = newCourse;
    }
    void deallocate() {
        while (sizeofList) {
            --sizeofList;
            enrolledCourse* j = monitor->nextEnrolledCourse;
            monitor->nextEnrolledCourse = monitor->nextEnrolledCourse->nextEnrolledCourse;
            delete j;
        }
        delete monitor;
    }
};

struct Student {
    int No;
    long long studentID;
    string firstName;
    string lastName;
    bool gender;
    string dateOfBirth;
    long long socialID;
    Student* inClassMonitor;
    enrolledCourses myCourses;
    Student* nextStudent;
    Student() {
        No = 0;
        studentID = 0;
        firstName = "";
        lastName = "";
        gender = 0;
        dateOfBirth = "";
        socialID = 0;
        nextStudent = NULL;
        inClassMonitor = NULL;
        myCourses = enrolledCourses();
    }
    Student(int No_x, long long studentID_x, string firstName_x, string lastName_x, bool gender_x, string dateOfBirth_x, long long socialID_x) {
        No = No_x;
        studentID = studentID_x;
        firstName = firstName_x;
        lastName = lastName_x;
        gender = gender_x;
        dateOfBirth = dateOfBirth_x;
        socialID = socialID_x;
        nextStudent = NULL;
        inClassMonitor = NULL;
        myCourses = enrolledCourses();
    }
    Student(int No_x, long long studentID_x, string firstName_x, string lastName_x, bool gender_x, string dateOfBirth_x, long long socialID_x, Student* inClassMonitor_x) {
        No = No_x;
        studentID = studentID_x;
        firstName = firstName_x;
        lastName = lastName_x;
        gender = gender_x;
        dateOfBirth = dateOfBirth_x;
        socialID = socialID_x;
        nextStudent = NULL;
        inClassMonitor = inClassMonitor_x;
        myCourses = enrolledCourses();
    }
    Student(int No_x, long long studentID_x, string firstName_x, string lastName_x, bool gender_x, string dateOfBirth_x, long long socialID_x, Student* inClassMonitor_x, enrolledCourses myCourses_x) {
        No = No_x;
        studentID = studentID_x;
        firstName = firstName_x;
        lastName = lastName_x;
        gender = gender_x;
        dateOfBirth = dateOfBirth_x;
        socialID = socialID_x;
        nextStudent = NULL;
        inClassMonitor = inClassMonitor_x;
        myCourses = myCourses_x;
    }
    void addNewEnrolledCourse(string* courseID_x) {
        myCourses.addNewEnrolledCourse(courseID_x);
    }
};

struct Class {
    string classID;
    int sizeOfClass;
    Student* monitor;
    Class* nextClass;
    Class() {
        classID = "";
        sizeOfClass = 0;
        monitor = new Student();
        nextClass = NULL;
    }
    Class(string classID_x) {
        classID = classID_x;
        sizeOfClass = 0;
        monitor = new Student();
        nextClass = NULL;
    }
    Class(string classID_x, int sizeOfClass_x) {
        classID = classID_x;
        sizeOfClass = sizeOfClass_x;
        monitor = new Student();
        nextClass = NULL;
    }
    Class(string classID_x, int sizeOfClass_x, Student* monitor_x) {
        classID = classID_x;
        sizeOfClass = sizeOfClass_x;
        monitor = monitor_x;
        nextClass = NULL;
    }
    Class(string classID_x, int sizeOfClass_x, Student* monitor_x, Class* nextClass_x) {
        classID = classID_x;
        sizeOfClass = sizeOfClass_x;
        monitor = monitor_x;
        nextClass = nextClass_x;
    }
    void addNewStudent(Student* newStudent) {
        ++sizeOfClass;
        newStudent->inClassMonitor = monitor;
        Student* cur = monitor;
        while (cur->nextStudent != NULL) cur = cur->nextStudent;
        newStudent->nextStudent = NULL;
        cur->nextStudent = newStudent;
    }
    void addStudentToCourse(Student* newStudent) {
        ++sizeOfClass;
        newStudent->nextStudent = monitor->nextStudent;
        monitor->nextStudent = newStudent;
    }
    Student* getStudentFromClass(int studentID) {
        Student* cur = monitor;
        while (cur->nextStudent != NULL) {
            if (cur->nextStudent->studentID == studentID) {
                return cur->nextStudent;
            }
        }
        return NULL;
    }
    void deallocate() {
        while (sizeOfClass) {
            Student* h = monitor->nextStudent;
            monitor->nextStudent = monitor->nextStudent->nextStudent;
            delete h;
            --sizeOfClass;
        }
        delete monitor;
    }
};

struct Classes {
    int numberofClasses;
    Class* monitor;
    Classes() {
        numberofClasses = 0;
        monitor = new Class();
    }
    void addNewClass(Class* newClass) {
        ++numberofClasses;
        newClass->nextClass = monitor->nextClass;
        monitor->nextClass = newClass;
    }
    void deallocate() {
        while (numberofClasses) {
            Class* h = monitor->nextClass;
            monitor->nextClass = monitor->nextClass->nextClass;
            delete h;
            --numberofClasses;
        }
        delete monitor;
    }
};

struct score{
    Student* studentInform;
    float totalMark;
    float finalMark;
    float midtermMark;
    float otherMark;
    score* nextScore;
    score() {
        studentInform = NULL;
        totalMark = 0;
        finalMark = 0;
        midtermMark = 0;
        otherMark = 0;
        nextScore = NULL;
    }
    score(Student* studentInform_x, float totalMark_x, float finalMark_x, float midtermMark_x, float otherMark_x) {
        studentInform = studentInform_x;
        totalMark = totalMark_x;
        finalMark = finalMark_x;
        midtermMark = midtermMark_x;
        otherMark = otherMark_x;
        nextScore = NULL;
    }
};

struct scoreBoard {
    int sizeofBoard;
    score* monitor;
    scoreBoard() {
        sizeofBoard = 0;
        monitor = new score();
    }
    void addNewScore(score* newScore) {
        ++sizeofBoard;
        score* cur = monitor;
        while (cur->nextScore != NULL) cur = cur->nextScore;
        newScore->nextScore = NULL;
        cur->nextScore = newScore;
    }
    score* getScoreOfStudent(long long studentID) {
        score* cur = monitor;
        while (cur->nextScore != NULL) {
            if (cur->nextScore->studentInform->studentID == studentID) {
                return cur->nextScore;
            }
        }
        return NULL;
    }
    void deleteScore(int index) {
        int k = 0;
        score* cur = monitor;
        for (int i = 0; i < index; i++)
            cur = cur->nextScore;
        score* score_to_delete = cur->nextScore;
        cur->nextScore = score_to_delete->nextScore;
        delete score_to_delete;
    }
    void deallocate() {
        while (sizeofBoard) {
            score* h = monitor->nextScore;
            monitor->nextScore=monitor->nextScore->nextScore;
            delete h;
            --sizeofBoard;
        }
    }
};

struct Course {
    string courseID;
    string courseName;
    string teacherName;
    int numberofCredit;
    int maxStudent;
    int day[2];
    int session[2];
    int schoolyear;
    int semester;
    Course* nextCourse;
    scoreBoard courseScoreBoard;
    Class courseClass;
    Course() {
        courseID = "";
        courseName = "";
        teacherName = "";
        numberofCredit = 0;
        maxStudent = 50;
        day[0] = day[1] = 0;
        session[0] = session[1] = 0;
        nextCourse = NULL;
        courseScoreBoard = scoreBoard();
        courseClass = Class();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], int schoolyear_x, int semester_x) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        schoolyear = schoolyear_x;
        semester = semester_x;
        nextCourse = NULL;
        courseClass = Class();
        courseScoreBoard = scoreBoard();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], int schoolyear_x, int semester_x, Class courseClass_x) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        schoolyear = schoolyear_x;
        semester = semester_x;
        nextCourse= NULL;
        courseClass = courseClass_x;
        courseScoreBoard = scoreBoard();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], int schoolyear_x, int semester_x, Class courseClass_x, scoreBoard courseScoreBoard_x) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        schoolyear = schoolyear_x;
        semester = semester_x;
        nextCourse = NULL;
        courseClass = courseClass_x;
        courseScoreBoard = courseScoreBoard_x;
    }
    void addStudentToCourse(Student* newStudent) {
        courseClass.addNewStudent(newStudent);
    }
};

struct Courses{
    int sizeofCourses;
    Course* monitor;
    Courses() {
        sizeofCourses = 0;
        monitor = new Course();
    }
    void addNewCourse(Course* newCourse) {
        ++sizeofCourses;
        newCourse->nextCourse = monitor->nextCourse;
        monitor->nextCourse = newCourse;
    }
    void addNewCourse(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], int schoolyear_x, int semester_x) {
        Course* newCourse = new Course(courseID_x, courseName_x, teacherName_x, numberofCredit_x, maxStudent_x, day_x, session_x, schoolyear_x, semester_x);
        ++sizeofCourses;
        newCourse->nextCourse = monitor->nextCourse;
        monitor->nextCourse = newCourse;
    }
    Course* getCourse(string courseID) {
        Course* cur = monitor;
        while (cur->nextCourse != NULL) {
            if (cur->nextCourse->courseID == courseID) {
                return cur->nextCourse;
            }
        }
        return NULL;
    }
    void deleteCourse(string courseID_x) {
        --sizeofCourses;
        Course* cur = monitor;
        while (cur->nextCourse != NULL) {
            if (cur->nextCourse->courseID == courseID_x) {
                Course* t = cur->nextCourse;
                cur->nextCourse = cur->nextCourse->nextCourse;
                delete t;
                break;
            }
        }
    }
    void deallocate() {
        while (sizeofCourses) {
            Course* h = monitor->nextCourse;
            monitor->nextCourse = monitor->nextCourse->nextCourse;
            delete h;
            sizeofCourses--;
        }
        delete monitor;
    }
};

struct School {
    int schoolyear;
    Classes allClasses;
    Courses allCourses;
    School() {
        allClasses = Classes();
        allCourses = Courses();
    }
    Student* getStudent(int studentID_x) {
        Class* curClass = allClasses.monitor;
        while (curClass->nextClass) {
            curClass = curClass->nextClass;
            Student* student_found = curClass->getStudentFromClass(studentID_x);
            if (student_found) return student_found;
        }
        return NULL;
    }
    Course* getCourse(string courseID_x) {
        Course* curCourse = allCourses.monitor;
        while (curCourse->nextCourse) {
            curCourse = curCourse->nextCourse;
            if (curCourse->courseID == courseID_x) return curCourse;
        }
        return NULL;
    }
};

#endif /* structure_h */

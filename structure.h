//
//  structure.h
//  structure
//
//  Created by Hoang The Anh.
//

#ifndef structure_h
#define structure_h

#pragma once

#include <string.h>

struct Student{};
struct Class{};
struct Course{};
struct CourseInfo{};
struct Courses{};
struct score{};
struct scoreBoard{};

struct Student {
    int No;
    long long studentID;
    string firstName;
    string lastName;
    bool gender;
    string dateOfBirth;
    long long socialID;
    Student* inClassMonitor;
    Courses myCourses;
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
        myCourse = Courses();
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
        myCourse = Courses();
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
        myCourse = Courses();
    }
    Student(int No_x, long long studentID_x, string firstName_x, string lastName_x, bool gender_x, string dateOfBirth_x, long long socialID_x, Student* inClassMonitor_x, Courses myCourses_x) {
        No = No_x;
        studentID = studentID_x;
        firstName = firstName_x;
        lastName = lastName_x;
        gender = gender_x;
        dateOfBirth = dateOfBirth_x;
        socialID = socialID_x;
        nextStudent = NULL;
        inClassMonitor = inClassMonitor_x;
        myCourse = myCourses_x;
    }
}

struct Class {
    int sizeOfClass;
    Student* monitor;
    Class() {
        sizeOfClass = 0;
        monitor = new Student();
    }
    void addNewStudent(Student* newStudent) {
        ++sizeOfClass;
        newStudent.inClassMonitor = monitor;
        newStudent->next = monitor->next;
        monitor->next = newStudent;
    }
    void addStudentToCourse(Student* newStudent) {
        ++sizeOfClass;
        newStudent->next = monitor->next;
        monitor->next = newStudent;
    }
    Student* getStudent(int studentID) {
        Student* cur = monitor;
        while (cur->next != NULL) {
            if (cur->next->studentID == studentID) {
                return cur->next;
            }
        }
        return NULL;
    }
    void deallocate() {
        while (sizeOfClass) {
            Student* h = monitor->next;
            monitor->next = monitor->next->next;
            delete h;
        }
        delete monitor;
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
    Course* courseNext;
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
        courseNext = NULL;
        courseScoreBoard = scoreBoard();
        courseClass = Class();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[]) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        courseNext = NULL;
        courseClass = Class();
        courseScoreBoard = scoreBoard();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], Class courseClass_x) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        courseNext = NULL;
        courseClass = courseClass_x;
        courseScoreBoard = scoreBoard();
    }
    Course(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[], Class courseClass_x, scoreBoard courseScoreBoard_x) {
        courseID = courseID_x;
        courseName = courseName_x;
        teacherName = teacherName_x;
        numberofCredit = numberofCredit_x;
        maxStudent = maxStudent_x;
        day[0] = day_x[0];
        day[1] = day_x[1];
        session[0] = session_x[0];
        session[1] = session_x[1];
        courseNext = NULL;
        courseClass = courseClass_x;
        courseScoreBoard = courseScoreBoard_x;
    }
    void addStudentToCourse(Student* newStudent) {
        courseClass.addStudentToCourse(newStudent);
        (newStudent->myCourses).addNewCourse(courseID, courseName, teacherName, numberofCredit, maxStudent, day, session);
    }
}

struct Courses {
    int sizeofCourses;
    Course* monitor;
    Courses() {
        sizeofCourses = 0;
        monitor = new Course();
    }
    void addNewCourse(Course* newCourse) {
        ++sizeofCourses;
        newCourse->next = monitor->next;
        monitor->next = newCourse;
    }
    void addNewCourse(string courseID_x, string courseName_x, string teacherName_x, int numberofCredit_x, int maxStudent_x, int day_x[], int session_x[]) {
        Course* newCourse = Course(courseID_x, courseName_x, teacherName_x, numberofCredit_x, maxStudent_x, day_x, session_x);
        ++sizeofCourses;
        newCourse->next = monitor->next;
        monitor->next = newCourse;
    }
    Course* getCourse(string courseID) {
        Course* cur = monitor;
        while (cur->next != NULL) {
            if (cur->next->courseID == courseID) {
                return cur->next;
            }
        }
        return NULL;
    }
    void deleteCourse(string courseID_x) {
        --sizeofCourses;
        Course* cur = monitor;
        while (cur->next != NULL) {
            if (cur->next->courseID == courseID_x) {
                Course* t = cur->next;
                cur->next=cur->next->next;
                delete t;
                break;
            }
        }
    }
    void deallocate() {
        while (sizeOfCourses) {
            Course* h = monitor->next;
            monitor->next = monitor->next->next;
            delete h;
        }
        delete monitor;
    }
}

struct score{
    Student* studentInform;
    float totalMark;
    float finalMark;
    float midtermMark;
    float otherMark;
    score* nextScore;
    score(Student* studentInform_x, float totalMark_x, float finalMark_x, float midtermMark_x, float otherMark_x) {
        studentInform = studentInform_x;
        totalMark = totalMark_x;
        finalMark = finalMark_x;
        midtermMark = midtermMark_x;
        otherMark = otherMark_x;
        nextScore = NULL;
    }
};

struct scoreBoard() {
    int sizeofBoard;
    score* monitor;
    scoreBoard() {
        sizeofBoard = 0;
        monitor = new score();
    }
    void addNewScore(score* newScore) {
        newScore->nextScore = monitor->nextScore;
        monitor->nextScore = newScore;
    }
    score* getScoreOfStudent(int studentID) {
        score* cur = monitor;
        while (cur->next != NULL) {
            if (cur->next->studentInform->studentID == studentID) {
                return cur->next;
            }
        }
        return NULL;
    }
}

#endif /* structure_h */

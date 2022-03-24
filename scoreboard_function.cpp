//
//  scoreboard_function.cpp
//  structure
//
//  Created by Hoang The Anh on 19/03/2022.
//  Edited by Hoang The Anh on 21/03/2022.
//  Edited by Hoang The Anh on 22/03/2022.
// Edited by Hoang The Anh on 23/03/2022.

#include "scoreboard_function.hpp"
#include "structure.h"
#include "general_function.hpp"
#include <fstream>
#include <sstream>

void exportStudentInCourse(Course* someRandomCourse) {
    ofstream fout;
    string filename = "Student_" + someRandomCourse->courseID + "_" + to_string(getCurrentSchoolYear()) + "_" + /*to_string(getSemester()) +*/ ".csv";

    fout.open(filename);
    fout << "No,First Name,Last Name,\n";
    Student* cur = someRandomCourse->courseClass.monitor;
    int stt = 0;
    while (cur->nextStudent != NULL) {
        cur = cur->nextStudent;
        ++stt;
        string desc = to_string(stt) + "," + cur->firstName + "," + cur->lastName + ",\n";
        fout << desc;
    }
    fout.close();
}

void importScore(Course* &course, string filename) {
    ifstream fin;
    fin.open(filename);
    string s;
    getline(fin, s);
    while (getline(fin, s)) {
        stringstream sst(s);
        int studentID;  char dumm;
        sst >> studentID >> dumm >> studentID >> dumm;
        score* newScore = new score();
        newScore->studentInform->studentID = studentID;
        while ((sst >> studentID).fail() && !sst.eof()) {
            string dummy;
            sst >> dummy;
        }
        fin >> dumm >> newScore->totalMark >> dumm >> newScore->finalMark >> dumm >> newScore->midtermMark >> dumm >> newScore->otherMark;
        course->courseScoreBoard.addNewScore(newScore);
    }
    fin.close();
}

void seeScoreOfCourse(Course* course) {
    scoreBoard thisCourseScoreBoard = course->courseScoreBoard;
    score* cur = thisCourseScoreBoard.monitor;
    int index = 1;
    while (cur->nextScore != NULL) {
        cur = cur->nextScore;
        //std::cout << index << " | " << cur->studentInform->lastName << " | " << cur->totalMark << " | " << cur->finalMark << " | " << cur->midtermMark << " | " << cur->otherMark << "\n"; -- Waiting for UI/UX
        index++;
    }
}

void updateStudentResult(Course*& course, int studentID, float totalMark_x, float finalMark_x, float midtermMark_x, float otherMark_x) {
    score* studentFound = course->courseScoreBoard.getScoreOfStudent(studentID);
    if (totalMark_x != -1) studentFound->totalMark = totalMark_x;
    if (finalMark_x != -1) studentFound->finalMark = finalMark_x;
    if (midtermMark_x != -1) studentFound->midtermMark = midtermMark_x;
    if (otherMark_x != -1) studentFound->otherMark = otherMark_x;
}

void viewClassScore(Class someRandomClass, Courses allCourses) {
    int thisSchoolYear = getCurrentSchoolYear();
    int thisSemester = getSemester();
    Student* cur = someRandomClass.monitor;
    int index1 = 1;
    while (cur->nextStudent != NULL) {
        cur = cur->nextStudent;
        enrolledCourses thisEnrolledCourses = cur->myCourses;
        enrolledCourse* thisEnrolledCourse = thisEnrolledCourses.monitor;
        //cout << index1 << ". " << cur->studentID << " - " << cur->firstName << " " << cur->lastName << "\n";
        index1++;
        int index2 = 0;
        double GPA1 = 0, GPA2 = 0;
        while (thisEnrolledCourse->nextEnrolledCourse != NULL) {
            thisEnrolledCourse = thisEnrolledCourse->nextEnrolledCourse;
            Course* thisCourse = allCourses.getCourse((*(thisEnrolledCourse->courseID)));
            score* thisScore = thisCourse->courseScoreBoard.getScoreOfStudent(cur->studentID);
            if (thisCourse->schoolyear == thisSchoolYear && thisCourse->semester == thisSemester) {
                index2++;
                //std::cout << index2 << " | " << thisCourse->courseName << " | " << thisScore->otherMark << " | " << thisScore->midtermMark << " | " << thisScore->finalMark << " | " << thisScore->totalMark << "\n";
                GPA1 += thisScore->totalMark;
            }
            GPA2 += thisScore->totalMark;
        }
        //cout << "GPA this semester: " << GPA1 / index2;
        //cout << "CGPA: " << GPA2 / thisEnrolledCourses.sizeofList;
    }
}

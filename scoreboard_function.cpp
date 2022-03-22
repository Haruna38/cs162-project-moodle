//
//  scoreboard_function.cpp
//  structure
//
//  Created by Hoang The Anh on 19/03/2022.
//  Edited by Hoang The Anh on 21/03/2022.
//  Edited by Hoang The Anh on 22/03/2022.

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

//
//  scoreboard_function.cpp
//  structure
//
//  Created by Hoang The Anh on 19/03/2022.
//

#include "scoreboard_function.hpp"
#include "structure.h"
#include <fstream>

void exportStudentInCourse(Course* someRandomCourse) {
    ofstream fout;
    string filename = "Student_" + someRandomCourse->courseID + "_" + to_string(getCurrentSchoolYear()) + "_" + to_string(getSemester()) + ".csv";

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

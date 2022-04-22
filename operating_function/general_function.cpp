//
//  general_function.cpp
//  structure
//
//  Created by Hoang The Anh on 21/03/2022.
//

#include "operating_function/general_function.hpp"
#include <fstream>

int getCurrentSchoolYear() {
    std::ifstream fin;
    fin.open("schoolyear.txt");
    int schoolyear_result = 0;
    while (!fin.eof()) {
        fin >> schoolyear_result;
    }
    fin.close();
    return schoolyear_result;
}

int getSemester() {
    std::ifstream fin;
    fin.open("currentSemester.txt");
    int semester_result = 0;
    fin >> semester_result;
    fin.close();
    return semester_result;
}

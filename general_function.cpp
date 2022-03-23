//
//  general_function.cpp
//  structure
//
//  Created by Hoang The Anh on 21/03/2022.
//

#include "general_function.hpp"
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

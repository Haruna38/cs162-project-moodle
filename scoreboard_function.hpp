//
//  scoreboard_function.hpp
//  structure
//
//  Created by Hoang The Anh on 19/03/2022.
//  Edited by Hoang The Anh on 21/03/2022.

#ifndef scoreboard_function_hpp
#define scoreboard_function_hpp

#include <stdio.h>
#include "structure.h"

void exportStudentInCourse(Course* someRandomCourse);
void importScore(Course*& course, string filename);

#endif /* scoreboard_function_hpp */

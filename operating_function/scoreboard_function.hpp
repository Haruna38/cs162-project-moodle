//
//  scoreboard_function.hpp
//  structure
//
//  Created by Hoang The Anh on 19/03/2022.
//  Edited by Hoang The Anh on 21/03/2022.
//  Edited by Hoang The Anh on 22/03/2022.
//  Edited by Hoang The Anh on 23/03/2022.
//  Edited by Hoang The Anh on 02/04/2022.

#ifndef scoreboard_function_hpp
#define scoreboard_function_hpp

#include <stdio.h>
#include "operating_function/structure.h"

void exportStudentInCourse(Course* someRandomCourse);
void exportScore(Course* randomCourse);
void importScore(Course*& course, string filename);
void seeScoreOfCourse(Course* course);
void updateStudentResult(Course*& course, int studentID, float totalMark_x, float finalMark_x, float midtermMark_x, float otherMark_x);
void viewClassScore(Class someRandomClass, Courses allCourses);
void seeStudentScore(Student* student, Courses allCourses);

#endif /* scoreboard_function_hpp */

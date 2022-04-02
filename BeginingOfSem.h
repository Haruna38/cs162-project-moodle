#pragma once
#include <iostream>
#include <fstream>
//#include <Windows.h>
using namespace std;

void createSemester();
void createRegistration();
void addCourse(School HCMUS);
void viewCourses(School HCMUS);
void updateCourseInfo(Course* course, const int& x);
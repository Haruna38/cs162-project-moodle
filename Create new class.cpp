//Created by DInh Quang Hieu 
///Started 17/03/2022
//Edited 22/03/2022
//Edited 23/03/2022
//Edited 25/03/2022
//Add student to list class new 
#include <iostream>
#include<string.h>
#include "general_function.h"
#include<string>
#include<fstream>
#include"struct.h"
using namespace std;
void createClassList(School HCMUS) {
	int schoolyear_x = getCurrentSchoolYear(); 
	Class* newClass = new Class();
	cin >> newClass->classID;
	newClass->schoolyear = schoolyear_x;
		bool status = true;
		while (status) {
			Student* newStudent = new Student();
			cin >> newStudent->No >> newStudent->studentID >> newStudent->dateOfBirth >> newStudent->socialID >> newStudent->firstName >>newStudent->lastName >>newStudent->gender;
			newClass->addNewStudent(newStudent);
			if (/*xuly*/) status = false;
		}
		HCMUS.allClasses.addNewClass(newClass);
	}

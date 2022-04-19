
#include "BeginingOfSem.h"
#include "structure.h"

void createSemester() {
	int schoolyear;
	cin >> schoolyear; //choose school year (2021 - 2025, 2020 - 2024, 2019 - 2023...)
	int sem;
	cin >> sem; //choose semester (1 or 2 or 3)
	string start, end; 
	cin >> start; //choose start date of the new semester 
	cin >> end; //choose end date of the new semester
	ofstream fout;
	fout.open("currentSemester.txt");
	fout << schoolyear << endl; //save the current school year as the default for the actions below
	fout << sem << endl; //save the current semester as the default for the actions below
	fout << start << endl; //save the start date as the default for the actions below
	fout << end << endl; //save the end date  as the default for the actions below
	fout.close();

	fout.open("allSemester.txt", ios::app);
	fout << schoolyear << endl; //save the school year to the list of all semester
	fout << sem << endl; //save the semester to the list of all semester
	fout << start << endl; //save the start date of new semester
	fout << end << endl; //save the end date of new semester
	fout.close();
}

void createRegistration() {
	string start, end;
	cin >> start; //choose start date for the course registration
	cin >> end; //choose end date for the course registration
	int h, m, s;
	cin >> h; //choose start hour for the course registration
	cin >> m; //choose start minute for the course registration
	cin >> s; //choose start second for the course registration
	ofstream fout;
	fout.open("courseRegistration.txt"); //save all the information of the course registration session into a file
	fout << h * 3600 + m * 60 + s << endl; //save the start time for the course registration into a file
	fout << start << endl; //save the start date for the course registration into a file
	cin >> h; //choose end hour for the course registration into a file
	cin >> m; //choose end minute for the course registration into a file
	cin >> s; //choose end second for the course registration into a file
	fout << h * 3600 + m * 60 + s << endl; //save end hour for the course registration into a file
	fout << end << endl; //save end date for the course registration into a file
	fout.close();
}

void addCourse(School HCMUS) {
	Course* newCourse = new Course();
	cin >> newCourse->courseID;
	cin >> newCourse->courseName;
	cin >> newCourse->teacherName;
	cin >> newCourse->numberofCredit;
	cin >> newCourse->maxStudent;
	cin >> newCourse->day[0];
	cin >> newCourse->day[1];
	cin >> newCourse->session[0];
	cin >> newCourse->session[1];
	cin >> newCourse->schoolyear;
	cin >> newCourse->semester;
	HCMUS.allCourses.addNewCourse(newCourse);
}

void viewCourses(School HCMUS) {
	HCMUS.allCourses.monitor = HCMUS.allCourses.monitor->nextCourse; 
	while (HCMUS.allCourses.monitor) {
		cout << HCMUS.allCourses.monitor->courseID << endl;
		cout << HCMUS.allCourses.monitor->courseName << endl;
		cout << HCMUS.allCourses.monitor->teacherName << endl << endl;
		HCMUS.allCourses.monitor = HCMUS.allCourses.monitor->nextCourse;
	}
}

void updateCourseInfo(School HCMUS, string courseID, const int& x) {
	Course* course = HCMUS.allCourses.getCourse(courseID);
	switch (x) {
	case 1: {
		cin >> course->courseID;
		break;
	}
	case 2: {
		cin >> course->courseName;
		break;
	}
	case 3: {
		cin >> course->teacherName;
		break;
	}
	case 4: {
		cin >> course->numberofCredit;
		break;
	}
	case 5: {
		cin >> course->maxStudent;
		break;
	}
	case 6: {
		cin >> course->day[0];
		cin >> course->day[1];
		break;
	}
	case 7: {
		cin >> course->session[0];
		cin >> course->session[1];
		break;
	}
	case 8: {
		cin >> course->schoolyear;
		break;
	}
	case 9: {
		cin >> course->semester;
		break;
	}
	default: {
		return;
	}
	}
}

void deleteACourse(School HCMUS, string CourseID) {
	HCMUS.allCourses.deleteCourse(CourseID);
}

#include "BeginingOfSem.h"
#include "structure.h"

void createSemester(int schoolyear, int sem, string start, string end) {
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

void createRegistration(string start, string end, int h, int m, int s) {
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
	cin >> newCourse->courseID; //input new course ID
	cin >> newCourse->courseName; //input new course Name
	cin >> newCourse->teacherName; //input new course teacher name
	cin >> newCourse->numberofCredit; //input new course number of credits
	cin >> newCourse->maxStudent; //input new course max student
	cin >> newCourse->day[0]; //input new course first day
	cin >> newCourse->day[1]; //input new course second day
	cin >> newCourse->session[0]; //input new course first session
	cin >> newCourse->session[1]; //input new course second session
	cin >> newCourse->schoolyear; //input new course schoolyear
	cin >> newCourse->semester; //input new course semester
	HCMUS.allCourses.addNewCourse(newCourse); //add new course to a list of all course
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
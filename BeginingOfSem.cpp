
#include "BeginingOfSem.h"
#include "structure.h"
//void gotoXY(int x, int y)
//{
//	static HANDLE h = NULL;
//	if (!h)
//		h = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD c = { x, y };
//	SetConsoleCursorPosition(h, c);
//}

void createSemester() {
	/*cout << "Choose a school year: " << endl;*/
	ifstream fin;
	ofstream fout;
	//fin.open("schoolyear.txt");
	//int n;
	//fin >> n;
	//for (int i = 0; i < n; ++i) {
	//	int x; fin >> x;
	//	/*cout << i + 1 << ". " << x << endl;*/
	//}
	//fin.close();
	int schoolyear;
	cin >> schoolyear; //choose school year (2021, 2022, 2023...)
	int sem;
	cin >> sem; //choose semester (1 or 2 or 3)
	string start, end;
	cin >> start;
	cin >> end;
	fout.open("currentSemester.txt");
	fout << schoolyear << endl;
	fout << sem << endl;
	fout << start << endl;
	fout << end << endl;
	fout.close();

	fout.open("allSemester.txt", ios::app);
	fout << schoolyear << endl;
	fout << sem << endl;
	fout << start << endl;
	fout << end << endl;
	fout.close();
}

void createRegistration() {
	string start, end;
	cin >> start;
	cin >> end;
	int h, m, s;
	cin >> h;
	cin >> m;
	cin >> s;
	ofstream fout;
	fout.open("courseRegistration.txt");
	fout << h * 3600 + m * 60 + s << endl;
	fout << start << endl;
	cin >> h;
	cin >> m;
	cin >> s;
	fout << h * 3600 + m * 60 + s << endl;
	fout << end << endl;
	fout.close();
}

void addCourse(School HCMUS) {
	Course* newCourse = new Course();
	cin >> newCourse->...;
	HCMUS.allCourses.addNewCourse(newCourse);
}

void viewCourses(School HCMUS) {
	/*cout << "There are " << HCMUS.allCourses.sizeofCourses << " courses in total." << endl << endl;*/
	HCMUS.allCourses.monitor = HCMUS.allCourses.monitor->nextCourse; 
	while (HCMUS.allCourses.monitor) {
		cout << HCMUS.allCourses.monitor->courseID << endl;
		cout << HCMUS.allCourses.monitor->courseName << endl;
		cout << HCMUS.allCourses.monitor->teacherName << endl << endl;
		HCMUS.allCourses.monitor = HCMUS.allCourses.monitor->nextCourse;
	}
}

void updateCourseInfo(Course* course, const int& x) {
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

void deleteACourse(Courses courses, string CourseID) {
	courses.deleteCourse(CourseID);
}
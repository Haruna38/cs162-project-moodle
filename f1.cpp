
#include "f1.h"
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
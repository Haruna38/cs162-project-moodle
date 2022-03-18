
#include "f1.h"

void gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void createSemester() {
	cout << "Choose a school year: " << endl;
	ifstream fin;
	fin.open("schoolyear.txt");
	int n;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		int x; fin >> x;
		cout << i + 1 << ". " << x << endl;
	}
	fin.close();
	/*gotoXY();*/
	cin >> 
}
#include <iostream>
#include<fstream> 
using namespace std;
void inputSchoolYear( ofstream& fout) {
	int x;
	cout << "Enter your current school year : ";
	cin >> x;
	fout.open("schoolyear.txt",ios::app);
	fout << x << endl;
	fout.close();
}

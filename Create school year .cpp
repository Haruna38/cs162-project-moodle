#include <iostream>
#include<fstream> 
#include"Function.h"
using namespace std;
void inputSchoolYear( ofstream& fout) {
	int x;
	cout << "Enter your current school year : ";
	cin >> x;
	fout.open("schoolyear.txt");
	fout << x << endl;
	fout.close();
}
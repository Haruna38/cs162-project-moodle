#include<iostream> 
#include<fstream> 
#include<string.h>
#include<cstring>
#include<string>
#include"Function.h"
using namespace std;
void createNewClass() {
	string newclass="";
	char ans[10];
	bool tmp = true;
	ofstream fout;
	fout.open("Class.txt");
	while (tmp!= false) {
		cout << "Input your class's name : ";
		cin.get();
		getline(cin,newclass , '\n');
		fout << newclass;
		cout << "You want to create a new class again ?" << endl;
		cout << "If yes input Y , no input N : ";
		/*cin.get();*/
		//cin.ignore(100, '\n');
		cin.getline(ans, 10, '\n');
		/*cout << ans[0];
		cout << strlen(ans);*/
		if (ans == "Y") tmp = true;
		else if (!strcmp(ans,"N")) {
			tmp = false;
		}
	}
	fout.close();
}
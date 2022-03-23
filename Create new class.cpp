//Created by DInh Quang Hieu 
///Started 17/03/2022
//Edited 22/03/2022
//Edited 23/03/2022
#include <iostream>
#include"class.h"
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
void createClassList(Class*& pClass , int numsClass) {
	ifstream fin;
	fin.open("Class.txt");
    pClass = new Class;
    Class *pCur = pClass;
    for (int i = 0; i < numsClass && pCur != nullptr; i++) {
	fin >> pCur->name;
        pCur = pCur->next;
    }
}

void createNewClass(Class *&pClass, int &numsClass) {
	pClass->name = "";
	char ans[10];
	bool tmp = true;
	ofstream fout;
	numsClass = 1;
	fout.open("Class.txt");
	while (tmp != false) {
		cout << "Input your class's name : ";
		cin.get();
		getline(cin, pClass->name, '\n');
		fout << pClass->name;
		cout << "You want to create a new class again ?" << endl;
		cout << "If yes input Y , no input N : ";
		cin.getline(ans, 10, '\n');
		if (ans == "Y") {
			tmp = true;
			numsClass++;
		}
		else if (!strcmp(ans, "N")) {
			tmp = false;
		}
	}
	fout.close();
}


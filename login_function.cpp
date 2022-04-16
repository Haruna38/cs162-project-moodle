#include<iostream>
#include<fstream>   
#include<string>

#include "cs162-project-moodle-main/login_function.h"

using namespace std;
string usn;
int tm;
void valid(string str)  
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        return;
    }
    else
    {
        tm++;
        if (tm == 3)
        {
            return;
        }
        cin >> usn;
        valid(usn);
    }
}



bool login(string username, string password) {
    ifstream fin;
    string fileuser = username + ".txt";
    fin.open(fileuser);
    if (fin.fail()) {
        fin.close();
        return false;
    }
    string password_saved; fin >> password_saved;
    fin.close();
    if (password == password_saved) return true;
    return false;
}

void showProfile(string usn , string name , string psd) {
    string fname = usn + ".txt";
    ofstream fileo;
    fileo.open(fname.c_str());
    fileo << usn << endl << name << endl << psd << endl;
    cin.ignore();
    //getline(cin, bio);
    //fileo << bio << endl;
    fileo.close();
    system("pause");
    system("cls");
}
void changePas(string usn , string name , string psd) {
    string fname = usn + ".txt";
    ifstream filei;
    getline(filei, usn);
    getline(filei, name);

    ofstream fout;
    fout.open(fname.c_str());
    fout << usn << endl << name << endl;
    getline(cin, psd);
    fout << psd << endl;
    fout.close();

 }
void logOut() {
    system("cls") ;
    return  ;
}

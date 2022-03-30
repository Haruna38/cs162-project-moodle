#include<iostream>
#include<fstream>   
#include<string>
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
            cout << "\nThis username already exists\nPlease try Again.";
            return;
        }
        cin >> usn;
        valid(usn);
    }
}
int main()
{
    int choice, i, exit = 0;
    string ans, psd, name, fname, bio, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    while (exit == 0)
    {
        cin >> choice;
        if (choice == 1)
        {
            cin >> usn;
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
                filei.close();
                system("pause");
                system("cls");
                continue;
            }
            getline(filei, usern);
            getline(filei, line);
            getline(filei, pw);
            if (usn == usern && psd == pw)
            {
                getline(filei, line);
                filei.close();
                system("pause");
                system("cls");
            }
            else {
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cin.ignore();
            getline(cin, name);
            cin >> usn;
            tm = 0;
            valid(usn);
            if (tm >= 3)
            {
                continue;
            }
            cin >> psd;
            //if(xu li) {} 
            showProfile(usn, name, psd);
        }
        else
        {
            exit = 1;
        }
    }
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


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
            return;
        }
        cin >> usn;
        valid(usn);
    }
}
void login()
{
     //cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
    int choice, i, exit = 0;
    string ans, psd, name, fname/*, bio*/, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    while (exit == 0)
    {
        cin >> choice;
        if (choice == 1)
        {
            //cout << "Enter your username:";
            cin >> usn;
            // cout << "\nEnter your password:";
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
               // cout << "\nYou are not registered, please register before logging in.\n";
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
               // cout << "\nYou are successfully logged in:)
                getline(filei, line);
                filei.close();
                system("pause");
                system("cls");
            }
            else {
                //cout << "\nWrong username or password!\nPlease try Again.\n";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            //  cout << "\nEnter your name:";
            cin.ignore();
            getline(cin, name);
            // cout << "\nCreate a username:";
            cin >> usn;
            tm = 0;
            valid(usn);
            if (tm >= 3)
            {
                continue;
            }
                   //    cout << "\nCreate a password:";
            cin >> psd;
            //if(xu li) {} 
            showProfile(usn, name, psd);
        }
        else if(choice == 3){
            //change password and clear screen and return login function 
          changePas(usn,name,psd) ;
          system("cls") ;
          login();
          } 
      else if(choice == 4 ) {
          //Log out 
          logOut() ;
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
void logOut() {
    system("cls") ;
    return  ;
}

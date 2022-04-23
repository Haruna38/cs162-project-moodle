#ifndef UTILS
#define UTILS

#include <string>
#include <fstream>

#include "structure.h"

using namespace std;

class Manager {
private:
    string path = "../../../../untitled/";
public:
    string getUser(string ID);
};

string Manager::getUser (string ID) {
    ifstream fin(path + "info.txt");
    if (fin.fail()) return "Failed to fetch user info";
    int amount;
    string data, test = "";
    while (!fin.eof()) {
        string id, fname, lname, isStaff, gender, dob, year, sid;
        getline(fin, id);
        getline(fin, fname);
        getline(fin, lname);
        getline(fin, isStaff);
        getline(fin, gender);
        getline(fin, dob);
        getline(fin, year);
        getline(fin, sid);
        test += id;
        if (id == ID) return "ID: " + id + "\nName: " + fname + " " + lname + "\nRole: " + (isStaff == "1" ? "Staff": "Student") + "\nGender: " + gender + "\nDate of birth: " + dob + "\nSchool year: " + year + "\nSocial ID: " + sid;
        getline(fin, data);
    }
    fin.close();
    return "Unable to find user in the database!";
}
#endif
